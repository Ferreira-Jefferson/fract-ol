/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:17:29 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/12 11:19:56 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/mandelbrot.h"

static int	ft_calculate_mandelbrot(double c_real, double c_imag, int max_iter)
{
	double	z_real;
	double	z_imag;
	double	z_real_temp;
	int		iter;

	z_real = 0;
	z_imag = 0;
	iter = 0;
	while (iter < max_iter)
	{
		z_real_temp = z_real * z_real - z_imag * z_imag + c_real;
		z_imag = 2.0 * z_real * z_imag + c_imag;
		z_real = z_real_temp;
		if (z_real * z_real + z_imag * z_imag > 4.0)
			break ;
		iter++;
	}
	return (iter);
}

static double	ft_calculate_interations(t_vars *vars, double x, double y)
{
	int		iter;
	double	complex_real;
	double	complex_imag;

	complex_real = vars->offset_x + x / vars->win_width * 4.0 / vars->zoom;
	complex_imag = vars->offset_y + y / vars->win_height * 4.0 / vars->zoom;
	iter = ft_calculate_mandelbrot(complex_real, complex_imag, \
		vars->max_iterations);
	return (iter);
}

void	ft_fractal_mandelbrot(t_vars *vars)
{
	int		x;
	int		y;
	int		iter;
	int		color;

	y = 0;
	while (y < vars->win_height)
	{
		x = 0;
		while (x < vars->win_width)
		{
			iter = ft_calculate_interations(vars, x, y);
			if (iter == vars->max_iterations)
				color = ft_create_trgb(0);
			else
				color = ft_create_trgb(iter);
			ft_mlx_pixel_put(vars, x, y, color);
			x++;
		}
		y++;
	}
}
