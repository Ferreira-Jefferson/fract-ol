/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 15:32:39 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/12 11:07:51 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/fractol.h"

int	main(int argc, char *argv[])
{	
	if (ft_validate_input(argc, argv))
	{
		ft_printf("Usage: ./fractol mandelbrot ");
		ft_printf("or ./fractol julia <int_real_part> <int_imaginary_part>\n");
		ft_printf("Ex: ./fractol mandelbrot or ./fractol julia -0.7 0.27\n");
		return (0);
	}
	return (ft_fractol(argv));
}

int	ft_validate_input(int argc, char *argv[])
{
	char	*fractol_name;
	char	*name_trim;

	name_trim = ft_strtrim(argv[1], " ");
	if (!name_trim)
		return (1);
	fractol_name = ft_str_tolower(name_trim);
	free(name_trim);
	if (ft_isequal(fractol_name, "mandelbrot"))
	{
		ft_to_free((void **) &fractol_name);
		return (0);
	}
	if (ft_isequal(fractol_name, "julia") && argc == 4)
	{
		if (ft_is_valid_number(argv[2]) && ft_is_valid_number(argv[3]))
		{
			ft_to_free((void **) &fractol_name);
			return (0);
		}
	}
	ft_to_free((void **) &fractol_name);
	return (1);
}

int	ft_fractol(char *argv[])
{
	t_vars	vars;
	char	*name_trim;

	vars.win_width = 1000;
	vars.win_height = 800;
	vars.zoom = 1.0;
	vars.offset_x = -2.0;
	vars.offset_y = -2.0;
	vars.max_iterations = 100;
	if (ft_setup_mlx(&vars))
		return (ft_destroy_all(&vars));
	name_trim = ft_strtrim(argv[1], " ");
	if (!name_trim)
		return (ft_destroy_all(&vars));
	vars.fractal_name = ft_str_tolower(name_trim);
	free(name_trim);
	if (!vars.fractal_name)
		return (ft_destroy_all(&vars));
	ft_setup_hooks(&vars);
	ft_render_fractol(&vars);
	mlx_loop(vars.mlx);
	return (0);
}
