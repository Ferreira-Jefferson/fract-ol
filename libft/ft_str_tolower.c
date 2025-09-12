/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_lower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 11:09:29 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/06 14:32:49 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_tolower(char *str)
{
	char	*str_lower;
	int		i;

	str_lower = (char *) malloc(ft_strlen(str) + 1);
	if (!str_lower)
		return (NULL);
	i = 0;
	while (str[i])
	{
		str_lower[i] = ft_tolower(str[i]);
		i++;
	}
	str_lower[i] = '\0';
	return (str_lower);
}
	