/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_control.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:28:59 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 09:29:14 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_CONTROL_H
# define UTILS_CONTROL_H

# include "fractol.h"
# include "utils.h"

int	ft_x_close_win(t_vars *vars);
int	ft_esc_close_win(int keyword, t_vars *vars);
int	ft_mouse_event_handler(int button, int x, int y, t_vars *data);

#endif