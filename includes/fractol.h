/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 09:29:29 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 12:47:53 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <math.h>

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# include "structs.h"
# include "utils.h"
# include "utils_setup.h"
# include "utils_control.h"
# include "utils_fractol.h"

# define MOUSE_BUTTON_PRESS_EVENT (4)
# define MOUSE_BUTTON_PRESS_MASK (1L)
# define ESC_KEYCODE (65307)
# define ON_KEYDOWN (2)
# define ON_DESTROY (17)
# define NO_MOUSE_CLICK_MASK (1L)

int	ft_fractol(t_vars *vars);
int	ft_validate_input(int argc, char *argv[], t_vars *vars);

#endif