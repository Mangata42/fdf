/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/16 18:11:06 by Mangata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_put_pixel(t_env **env, int pos, void *color_val)
{
	char	*col;

	col = color_val;
	(*env)->img_datas[pos] = col[0];
	(*env)->img_datas[pos + 1] = col[1];
	(*env)->img_datas[pos + 2] = col[2];
	(*env)->img_datas[pos + 3] = 0;
}

void	ft_draw_grind(t_env	**env)
{
	t_coords *to_draw;
	int		white;
	int		blue;
	int		pos;

	to_draw = (*env)->coords;
	white = 0xFFFFFF;
	blue = 0x0000FF;
	while (to_draw != NULL)
	{
		pos = ((to_draw->y) * 2000) + ((to_draw->x) * 4);
		if (to_draw->z == 0)
			ft_put_pixel(env, pos, &white);
		else
			ft_put_pixel(env, pos, &blue);
		to_draw = to_draw->next;
	}
	expose_hook(env);
}

void	ft_store_map(t_env **env, char **split_map)
{
	int	x;
	int	y;
	int	i;

	i = 0;
	x = 0;
	y = 0;
	while (split_map[i] != '\0')
	{
		ft_add_node(env, x, y, ft_atoi(split_map[i]));
		x++;
		if (ft_strchr(split_map[i], '\n') != NULL)
		{
			x = 0;
			y++;
		}
		i++;
	}
}

int		ft_check_map(char *tmp_map, t_env **env)
{
	char	**split_map;
	int		x;
	int		y;

	if (ft_strlen(tmp_map) <= 1)
		ft_error_handler(4);
	split_map = ft_strsplit(tmp_map, ' ');
	y = -1;
	while (split_map[++y])
	{
		x = -1;
		while (split_map[y][++x])
		{
			if (ft_isdigit(split_map[y][x]) == 0 && split_map[y][x] != '\n'
					&& split_map[y][x] != '-')
	 			ft_error_handler(5);
		}
	}
	ft_store_map(env, split_map);
	return (0);
}

int 	ft_read_map(int fd, t_env **env)
{
	char	*line;
	char	*tmp_map;
	int 	ret;

	ret = 42;
	tmp_map = (char *)malloc(1); //useful to realloc
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			ft_error_handler(2);
		tmp_map = ft_realloc((void **)&tmp_map, ft_strlen(line) + 3);
		tmp_map = ft_strcat(tmp_map, line);
		tmp_map = ft_strcat(tmp_map, "\n");
		free(line);
	}
	ft_check_map(tmp_map, env);
	ft_draw_grind(env);
	free(tmp_map);
	return (0);
}
