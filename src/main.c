/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/07 16:07:54 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_tab	tab;

	tab.y = 0;
	tab.x = 0;
	if (ac == 2)
	{
		if (count_y_x(av[1], &tab) < 0)
		{
			return (error_shape(), EXIT_FAILURE);
		}
		tab.tab = init_map(av[1], tab.x, tab.y);
		init_mlx(&tab);
	}
	else
	{
		error_nb_arg();
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
