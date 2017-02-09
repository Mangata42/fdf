/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:28:17 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/09 02:40:46 by Mangata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env	*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->mlx = mlx_init();
	env->w_x = 500;
	env->w_y = 500;
	env->win = mlx_new_window(env->mlx, env->w_x, env->w_y, "pr0nhub.exe");
	env->img = mlx_new_image(env->mlx, env->w_x, env->w_y);
	env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl), 
	 		&(env->end));
	if (!env->mlx || !env->win || !env->img)
		return (NULL);
	return (env);
}