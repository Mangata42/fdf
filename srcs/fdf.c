/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:27:02 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/03 15:27:27 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(void)
{
	void	*mlx_ptr;
	void	*mlx_window;

	mlx_ptr = mlx_init();
	mlx_window = mlx_new_window(mlx_ptr, 500, 500, "TEST");
	mlx_loop(mlx_ptr);
	return (-1);
}
