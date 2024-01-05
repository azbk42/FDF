/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:26 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/05 18:54:33 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	tab_to_pixel(t_data *data, t_tab *tab, t_pixel *p)
{
	t_iso	iso;

	if (!tab)
		return ;
	iso.angle = M_PI / 6;
	adjust_starting_points(&iso, p, tab);
	draw_project(p, &iso, data, tab);
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
	setup_and_run_mlx(&data, tab);
	return (0);
}

void	setup_and_run_mlx(t_data *data, t_tab *tab)
{
	t_pixel	p;

	data->tab = tab;
	data->p = &p;
	data->p->len_line = 2;
	data->p->height = 2;
	data->path = mlx_get_data_addr(data->img_ptr, &data->bits_pixel,
			&data->size_line, &data->endian);
	tab_to_pixel(data, tab, &p);
	mlx_key_hook(data->win_ptr, handle_key, data);
	mlx_hook(data->win_ptr, 17, 0, close_window, data);
	mlx_loop(data->mlx_ptr);
}
