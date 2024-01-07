/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 13:21:07 by emauduit          #+#    #+#             */
/*   Updated: 2024/01/07 16:08:01 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_shape(void)
{
	ft_printf("Error, plz retry with a valid shape");
}

void	error_nb_arg(void)
{
	ft_printf("Error, plz retry with this shape -> ./fdf [map.fdf]");
}

void	error_file(void)
{
	ft_printf("Error, plz retry with a valid file");
	exit(EXIT_FAILURE);
}
