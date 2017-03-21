/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/21 09:41:05 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env **env)
{
	mlx_put_image_to_window((*env)->mlx, (*env)->win, (*env)->img, 0, 0);
	return (0);
}

void	ft_manage_zoom(t_env **env, int keycode)
{
	if (keycode == K_MIN || keycode == 5)
		(*env)->step -= 3;
	if (keycode == K_MAX || keycode == 4)
		(*env)->step += 3;
	if ((*env)->step <= 0)
		(*env)->step = 0;
	ft_manage_view(env);
}

void	ft_manage_view(t_env **env)
{
	mlx_destroy_image((*env)->mlx, (*env)->img);
	(*env)->img = mlx_new_image((*env)->mlx, W_X, W_Y);
	if ((*env)->view == 1)
		ft_std_view(env, ft_copy_struct((*env)->coords));
	if ((*env)->view == 2)
		ft_iso_view(env, ft_copy_struct((*env)->coords));
	if ((*env)->view == 3)
		ft_paral_view(env, ft_copy_struct((*env)->coords));
	expose_hook(env);
}

int		mouse_hook(int button, int x, int y, t_env **env)
{
	x = 0;
	y = 0;
	if (button == 4)
		ft_manage_zoom(env, button);
	if (button == 5)
		ft_manage_zoom(env, button);
	return (0);
}

int		key_hook(int keycode, t_env **env)
{
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	if (keycode == K_1 || keycode == K_2 || keycode == K_3)
		ft_change_view(env, keycode);
	if (keycode == K_MIN || keycode == K_MAX)
		ft_manage_zoom(env, keycode);
	if (keycode == K_RIGHT || keycode == K_LEFT
		|| keycode == K_UP || keycode == K_DOWN)
		ft_manage_mov(env, keycode);
	if (keycode == K_Q || keycode == K_W)
		ft_manage_height(env, keycode);
	return (0);
}
