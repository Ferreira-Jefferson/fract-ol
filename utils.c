/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:34:12 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/12 11:41:55 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"
#include "includes/utils.h"

int	ft_create_trgb(int iter)
{
	int	t;
	int	r;
	int	g;
	int	b;

	t = 0;
	r = (iter * 8) % 255;
	g = (iter * -233) % 255;
	b = (iter * 50) % 255;
	return (t << 24 | r << 16 | g << 11 | b << 2);
}

void	ft_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_render_fractol(t_vars *vars)
{
	if (ft_isequal(vars->fractal_name, "mandelbrot"))
		ft_fractal_mandelbrot(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	ft_destroy_all(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	ft_to_free((void **) &vars->mlx);
	ft_to_free((void **) &vars->fractal_name);
	return (1);
}
