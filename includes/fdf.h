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
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
// define

# define HEIGHT 600
# define WIDTH 800
# define len_line 20
# define MALLOC_ERROR 1

// struct

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*path;
	int		bits_pixel;
	int		size_line;
	int		endian;

}			t_data;

typedef struct s_pixel
{
	int		beginX;
	int		beginY;
	int		endX;
	int		endY;

}			t_pixel;

typedef struct s_tab
{
	int	**tab;
	int	y;
	int	x;
	int z;
}			t_tab;

typedef struct s_iso
{
	int		isoX;
	int		isoY;
	int		nextIsoX;
	int		nextIsoY;
	int		height;
	int		tableWidth;
	int		tableHeight;
	float	angle;
}			t_iso;

// initialisation de la map en tableau de INT

int			**free_maps(int **tab, int index);
int			count_y(char *str);
int			count_x(char *str);
int			**init_map(char *str);

// fermer le prog

int			close_window(t_data *data);
int			handle_esc(int keysym, t_data *data);

// draw
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_line(t_data *data, int beginX, int beginY, int endX, int endY);
void		print_tab(char *av, int **tab);

#endif