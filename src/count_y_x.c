/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:26 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/05 20:24:06 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	count_y_x(char *str, t_tab *tab)
{
	int		fd;
	char	*line;
	char	**value;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (-1);
	line = get_next_line(fd);
	value = ft_split(line, ' ');
	tab->x = -1;
	while (value[++tab->x])
		free(value[tab->x]);
	while (line)
	{
		tab->y += 1;
		free(line);
		line = get_next_line(fd);
	}
	free(value);
	close(fd);
	return (0);
}
