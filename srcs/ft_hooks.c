/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/24 21:19:14 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env **env)
{	
	mlx_put_image_to_window((*env)->mlx, (*env)->win, (*env)->img, W_X / 4, W_Y / 4);
	return (0);
}

int 	key_hook(int keycode, t_env **env)
{
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	ft_std_view(env, ft_copy_struct((*env)->coords));
	expose_hook(env);
	return (0);
}
