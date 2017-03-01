/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/22 10:57:13 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/01 17:40:16 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* Vue isométrique, parallèle et conique */


void	ft_print_grind(t_env **env, t_coords *coords)
{
	int color;

	while (coords != NULL)
	{
		color = 0xFFFFFF - (coords->z * 10000);
		ft_put_pixel(env, coords->x + coords->y, &color);
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
		tmp->x = (tmp->x * 4) * (*env)->step;
		tmp->y = ((tmp->y) * (*env)->sl) * (*env)->step; 
		tmp = tmp->next;
	}
	ft_print_struct(coords);
}

void	ft_iso_view(t_env **env, t_coords *coords)
{
	t_coords *tmp;

	tmp = coords;
	while (tmp != NULL)
	{
		tmp->x = ft_abs(((tmp->x * 4) - (tmp->y) * 5));
		tmp->y = ft_abs(((tmp->y) + (tmp->x * 4) * 5));
		tmp = tmp->next;
	}
	ft_print_struct(coords);
}	

// void	ft_con_view(t_env **env, t_coords *coords)
// {
// 	t_coords *tmp;

// 	tmp = coords;
// 	while (tmp != NULL)
// 	{
// 		tmp->x = ((tmp->x * 4) - (tmp->y)) * 5;
// 		tmp->y = ((tmp->y) + (tmp->x * 4)) * 5; 
// 		tmp = tmp->next;
// 	}
// 	ft_print_grind(env, coords);
// }

// void	ft_paral_view(t_env **env, t_coords *coords)
// {
// 	t_coords *tmp;

// 	tmp = coords;
// 	while (tmp != NULL)
// 	{
// 		tmp->x = (tmp->x * 4) * (*env)->step;
// 		tmp->y = ((tmp->y) * (*env)->sl) * (*env)->step; 
// 		tmp = tmp->next;
// 	}
// 	ft_print_grind(env, coords);
// }