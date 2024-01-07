/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 14:30:33 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/07 12:40:55 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	get_color(int start_z, int end_z, int flag)
{
	int	color;

	if (flag == 1)
	{
		if (start_z <= 0 && end_z <= 0)
			color = BLUE;
		else if (start_z >= 75 && end_z >= 75)
			color = YELLOW;
		else if (start_z <= 0 && end_z >= 25)
			color = YELLOW;
		else if (start_z >= 25 && end_z <= 0)
			color = YELLOW;
		else if (start_z > 0 && end_z > 0)
			color = GREEN;
		else if (start_z < 0 && end_z >= 0)
			color = GREEN;
		else
			color = GREEN;
		return (color);
	}
	else
		return (WHITE);
}
