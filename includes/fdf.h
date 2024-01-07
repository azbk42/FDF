/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 13:54:53 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/07 13:22:53 by emauduit         ###   ########.fr       */
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
# define HEIGHT 800
# define WIDTH 1200
# define MALLOC_ERROR 1
# define PAGE_UP 0xFF55
# define PAGE_DOWN 0xFF56

// define color

# ifndef COULEUR
#  define COULEUR 0
# endif
# define YELLOW 0xe0cb10
# define BLUE 0x381ea6
# define GREEN 0x1e8810
# define WHITE 0xffffff
// struct

typedef struct s_projection
{
	double	projected_width;
	double	projected_height;
	double	projection_center_x;
	double	projection_center_y;
	double	window_center_x;
	double	window_center_y;
}			t_projection;

typedef struct s_pixel
{
	int		begin_x;
	int		begin_y;
	int		end_x;
	int		end_y;
	int		len_line;
	float	height;

}			t_pixel;

typedef struct s_tab
{
	int		**tab;
	int		y;
	int		x;
	int		z;
	int		next_z;
	int		color;
	long	i;
	long	j;
	int		flag;
}			t_tab;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*path;
	int		bits_pixel;
	int		size_line;
	int		endian;
	t_tab	*tab;
	t_pixel	*p;

}			t_data;

typedef struct s_iso
{
	float	iso_x;
	float	iso_y;
	float	nextiso_x;
	float	nextiso_y;
	float	height;
	int		table_width;
	int		table_height;
	float	angle;
}			t_iso;

// initialisation de la map en tableau de INT

int			**free_maps(int **tab, int index);
int			count_y_x(char *str, t_tab *tab);
int			**init_map(char *str, int x, int y);

// check error
void		error_nb_arg(void);
void		error_file(void);

// fermer le prog et handle key

int			close_window(t_data *data);
int			handle_key(int key, t_data *data);
int			handle_esc(int key, t_data *data);

// color
int			get_color(int start_z, int end_z, int flag);

// calcul
void		calculate_iso_coords(t_iso *iso, t_pixel *p, t_tab *index,
				t_data *data);
void		adjust_starting_points(t_iso *iso, t_pixel *p, t_tab *tab);

// draw
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
void		draw_line(t_data *data, t_iso *iso, int z);
void		connect_points(t_data *data, t_iso *iso, t_pixel *p, t_tab *tab);
void		draw_next_point(t_data *data, t_iso *iso, t_pixel *p, t_tab index);
void		draw_project(t_pixel *p, t_iso *iso, t_data *data, t_tab *tab);
void		redraw_map(t_data *data, t_pixel *p, t_tab *tab);

// initialiation de la mlx

void		tab_to_pixel(t_data *data, t_tab *tab, t_pixel *p);
int			init_mlx(t_tab *tab);
void		setup_and_run_mlx(t_data *data, t_tab *tab);

#endif