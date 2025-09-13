/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jtertuli <jtertuli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/13 11:47:07 by jtertuli          #+#    #+#             */
/*   Updated: 2025/09/13 11:47:08 by jtertuli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_vars {
	void	*mlx;
	void	*win;
	char	*fractol_name;
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
}	t_vars;

typedef struct s_fractal_result {
	int		iter;
	double	z_real;
	double	z_imag;
}	t_fractal_result;

#endif