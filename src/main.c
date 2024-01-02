/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/02 19:47:52 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	tab_to_pixel(t_data *data, int **tab, int y, int x)
{
	int		i;
	int		j;
	t_pixel	p;
	t_iso	iso;

	iso.tableWidth = x * len_line;
	iso.tableHeight = y * len_line;
	iso.angle = M_PI / 4; // 45 degrees radian
	iso.height = 2;       // valeur a augmenter pour voir la hauteur
	p.beginX = (WIDTH - iso.tableWidth) / 2;
	p.beginY = (HEIGHT - iso.tableHeight) / 2;
	if (!tab)
		return ;
	for (i = 0; i < y; i++)
	{
		for (j = 0; j < x; j++)
		{
			// Calculate the isometric position for the current point
			iso.isoX = (j - i) * cos(iso.angle) * len_line + p.beginX;
			iso.isoY = (j + i) * sin(iso.angle) * len_line - tab[i][j]
				* iso.height + p.beginY;
			if (j < x - 1)
			{
				iso.nextIsoX = ((j + 1) - i) * cos(iso.angle) * len_line
					+ p.beginX;
				iso.nextIsoY = ((j + 1) + i) * sin(iso.angle) * len_line
					- tab[i][j + 1] * iso.height + p.beginY;
				draw_line(data, iso.isoX, iso.isoY, iso.nextIsoX, iso.nextIsoY);
			}
			if (i < y - 1)
			{
				iso.nextIsoX = (j - (i + 1)) * cos(iso.angle) * len_line
					+ p.beginX;
				iso.nextIsoY = (j + (i + 1)) * sin(iso.angle) * len_line - tab[i
					+ 1][j] * iso.height + p.beginY;
				draw_line(data, iso.isoX, iso.isoY, iso.nextIsoX, iso.nextIsoY);
			}
		}
	}
}

int	init_mlx(int **tab, int y, int x)
{
	t_data	data;

	data.mlx_ptr = mlx_init();
	if (!data.mlx_ptr)
		return (MALLOC_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "FDF");
	if (!data.win_ptr)
	{
		mlx_destroy_display(data.mlx_ptr);
		return (free(data.mlx_ptr), MALLOC_ERROR);
	}
	data.img_ptr = mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT);
	if (!data.img_ptr)
	{
		mlx_destroy_window(data.mlx_ptr, data.win_ptr);
		return (free(data.mlx_ptr), MALLOC_ERROR);
	}
	data.path = mlx_get_data_addr(data.img_ptr, &data.bits_pixel,
			&data.size_line, &data.endian);
	tab_to_pixel(&data, tab, y, x);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_key_hook(data.win_ptr, handle_esc, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	free_maps(tab, y);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	int	**tab;
	int	k;
	int	y;
	int	x;

	ac = 5;
	k = -1;
	y = count_y(av[1]);
	x = count_x(av[1]);
	tab = init_map(av[1]);
	print_tab(av[1], tab);
	init_mlx(tab, y, x);
}
