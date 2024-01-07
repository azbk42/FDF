/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:32:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/06 17:16:03 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	close_window(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_maps(data->tab->tab, data->tab->y);
	free(data->mlx_ptr);
	exit(0);
	return (0);
}

int	handle_esc(int key, t_data *data)
{
	if (key == XK_Escape)
	{
		ft_printf("ESC has been pressed, prog close\n\n");
		mlx_destroy_image(data->mlx_ptr, data->img_ptr);
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
		free_maps(data->tab->tab, data->tab->y);
		exit(0);
	}
	return (0);
}

int	handle_key(int key, t_data *data)
{
	if (key == XK_Escape)
		handle_esc(key, data);
	if (key == XK_KP_Add)
		data->p->len_line += 1;
	else if (key == XK_KP_Subtract)
		data->p->len_line -= 1;
	else if (key == XK_Up)
		data->p->begin_y -= 30;
	else if (key == XK_Down)
		data->p->begin_y += 30;
	else if (key == XK_Left)
		data->p->begin_x -= 30;
	else if (key == XK_Right)
		data->p->begin_x += 30;
	else if (key == PAGE_UP)
		data->p->height += 0.1;
	else if (key == PAGE_DOWN)
		data->p->height -= 0.1;
	redraw_map(data, data->p, data->tab);
	return (0);
}
