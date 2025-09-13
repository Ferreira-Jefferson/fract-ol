/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_fractol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:17:29 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 09:22:44 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils_fractol.h"

static void	ft_set_z(double *z_r, double val_z_r, double *z_i, double val_z_i)
{
	*z_r = val_z_r;
	*z_i = val_z_i;
}

static void	ft_set_c(double *c_r, double val_c_r, double *c_i, double val_c_i)
{
	*c_r = val_c_r;
	*c_i = val_c_i;
}

static t_fractal_result	ft_calculate_fractal_math(double pixel_r, \
	double pixel_i, t_vars *vars)
{
	t_fractal_result	result;
	double				z_r_temp;
	double				c_r;
	double				c_i;

	ft_set_z(&result.z_real, 0, &result.z_imag, 0);
	ft_set_c(&c_r, pixel_r, &c_i, pixel_i);
	if (ft_isequal(vars->fractol_name, "julia"))
	{
		ft_set_z(&result.z_real, pixel_r, &result.z_imag, pixel_i);
		ft_set_c(&c_r, vars->c_real, &c_i, vars->c_imag);
	}
	result.iter = 0;
	while (result.iter < vars->max_iterations)
	{
		if (result.z_real * result.z_real + result.z_imag * result.z_imag > 4.0)
			break ;
		z_r_temp = result.z_real * result.z_real - result.z_imag
			* result.z_imag + c_r;
		result.z_imag = 2.0 * result.z_real * result.z_imag + c_i;
		result.z_real = z_r_temp;
		result.iter++;
	}
	return (result);
}

static double	ft_calculate_iterations(t_vars *vars, int x, int y)
{
	t_fractal_result	result;
	double				pixel_r;
	double				pixel_i;
	double				smooth_iter;

	pixel_r = vars->offset_x + (double)x / vars->win_width * 4.0 / vars->zoom;
	pixel_i = vars->offset_y + (double)y / vars->win_height * 4.0 / vars->zoom;
	if (ft_isequal(vars->fractol_name, "mandelbrot"))
		result = ft_calculate_fractal_math(pixel_r, pixel_i, vars);
	else
		result = ft_calculate_fractal_math(pixel_r, pixel_i, vars);
	if (result.iter == vars->max_iterations)
		return ((double)vars->max_iterations);
	smooth_iter = (double)result.iter + 1.0 - log(log(\
		sqrt(result.z_real * result.z_real + result.z_imag * result.z_imag))) \
		/ log(2.0);
	return (smooth_iter);
}

void	ft_create_fractol(t_vars *vars)
{
	int		x;
	int		y;
	double	smooth_iter;
	int		color;

	y = -1;
	while (++y < vars->win_height)
	{
		x = -1;
		while (++x < vars->win_width)
		{
			smooth_iter = ft_calculate_iterations(vars, x, y);
			if (smooth_iter >= vars->max_iterations)
				color = 0x000000;
			else
				color = ft_create_trgb(smooth_iter);
			ft_mlx_pixel_put(vars, x, y, color);
		}
	}
}
