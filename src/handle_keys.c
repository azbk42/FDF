/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:32:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/05 19:03:53 by emauduit         ###   ########.fr       */
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

void	redraw_map(t_data *data, t_pixel *p, t_tab *tab)
{
	t_iso	iso;
	
	mlx_clear_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, WIDTH, HEIGHT);
	data->path = mlx_get_data_addr(data->img_ptr, &data->bits_pixel,
			&data->size_line, &data->endian);
	if (!tab)
		return ;
	iso.angle = M_PI / 6;
	if (p->len_line < 1)
		p->len_line = 1;
	printf("iso.height: %f\n", data->p->height);
	draw_project(p, &iso, data, tab);
}


int	handle_key(int key, t_data *data)
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
	else if (key == XK_KP_Add) // '+' key on the numpad
		data->p->len_line += 1;
	else if (key == XK_KP_Subtract) // '-' key
		data->p->len_line -= 1;
	else if (key == XK_Up)
		data->p->begin_y -= 20;
	else if (key == XK_Down)
		data->p->begin_y += 20;
	else if (key == XK_Left)
		data->p->begin_x -= 20;
	else if (key == XK_Right)
		data->p->begin_x += 20;
	else if (key == PAGE_UP)
		data->p->height += 0.1;
	else if (key == PAGE_DOWN)
		data->p->height -= 0.1;
	redraw_map(data, data->p, data->tab);
	return (0);
}
