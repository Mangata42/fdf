#include "../includes/fdf.h"

void	ft_line(t_env **env, t_coords a, t_coords b)
{
	t_draw line;

	a.x += 150;
	a.y += 150;
	b.x += 150;
	b.y += 150;
 	line.dx = abs(b.x - a.x);
 	line.sx = a.x < b.x ? 1 : -1;
 	line.dy = abs(b.y - a.y);
 	line.sy = a.y < b.y ? 1 : -1;
 	line.err = (line.dx > line.dy ? line.dx : -(line.dy)) / 2;
	while (1)
	{
		a.col = 0xFFFFFF;
		ft_put_pixel(env, (a.x * 4) + (a.y * (*env)->sl), &(a.col));
		if (a.x == b.x && a.y == b.y)
			break;
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

t_coords	*asked_pos(t_coords *coords, int pos)
{
	t_coords *tmp;

	tmp = coords;
	for (int i = 0; i < pos; i++)
		tmp = tmp->next;
	return (tmp);
}

void	ft_vertical_draw(t_env **env, t_coords *coords)
{
	int origin;
	int pos;
	t_coords *tmp;

	origin = 150;
	while (asked_pos(coords, (*env)->x_max + 1) != NULL)
	{
		tmp = asked_pos(coords, (*env)->x_max + 1);
		ft_line(env, *coords, *tmp);
		coords = coords->next;
	}

}

void	ft_horizontal_draw(t_env **env, t_coords *coords)
{
	int origin;
	int pos;
	int i;
	t_coords *tmp;

	origin = 150;
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