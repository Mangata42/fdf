/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:57:13 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/30 17:25:42 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_screen_pos(t_env **env, t_coords *coords)
{
	t_coords *tmp;

	tmp = coords;
	while (tmp)
	{
		tmp->x += (*env)->x_pos;
		tmp->y += (*env)->y_pos;
		tmp = tmp->next;
	}
}

void	ft_put_pixel(t_env **env, int pos, unsigned int color)
{
	unsigned int mask;

	color = 0x00FF00;
	mask = 0xFF & color;
	(*env)->img_datas[pos] = mask;
	mask = 0xFF & (color >> 8);
	(*env)->img_datas[pos + 1] = mask;
	mask = 0xFF & (color >> 16);
	(*env)->img_datas[pos + 2] = mask;
	mask = 0xFF & (color >> 24);
	(*env)->img_datas[pos + 3] = 0;
}

void	ft_std_view(t_env **env, t_coords *coords)
{
	t_coords *tmp;

	tmp = coords;
	while (tmp != NULL)
	{
		if (tmp->z != 0)
			tmp->z += (*env)->height;
		tmp->x = (tmp->x) * (*env)->step;
		tmp->y = (tmp->y - tmp->z) * (*env)->step;
		tmp = tmp->next;
	}
	ft_screen_pos(env, coords);
	ft_horizontal_draw(env, coords);
	ft_free_struct(coords);
}

void	ft_iso_view(t_env **env, t_coords *coords)
{
	t_coords	*tmp;
	int			posx;
	int			posy;

	tmp = coords;
	while (tmp != NULL)
	{
		if (tmp->z != 0)
			tmp->z += (*env)->height;
		posx = (tmp->x - tmp->y) * (*env)->step;
		posy = (tmp->x + tmp->y - tmp->z) * (*env)->step / 2;
		tmp->x = posx;
		tmp->y = posy;
		tmp = tmp->next;
	}
	ft_screen_pos(env, coords);
	ft_horizontal_draw(env, coords);
	ft_free_struct(coords);
}

void	ft_paral_view(t_env **env, t_coords *coords)
{
	t_coords	*tmp;
	int			posx;
	int			posy;

	tmp = coords;
	while (tmp != NULL)
	{
		if (tmp->z != 0)
			tmp->z += (*env)->height;
		posx = (tmp->x - tmp->y) * (*env)->step;
		posy = (tmp->x + tmp->y - tmp->z) * (*env)->step;
		tmp->x = posx;
		tmp->y = posy;
		tmp = tmp->next;
	}
	ft_screen_pos(env, coords);
	ft_horizontal_draw(env, coords);
	ft_free_struct(coords);
}
