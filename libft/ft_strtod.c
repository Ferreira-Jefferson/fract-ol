/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 15:04:16 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/12 15:57:58 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctype.h>
#include <math.h>

static double	ft_get_signal(const char **str)
{
	double	sign;

	sign = 1.0;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1.0;
		(*str)++;
	}
	return (sign);
}

static double	ft_get_decimal_part(const char **str)
{
	double	fraction;
	double	divisor;

	fraction = 0.0;
	divisor = 1.0;
	while (isdigit((unsigned char)**str))
	{
		fraction = fraction * 10.0 + (**str - '0');
		divisor *= 10.0;
		(*str)++;
	}
	return (fraction / divisor);
}

double	ft_strtod(const char *str, const char **endptr)
{
	double		result;
	double		sign;

	while (isspace((unsigned char)*str))
		str++;
	sign = ft_get_signal(&str);
	result = 0.0;
	while (isdigit((unsigned char)*str))
	{
		result = result * 10.0 + (*str - '0');
		str++;
	}
	if (*str == '.')
	{
		str++;
		result += ft_get_decimal_part(&str);
	}
	if (endptr)
		*endptr = str;
	return (sign * result);
}
