#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include "../minilibx/mlx.h"

# include <stdlib.h>
# include <math.h>

# define MOUSE_BUTTON_PRESS_EVENT (4)
# define MOUSE_BUTTON_PRESS_MASK (1L<<2)
# define ESC_KEYCODE (65307)
# define ON_KEYDOWN (2)
# define ON_DESTROY (17)
# define NO_MOUSE_CLICK_MASK (1L << 0)

typedef struct s_vars t_vars;

typedef struct s_vars {
	void 	*mlx;
	void 	*win;
	char 	*fractol_name;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		win_width;
	int		win_height;
	double	zoom;
	double	offset_x;
	double	offset_y;
	int		max_iterations;
    double	c_real;
    double	c_imag;
} t_vars;

typedef struct s_fractal_result {
	int		iter;
	double	z_real;
	double	z_imag;
}	t_fractal_result;

# include "utils.h"
# include "utils_setup.h"
# include "utils_control.h"
# include "utils_fractol.h"

int	ft_fractol(char *argv[], t_vars *vars);
int	ft_validate_input(int argc, char *argv[], t_vars *vars);



#endif