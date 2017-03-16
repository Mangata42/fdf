/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:57:13 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/16 23:34:03 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_center(t_coords *coords)
{
	t_coords *tmp;

	tmp = coords;
	while (tmp)
	{
		tmp->x += 250;
		tmp->y += 250;
		tmp = tmp->next;
	}
}

void	ft_put_pixel(t_env **env, int pos)
{
	(*env)->img_datas[pos] = 0xFF;
	(*env)->img_datas[pos + 1] = 0xFF;
	(*env)->img_datas[pos + 2] = 0xFF;
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
	ft_center(coords);
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
	ft_center(coords);
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
	ft_center(coords);
	ft_horizontal_draw(env, coords);
}