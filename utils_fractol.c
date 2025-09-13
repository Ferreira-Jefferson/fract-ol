/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:17:29 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 07:55:26 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils_fractol.h"

static t_fractal_result	ft_calculate_fractol(double c_real, double c_imag, int max_iter)
{
	t_fractal_result	result;
	double				z_real_temp;

	result.z_real = 0;
	result.z_imag = 0;
	result.iter = 0;
	while (result.iter < max_iter)
	{
		// Condição de escape: |z|^2 > 4. O quadrado da magnitude é (z_real^2 + z_imag^2).
		if (result.z_real * result.z_real + result.z_imag * result.z_imag > 4.0)
			break ;
		z_real_temp = result.z_real * result.z_real - result.z_imag * result.z_imag
			+ c_real;
		result.z_imag = 2.0 * result.z_real * result.z_imag + c_imag;
		result.z_real = z_real_temp;
		result.iter++;
	}
	return (result);
}

static double	ft_calculate_interations(t_vars *vars, double x, double y)
{
	t_fractal_result	result;
	double				complex_real;
	double				complex_imag;
	double				smooth_iter;
	double				magnitude;

	complex_real = vars->offset_x + x / vars->win_width * 4.0 / vars->zoom;
	complex_imag = vars->offset_y + y / vars->win_height * 4.0 / vars->zoom;
	result = ft_calculate_fractol(complex_real, complex_imag,
			vars->max_iterations);
	
	// Se o ponto não escapou (pertence ao conjunto), retornamos o máximo de iterações.
	if (result.iter == vars->max_iterations)
		return ((double)vars->max_iterations);
	
	magnitude = sqrt(result.z_real * result.z_real + result.z_imag * result.z_imag);
	smooth_iter = (double)result.iter + 1.0 - log(log(magnitude)) / log(2.0);
	
	return (smooth_iter);
}

void	ft_create_fractol(t_vars *vars)
{
	int		x;
	int		y;
	double	smooth_iter;
	int		color;

	y = 0;
	while (y < vars->win_height)
	{
		x = 0;
		while (x < vars->win_width)
		{
			smooth_iter = ft_calculate_interations(vars, x, y);
			if (smooth_iter >= vars->max_iterations)
				color = 0x000000; // Cor preta para o interior do conjunto
			else
				color = ft_create_trgb(smooth_iter);
			ft_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}
}
