/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emauduit <emauduit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:24:13 by azbreak           #+#    #+#             */
/*   Updated: 2023/11/08 15:18:06 by emauduit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		len;
	char	*tab;
	int		j;

	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	tab = malloc(len * sizeof(char) + 1);
	if (!tab)
		return (NULL);
	while (s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		tab[i] = s2[j];
		i++;
		j++;
	}
	tab[i] = '\0';
	return (tab);
}

// #include <stdio.h>

// int main(int ac, char *av[])
// {
//     if (ac == 3)
//         printf("%s|\n", ft_strjoin(av[1], av[2]));
// }