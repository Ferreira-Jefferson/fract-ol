#ifndef UTILS_H
# define UTILS_H

# include "fractol.h"

int	ft_create_trgb(int iter);
void ft_mlx_pixel_put(t_vars *data, int x, int y, int color);
int ft_render_fractol(t_vars *vars);
int ft_destroy_all(t_vars *vars);

#endif
