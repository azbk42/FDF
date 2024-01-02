/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2023/12/31 19:38:27 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_tab(char *av, int **tab)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	x = count_x(av);
	y = count_y(av);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%d ", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void tab_to_pixel(t_data *data, int **tab, int y, int x)
{
	int i;
	int j;
	int width;
	int height;

	height = 50;
	width = 50;
	i = 0;
	if (!tab)
		return ;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			my_mlx_pixel_put(data, width, height, 0xFFFFFFFF);
			j ++;
			width += 30;
		}
		width = 50;
		height += 30;
		i ++;
	}
}

int init_mlx(int **tab, int y, int x)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MALLOC_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, HEIGHT, WIDTH, "FDF");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		return (free(data.mlx_ptr), MALLOC_ERROR);
	}
	data.img_ptr = mlx_new_image(data.mlx_ptr, HEIGHT, WIDTH);
	if (!data.img_ptr)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		return (free(data.mlx_ptr), MALLOC_ERROR);
	}
	data.path = mlx_get_data_addr(data.img_ptr, &data.bits_pixel, &data.size_line, &data.endian);
	tab_to_pixel(&data, tab, y, x);
	
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_key_hook(data.win_ptr, handle_esc, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	int	**tab;
	int	k;
	int	y;
	int x;
	
	ac = 5;
	k = -1;
	
	y = count_y(av[1]);
	x = count_x(av[1]);
	tab = init_map(av[1]);
	print_tab(av[1], tab);
	while (++k < y)
		free(tab[k]);
	free(tab);

	init_mlx(tab, y, x);

}
