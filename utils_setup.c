/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_setup.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:20:40 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 11:44:55 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/utils_setup.h"

int	ft_setup_mlx(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (!vars->mlx)
		return (1);
	vars->win = mlx_new_window(vars->mlx, \
		vars->win_width, vars->win_height, "Fract'ol");
	if (!vars->win)
		return (ft_destroy_all(vars));
	vars->img = mlx_new_image(vars->mlx, \
		vars->win_width, vars->win_height);
	if (!vars->img)
		return (ft_destroy_all(vars));
	vars->addr = mlx_get_data_addr(vars->img, \
		&vars->bits_per_pixel, &vars->line_length, &vars->endian);
	if (!vars->addr)
		return (ft_destroy_all(vars));
	return (0);
}

void	ft_setup_hooks(t_vars *vars)
{
	mlx_hook(vars->win, ON_DESTROY, 0, ft_x_close_win, vars);
	mlx_key_hook(vars->win, ft_esc_close_win, vars);
	mlx_hook(vars->win, MOUSE_BUTTON_PRESS_EVENT, MOUSE_BUTTON_PRESS_MASK << 2, \
		ft_mouse_event_handler, vars);
}
