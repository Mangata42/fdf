/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bres.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 21:15:20 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/16 23:34:24 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_line(t_env **env, t_coords a, t_coords b)
{
	t_draw line;

 	line.dx = ft_abs(b.x - a.x);
 	line.sx = a.x < b.x ? 1 : -1;
 	line.dy = ft_abs(b.y - a.y);
 	line.sy = a.y < b.y ? 1 : -1;
 	line.err = (line.dx > line.dy ? line.dx : -(line.dy)) / 2;
	while (1)
	{
		if ((a.x < W_X && a.y < W_Y) && (a.x > 0 && a.y > 0))
			ft_put_pixel(env, (a.x * 4) + (a.y * (*env)->sl));
		if (a.x == b.x && a.y == b.y)
			break ;
		line.e2 = line.err;
	    if (line.e2 > -(line.dx)) 
	    {
	    	line.err -= line.dy;
	    	a.x += line.sx;
	    }
	    if (line.e2 < line.dy) 
	    {
	    	line.err += line.dx; 
	    	a.y += line.sy; 
	    }
	}
}

void	ft_vertical_draw(t_env **env, t_coords *coords)
{
	t_coords *tmp;

	while (ft_move_node(coords, (*env)->x_max + 1) != NULL)
	{
		tmp = ft_move_node(coords, (*env)->x_max + 1);
		ft_line(env, *coords, *tmp);
		coords = coords->next;
	}
}

void	ft_horizontal_draw(t_env **env, t_coords *coords)
{
	int i;
	t_coords *tmp;

	i = 0;
	tmp = coords;
	while (tmp->next != NULL)
	{
		if (i == (*env)->x_max)
		{
			tmp = tmp->next;
			i = 0;
		}
		ft_line(env, *tmp, *(tmp->next));
		tmp = tmp->next;
		i++;
	}
	ft_vertical_draw(env, coords);
}