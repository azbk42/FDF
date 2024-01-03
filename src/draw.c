/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:41:46 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/03 17:55:26 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = data->path + (y * data->size_line + x * (data->bits_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	draw_line(t_data *data, t_iso *iso)
{
	double	delta_x;
	double	delta_y;
	double	pixel_x;
	double	pixel_y;
	int		pixels;

	delta_x = iso->nextiso_x - iso->iso_x;
	delta_y = iso->nextiso_y - iso->iso_y;
	pixels = sqrt((delta_x * delta_x) + (delta_y * delta_y));
	delta_x /= pixels;
	delta_y /= pixels;
	pixel_x = iso->iso_x;
	pixel_y = iso->iso_y;
	while (pixels)
	{
		my_mlx_pixel_put(data, pixel_x, pixel_y, 0xFFFFFFFF);
		pixel_x += delta_x;
		pixel_y += delta_y;
		--pixels;
	}
}

void	draw_next_point(t_data *data, t_iso *iso, t_pixel *p, t_tab index)
{
	if (!index.flag)
	{
		iso->nextiso_x = ((index.j + 1) - index.i) * cos(iso->angle) * LEN_LINE
			+ p->begin_x;
		iso->nextiso_y = ((index.j + 1) + index.i) * sin(iso->angle) * LEN_LINE
			- index.z * iso->height + p->begin_y;
	}
	else
	{
		iso->nextiso_x = (index.j - (index.i + 1)) * cos(iso->angle) * LEN_LINE
			+ p->begin_x;
		iso->nextiso_y = (index.j + (index.i + 1)) * sin(iso->angle) * LEN_LINE
			- index.z * iso->height + p->begin_y;
	}
	draw_line(data, iso);
}

void	connect_points(t_data *data, t_iso *iso, t_pixel *p, t_tab *tab)
{
	t_tab	index;

	index.i = tab->i;
	index.j = tab->j;
	index.z = tab->tab[index.i][index.j];
	calculate_iso_coords(iso, p, &index);
	if (index.j < tab->x - 1)
	{
		index.z = tab->tab[index.i][index.j + 1];
		index.flag = 0;
		draw_next_point(data, iso, p, index);
	}
	if (index.i < tab->y - 1)
	{
		index.z = tab->tab[index.i + 1][index.j];
		index.flag = 1;
		draw_next_point(data, iso, p, index);
	}
}

void	draw_project(t_pixel *p, t_iso *iso, t_data *data, t_tab *tab)
{
	tab->i = -1;
	while (++tab->i < tab->y)
	{
		tab->j = -1;
		while (++tab->j < tab->x)
		{
			connect_points(data, iso, p, tab);
		}
	}
}
