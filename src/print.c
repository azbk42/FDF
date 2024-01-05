/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/05 11:41:56 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	print_tab(t_tab *tab)
{
	int	i;
	int	j;

	i = 0;
	while (i < tab->y)
	{
		j = 0;
		while (j < tab->x)
		{
			ft_printf("%d ", tab->tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
