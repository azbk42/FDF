/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/05 18:44:23 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	calculate_iso_coords(t_iso *iso, t_pixel *p, t_tab *index, t_data *data)
{
	iso->iso_x = (index->j - index->i) * cos(iso->angle) * p->len_line
		+ p->begin_x;
	iso->iso_y = (index->j + index->i) * sin(iso->angle) * p->len_line
		- index->z * data->p->height + p->begin_y;
}

void	adjust_starting_points(t_iso *iso, t_pixel *p, t_tab *tab)
{
	t_projection	proj;

	proj.projected_width = (tab->x - 1) * cos(iso->angle) * p->len_line;
	proj.projected_height = (tab->y - 1) * sin(iso->angle) * p->len_line;
	proj.window_center_x = WIDTH / 2;
	proj.window_center_y = HEIGHT / 2;
	proj.projection_center_x = proj.projected_width / 2;
	proj.projection_center_y = proj.projected_height / 2;
	p->begin_x = proj.window_center_x;
	p->begin_y = proj.window_center_y - proj.projection_center_y - 100;
}
