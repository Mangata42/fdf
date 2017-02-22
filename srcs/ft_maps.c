/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/22 15:13:41 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int 	ft_read_map(t_env **env, int fd)
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
	ft_check_map(env, tmp_map);
	// ft_draw_grind(env);
	t_coords *test;

	test = ft_copy_struct(&(*env)->coords);
	ft_print_struct(&test);
	free(tmp_map);
	return (0);
}

int		ft_check_map(t_env **env, char *tmp_map)
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
		(*env)->coords = ft_add_node(&(*env)->coords, x, y, ft_atoi(split_map[i]));
		if (ft_strchr(split_map[i], '\n') != NULL)
		{
			if (split_map[i + 1] == '\0')
				return ;
			x = 0;
			(*env)->coords = ft_add_node(&(*env)->coords, x, y, ft_atoi(split_map[i]));
			y++;
		}
		x++;
		i++;
	}
	free(split_map);
}
