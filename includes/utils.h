/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:24:35 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 09:24:48 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

int		ft_create_trgb(double iter);
void	ft_mlx_pixel_put(t_vars *data, int x, int y, int color);
int		ft_render_fractol(t_vars *vars);
int		ft_destroy_all(t_vars *vars);

#endif
