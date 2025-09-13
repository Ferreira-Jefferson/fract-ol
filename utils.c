/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:34:12 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 08:48:22 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"
#include "includes/utils.h"

int	ft_create_trgb(double iter)
{
	int		r;
	int		g;
	int		b;
	double	frequency;

	frequency = 0.1;
	r = (int)(sin(frequency * iter + 0.0) * 127.5 + 127.5);
	g = (int)(sin(frequency * iter + 2.0) * 127.5 + 127.5);
	b = (int)(sin(frequency * iter + 4.0) * 127.5 + 127.5);
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	ft_mlx_pixel_put(t_vars *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_render_fractol(t_vars *vars)
{
	ft_create_fractol(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}

int	ft_destroy_all(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_image(vars->mlx, vars->img);
	mlx_destroy_display(vars->mlx);
	ft_to_free((void **) &vars->mlx);
	ft_to_free((void **) &vars->fractol_name);
	return (1);
}
