/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:57:13 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/24 16:10:30 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Vue isométrique, parallèle et conique */

void	ft_put_pixel(t_env **env, int pos, void *color_val)
{
	char	*col;

	col = color_val;
	(*env)->img_datas[pos] = col[0];
	(*env)->img_datas[pos + 1] = col[1];
	(*env)->img_datas[pos + 2] = col[2];
	(*env)->img_datas[pos + 3] = 0;
}

void	ft_std_view(t_env **env, t_coords *coords)
{
	int	white;
	int color;
	int	pos;

	white = 0xFFFFFF;
	while (coords != NULL)
	{
		color = white - (coords->z) * 100;
		pos = ((coords->y * (*env)->sl) * 10 + (coords->x * 4) * 10);
		ft_put_pixel(env, pos, &color);
		coords = coords->next;
	}	
}

void	ft_draw_grind(t_env	**env)
{
	t_coords *to_draw;
	int 	white;
	int		pos;

	to_draw = (*env)->coords;
	white = 0xFFFFFF;
	while (to_draw != NULL)
	{
		pos = ((to_draw->y) * (*env)->sl) + ((to_draw->x) * 4);
		ft_put_pixel(env, pos, &white);
		to_draw = to_draw->next;
	}
	expose_hook(env);
}