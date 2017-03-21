/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks_bis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 02:27:01 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/21 03:57:54 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_manage_mov(t_env **env, int keycode)
{
	if (keycode == K_UP)
		(*env)->y_pos -= 30;
	if (keycode == K_DOWN)
		(*env)->y_pos += 30;
	if (keycode == K_RIGHT)
		(*env)->x_pos += 30;
	if (keycode == K_LEFT)
		(*env)->x_pos -= 30;
	ft_manage_view(env);
}

void	ft_manage_height(t_env **env, int keycode)
{
	if (keycode == K_Q)
		(*env)->height -= 5;
	if (keycode == K_W)
		(*env)->height += 5;
	ft_manage_view(env);
}

void	ft_change_view(t_env **env, int keycode)
{
	if (keycode == K_1)
		(*env)->view = 1;
	if (keycode == K_2)
		(*env)->view = 2;
	if (keycode == K_3)
		(*env)->view = 3;
	ft_manage_view(env);
}
