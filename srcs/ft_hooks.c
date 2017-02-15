/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/14 18:39:11 by Mangata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env *env)
{	
	mlx_pixel_put(env->mlx, env->win, 50, 50, 0x00FF00);
	return (0);
}

int		loop_hook(t_env	*env)
{
	expose_hook(env);
	return (0);
}

int 	key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
