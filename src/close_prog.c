/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_prog.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 17:32:56 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/02 18:15:42 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


int	close_window(t_data *data)
{
    mlx_destroy_image(data->mlx_ptr, data->img_ptr);
    mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
    exit(0);
    return (0);
}

int handle_esc(int keysym, t_data *data)
{
    if (keysym == XK_Escape)
    {
        ft_printf("ESC has been pressed, prog close\n\n");
        mlx_destroy_image(data->mlx_ptr, data->img_ptr);
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
        mlx_destroy_display(data->mlx_ptr);
        free(data->mlx_ptr);
        exit(0);
    }
    return (0);
}