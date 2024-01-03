/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:26 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/03 11:50:59 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_x(char *str)
{
	int		x;
	int		fd;
	char	*line;
	char	**value;

	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	value = ft_split(line, ' ');
	x = -1;
	while (value[++x])
		free(value[x]);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
	}
	free(value);
	close(fd);
	return (x);
}

int	count_y(char *str)
{
	int		fd;
	int		y;
	char	*line;

	y = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		y += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (y);
}
