/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:21:07 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/06 13:32:45 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_nb_arg(void)
{
	ft_printf("Error, plz retry with this shape -> ./fdf [map.fdf]");
	exit(EXIT_FAILURE);
}

void	error_file(void)
{
	ft_printf("Error, plz retry with a valid file");
	exit(EXIT_FAILURE);
}
