/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 18:41:46 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/02 18:53:12 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->path + (y * data->size_line + x * (data->bits_pixel / 8));
	*(unsigned int*)dst = color;
}
void draw_line(t_data *data, int beginX, int beginY, int endX, int endY)
{
	double deltaX;
	double deltaY;
	double pixelX;
	double pixelY;
	int pixels;

	deltaX = endX - beginX;
	deltaY = endY - beginY;
	pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	deltaX /= pixels;
	deltaY /= pixels;
	pixelX = beginX;
	pixelY = beginY;
	while (pixels)
	{
		my_mlx_pixel_put(data, pixelX, pixelY, 0xFFFFFFFF);
		pixelX += deltaX;
		pixelY += deltaY;
		--pixels;
	}
}
void	print_tab(char *av, int **tab)
{
	int	y;
	int	x;
	int	i;
	int	j;

	i = 0;
	x = count_x(av);
	y = count_y(av);
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			ft_printf("%d ", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
