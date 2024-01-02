/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/02 20:54:28 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calculate_iso_coords(t_iso *iso, t_pixel *p, int i, int j, int z)
{
	iso->isoX = (j - i) * cos(iso->angle) * len_line + p->beginX;
	iso->isoY = (j + i) * sin(iso->angle) * len_line - z * iso->height
		+ p->beginY;
}
void	connect_points(t_data *data, t_iso *iso, t_pixel *p, t_tab *tab, int i,
		int j)
{
	int	nextZ;
	
	nextZ = tab->tab[i][j];
	calculate_iso_coords(iso, p, i, j, tab->tab[i][j]);
	if (j < tab->x - 1)
	{
		nextZ = tab->tab[i][j + 1];
		iso->nextIsoX = ((j + 1) - i) * cos(iso->angle) * len_line + p->beginX;
		iso->nextIsoY = ((j + 1) + i) * sin(iso->angle) * len_line - nextZ
			* iso->height + p->beginY;
		draw_line(data, iso->isoX, iso->isoY, iso->nextIsoX, iso->nextIsoY);
	}
	if (i < tab->y - 1)
	{
		nextZ = tab->tab[i + 1][j];
		iso->nextIsoX = (j - (i + 1)) * cos(iso->angle) * len_line + p->beginX;
		iso->nextIsoY = (j + (i + 1)) * sin(iso->angle) * len_line - nextZ
			* iso->height + p->beginY;
		draw_line(data, iso->isoX, iso->isoY, iso->nextIsoX, iso->nextIsoY);
	}
}

void	draw_project(t_pixel *p, t_iso *iso, t_data *data, t_tab *tab)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tab->y)
	{
		j = -1;
		while (++j < tab->x)
		{
			connect_points(data, iso, p, tab, i, j);
		}
	}
}

void	tab_to_pixel(t_data *data, t_tab *tab)
{
	t_pixel	p;
	t_iso	iso;

	iso.tableWidth = tab->x * len_line;
	iso.tableHeight = tab->y * len_line;
	iso.angle = M_PI / 4; // 45 degrees radian
	iso.height = 2;       // valeur a augmenter pour voir la hauteur
	p.beginX = (WIDTH - iso.tableWidth) / 2;
	p.beginY = (HEIGHT - iso.tableHeight) / 2;
	if (!tab)
		return ;
	draw_project(&p, &iso, data, tab);
}

int	init_mlx(t_tab *tab)
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
	tab_to_pixel(&data, tab);
	mlx_put_image_to_window(data.mlx_ptr, data.win_ptr, data.img_ptr, 0, 0);
	mlx_key_hook(data.win_ptr, handle_esc, &data);
	mlx_hook(data.win_ptr, 17, 0, close_window, &data);
	free_maps(tab->tab, tab->y);
	mlx_loop(data.mlx_ptr);
	return (0);
}

int	main(int ac, char **av)
{
	t_tab	tab;
	int		k;

	ac = 5;
	k = -1;
	tab.y = count_y(av[1]);
	tab.x = count_x(av[1]);
	tab.tab = init_map(av[1]);
	print_tab(av[1], tab.tab);
	init_mlx(&tab);
}
