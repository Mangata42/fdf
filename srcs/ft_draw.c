/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:57:13 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/28 14:31:29 by nghaddar         ###   ########.fr       */
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

void	ft_iso_view(t_env **env, t_coords *coords)
{
	;
}	

void	ft_con_view(t_env **env, t_coords *coords)
{
	;
}

void	ft_paral_view(t_env **env, t_coords *coords)
{
	int pos;
	int posx;
	int posy;
	int color;

	while (coords != NULL)
	{
		color = 0xFFFFFF;
		posx = (coords->x - coords->y) * ((*env)->step) / 2;
		posy = (coords->x + coords->y) * ((*env)->step) / 2;
		pos = (posy * (*env)->sl) + (posx * 4);
		ft_put_pixel(env, pos, &color);
		coords = coords->next;
	}
}