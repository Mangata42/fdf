/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:57:13 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/02 17:59:47 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Vue isométrique et parallèle*/

void	ft_print_grind(t_env **env, t_coords *coords)
{
	int pos;
	int centerx;
	int	centery;
	int color = 0xFFFFFF;

	centerx = 150;
	centery = 150;
	while (coords != NULL)
	{
		pos = (coords->y * (*env)->sl) + (coords->x * 4);
		pos += (centery * (*env)->sl + centerx * 4);
		if ((coords->y + centery >= 0 && coords->y + centery <= W_Y) &&
				coords->x + centerx >= 0 && coords->x + centerx <= W_X)
			ft_put_pixel(env, pos, &color);
		coords = coords->next;
	}
}

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
	t_coords *tmp;

	tmp = coords;
	while (tmp != NULL)
	{
		tmp->x = (tmp->x) * (*env)->step;
		tmp->y = (tmp->y - tmp->z) * (*env)->step; 
		tmp = tmp->next;
	}
	ft_horizontal_draw(env, coords);
}

void	ft_iso_view(t_env **env, t_coords *coords)
{
	t_coords *tmp;
	int	posx;
	int posy;

	tmp = coords;
	while (tmp != NULL)
	{
		posx = (tmp->x - tmp->y) * (*env)->step;
		posy = (tmp->x + tmp->y - tmp->z) * (*env)->step / 2; 
		tmp->x = posx;
		tmp->y = posy;
		tmp = tmp->next;
	}
	ft_horizontal_draw(env, coords);
}	

void	ft_paral_view(t_env **env, t_coords *coords)
{
	t_coords *tmp;
	int	posx;
	int posy;

	tmp = coords;
	while (tmp != NULL)
	{
		posx = (tmp->x - tmp->y) * (*env)->step;
		posy = (tmp->x + tmp->y - tmp->z) * (*env)->step;
		tmp->x = posx;
		tmp->y = posy;
		tmp = tmp->next;
	}
	ft_horizontal_draw(env, coords);
}