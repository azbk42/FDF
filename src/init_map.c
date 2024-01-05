/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 17:46:41 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/05 16:45:53 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	**free_maps(int **tab, int index)
{
	int	i;

	i = 0;
	while (i < index)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static int	**init_array(int y, int x)
{
	int	**maps;
	int	i;

	i = 0;
	maps = malloc(sizeof(int *) * y);
	if (!maps)
		return (NULL);
	while (i < y)
	{
		maps[i] = malloc(sizeof(int) * x);
		if (!maps[i])
		{
			free_maps(maps, i);
			return (NULL);
		}
		i++;
	}
	return (maps);
}

static void	fill_line(int *tab, char **split, int x)
{
	int	i;

	i = 0;
	while (i < x)
	{
		tab[i] = ft_atoi(split[i]);
		i++;
	}
}

static int	**fill_array(int **tab, char *str, int x)
{
	char	**split;
	char	*line;
	int		fd;
	int		i;
	int		j;

	i = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		split = ft_split(line, ' ');
		fill_line(tab[i], split, x);
		j = -1;
		while (split[++j])
			free(split[j]);
		free(split);
		free(line);
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (tab);
}

int	**init_map(char *str, int x, int y)
{
	int	**tab;

	tab = init_array(y, x);
	tab = fill_array(tab, str, x);
	return (tab);
}
