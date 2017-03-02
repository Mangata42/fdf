/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/02 18:11:57 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env **env)
{	
	// int x_pos;
	// int y_pos;

	// x_pos = ((((W_X / (*env)->x_max)) / 2) * (*env)->x_max) - (*env)->x_max * 4;
	// y_pos = ((((W_Y / (*env)->y_max)) / 2) * (*env)->y_max) - (*env)->y_max * 4;
	mlx_put_image_to_window((*env)->mlx, (*env)->win, (*env)->img, 0, 0);
	return (0);
}

void	ft_manage_zoom(t_env **env, int keycode)
{
	if (keycode == K_MIN)
		(*env)->step -= 3;
	if (keycode == K_MAX)
		(*env)->step += 3;
	if ((*env)->step <= 0)
		(*env)->step = 0;
	mlx_destroy_image((*env)->mlx, (*env)->img);
	(*env)->img = mlx_new_image((*env)->mlx, W_X, W_Y);
	ft_iso_view(env, ft_copy_struct((*env)->coords));
	expose_hook(env);
}

int 	key_hook(int keycode, t_env **env)
{
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == K_1)
	{
		mlx_destroy_image((*env)->mlx, (*env)->img);
		(*env)->img = mlx_new_image((*env)->mlx, W_X, W_Y);
		ft_std_view(env, ft_copy_struct((*env)->coords));
		expose_hook(env);
	}
	if (keycode == K_2)
	{
		mlx_destroy_image((*env)->mlx, (*env)->img);
		(*env)->img = mlx_new_image((*env)->mlx, W_X, W_Y);
		ft_iso_view(env, ft_copy_struct((*env)->coords));
		expose_hook(env);
	}
	if (keycode == K_3)
	{
		mlx_destroy_image((*env)->mlx, (*env)->img);
		(*env)->img = mlx_new_image((*env)->mlx, W_X, W_Y);
		ft_paral_view(env, ft_copy_struct((*env)->coords));
		expose_hook(env);
	}
	if (keycode == K_MIN || keycode == K_MAX)
		ft_manage_zoom(env, keycode);
	return (0);
}
