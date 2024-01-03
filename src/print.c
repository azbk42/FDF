/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/03 12:43:06 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

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
