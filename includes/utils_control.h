#ifndef UTILS_CONTROL_H
# define UTILS_CONTROL_H

# include "fractol.h"
# include "utils.h"

int	ft_x_close_win(t_vars *vars);
int	ft_esc_close_win(int keyword, t_vars *vars);
int ft_mouse_event_handler(int button, int x, int y, t_vars *data);

#endif