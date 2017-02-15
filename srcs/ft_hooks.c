/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/15 21:49:21 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		expose_hook(t_env **env)
{	
	mlx_clear_window((*env)->mlx, (*env)->win);
	mlx_put_image_to_window((*env)->mlx, (*env)->win, (*env)->img, 0, 0);
	mlx_string_put((*env)->mlx, (*env)->win, 1, 970, 0x00FF00, "fdf");
	return (0);
}

int 	key_hook(int keycode, t_env **env)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
