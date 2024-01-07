/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_y_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:26 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/07 13:19:48 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int ft_tablen(char **value, char *line)
{
	int count;
	int i;

	i = 0;
	count = 0;
	value = ft_split(line, ' ');
	while (value[count])
		count++;
	while (value[i])
		free(value[i++]);
	free(value); // Free the value array
	return (count);
}

int	count_y_x(char *str, t_tab *tab)
{
	int		fd;
	char	*line;
	char	**value;
	int 	flag;
	
	flag = 0;
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
		if (tab->x != (int)ft_tablen(value, line))
			flag = -1;
		tab->y += 1;
		free(line);
		line = get_next_line(fd);
	}
	free(value); // Free the value array
	close(fd);
	return (flag);
}
