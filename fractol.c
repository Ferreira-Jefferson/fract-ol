/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:32:39 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 08:50:16 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(int argc, char *argv[])
{	
	t_vars	vars;

	if (ft_validate_input(argc, argv, &vars))
	{
		ft_printf("Usage: ./fractol mandelbrot ");
		ft_printf("or ./fractol julia <int_real_part> <int_imaginary_part>\n");
		ft_printf("Ex: ./fractol mandelbrot or ./fractol julia -0.7 0.27\n");
		return (0);
	}
	return (ft_fractol(argv, &vars));
}

static int	ft_get_values_julia(t_vars *vars, char *value_1, char *value_2)
{
	const char	*end;

	vars->c_real = ft_strtod(value_1, &end);
	if (vars->c_real == 0 && ft_strlen(end))
		return (1);
	vars->c_imag = ft_strtod(value_2, &end);
	if (vars->c_imag == 0 && ft_strlen(end))
		return (1);
	return (0);
}

int	ft_validate_input(int argc, char *argv[], t_vars *vars)
{
	char	*name_trim;

	name_trim = ft_strtrim(argv[1], " ");
	if (!name_trim)
		return (1);
	vars->fractol_name = ft_str_tolower(name_trim);
	free(name_trim);
	if (ft_isequal(vars->fractol_name, "mandelbrot"))
	{
		vars->c_real = 0;
		vars->c_imag = 0;
		return (0);
	}
	if (ft_isequal(vars->fractol_name, "julia") && argc == 4)
		return (ft_get_values_julia(vars, argv[2], argv[3]));
	return (1);
}

int	ft_fractol(char *argv[], t_vars *vars)
{
	char	*name_trim;

	vars->win_width = 1000;
	vars->win_height = 800;
	vars->zoom = 1.0;
	vars->offset_x = -2.0;
	vars->offset_y = -2.0;
	vars->max_iterations = 100;
	if (ft_setup_mlx(vars))
		return (ft_destroy_all(vars));
	name_trim = ft_strtrim(argv[1], " ");
	if (!name_trim)
		return (ft_destroy_all(vars));
	if (!vars->fractol_name)
		return (ft_destroy_all(vars));
	ft_setup_hooks(vars);
	ft_render_fractol(vars);
	mlx_loop(vars->mlx);
	return (0);
}
