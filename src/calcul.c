/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/03 18:02:32 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	find_max_height(t_tab *tab)
{
	int	max_height;
	int	i;
	int	j;

	max_height = 0;
	i = 0;
	while (i < tab->y)
	{
		j = 0;
		while (j < tab->x)
		{
			if (tab->tab[i][j] > max_height)
				max_height = tab->tab[i][j];
			j++;
		}
		i++;
	}
	return (max_height);
}

void	calculate_iso_coords(t_iso *iso, t_pixel *p, t_tab *index)
{
	iso->iso_x = (index->j - index->i) * cos(iso->angle) * LEN_LINE
		+ p->begin_x;
	iso->iso_y = (index->j + index->i) * sin(iso->angle) * LEN_LINE - index->z
		* iso->height + p->begin_y;
}

void	adjust_starting_points(t_iso *iso, t_pixel *p, t_tab *tab)
{
    t_projection proj;

    proj.projected_width = (tab->x - 1) * cos(iso->angle) * LEN_LINE;
    proj.projected_height = (tab->y - 1) * sin(iso->angle) * LEN_LINE;
    proj.window_center_x = WIDTH / 2;
    proj.window_center_y = HEIGHT / 2;
    proj.projection_center_x = proj.projected_width / 2;
    proj.projection_center_y = proj.projected_height / 2;
    p->begin_x = proj.window_center_x;
    p->begin_y = proj.window_center_y - proj.projection_center_y - 100;
}
