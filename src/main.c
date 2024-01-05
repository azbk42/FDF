/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/05 16:53:54 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_nb_arg(void)
{
	ft_printf("Error, plz retry with this shape -> ./fdf [map.fdf]");
}

int	main(int ac, char **av)
{
	t_tab	tab;

	tab.y = 0;
	tab.x = 0;
	if (ac == 2)
	{
		count_y_x(av[1], &tab);
		tab.tab = init_map(av[1], tab.x, tab.y);
		// print_tab(&tab);
		init_mlx(&tab);
	}
	else
	{
		error_nb_arg();
		return (1);
	}
}
