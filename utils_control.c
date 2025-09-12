/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_control.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 11:29:44 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/12 11:33:33 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"
#include "includes/utils_control.h"

int	ft_esc_close_win(int keyword, t_vars *vars)
{
	if (keyword == 65307)
	{
		ft_destroy_all(vars);
		exit(0);
	}
	return (0);
}

int	ft_x_close_win(t_vars *vars)
{
	ft_destroy_all(vars);
	exit(0);
	return (0);
}

int	ft_mouse_event_handler(int button, int x, int y, t_vars *vars)
{
	double	mouse_real_before_zoom;
	double	mouse_imag_before_zoom;

	mouse_real_before_zoom = vars->offset_x + \
		(double)x / vars->win_width * (4.0 / vars->zoom);
	mouse_imag_before_zoom = vars->offset_y + \
		(double)y / vars->win_height * (4.0 / vars->zoom);
	if (button == 4)
		vars->zoom *= 1.1;
	else if (button == 5)
		vars->zoom /= 1.1;
	else
		return (0);
	vars->offset_x = mouse_real_before_zoom - \
		((double)x / vars->win_width * (4.0 / vars->zoom));
	vars->offset_y = mouse_imag_before_zoom - \
		((double)y / vars->win_height * (4.0 / vars->zoom));
	ft_render_fractol(vars);
	return (0);
}
