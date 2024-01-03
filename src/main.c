/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:00:28 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/03 13:51:20 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	main(int ac, char **av)
{
	t_tab	tab;
	int		k;

	ac = 5;
	k = -1;
	tab.y = count_y(av[1]);
	tab.x = count_x(av[1]);
	tab.tab = init_map(av[1]);
	print_tab(av[1], tab.tab);
	init_mlx(&tab);
}
