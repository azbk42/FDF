/* *************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 14:58:01 by emauduit          #+#    #+#             */
/*   Updated: 2023/12/31 16:48:19 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../Libft/libft.h"
#include "../minilibx-linux/mlx.h"
#include <X11/X.h>
#include <X11/keysym.h>

// define

#define HEIGHT 800
#define WIDTH 400
#define MALLOC_ERROR 1
// struct

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
    void    *img_ptr;
    char    *path;
    int     bits_pixel;
    int     size_line;
    int     endian;

}			t_data;

// initialisation de la map en tableau de INT

int			count_y(char *str);
int			count_x(char *str);
int			**init_map(char *str);

// fermer le prog

int	close_window(t_data *data);
int handle_esc(int keysym, t_data *data);

// draw
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif