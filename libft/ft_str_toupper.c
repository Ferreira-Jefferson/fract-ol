/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_toupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:09:29 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 14:25:24 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_toupper(char *str)
{
	char	*str_upper;
	int		i;

	str_upper = (char *) malloc(ft_strlen(str) + 1);
	if (!str_upper)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_upper[i] = ft_toupper(str[i]);
		i++;
	}
	str_upper[i] = '\0';
	return (str_upper);
}
