/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:34:12 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 07:51:49 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"
#include "includes/utils.h"

int	ft_create_trgb(double iter)
{
	int	r;
	int	g;
	int	b;

	r = (int)(sin(0.1 * iter) * 127 + 128);
	g = (int)(sin(0.1 * iter + 2.0) * 127 + 128);
	b = (int)(sin(0.1 * iter + 4.0) * 127 + 128);

    // CORREÇÃO IMPORTANTE:
    // O padrão para cores TRGB de 32 bits é 8 bits para cada canal.
    // Transparência (T): bits 24-31
    // Vermelho (R): bits 16-23
    // Verde (G): bits 8-15
    // Azul (B): bits 0-7
    // A sua versão anterior deslocava G e B incorretamente.
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
