/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/15 23:37:30 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_draw_grind(t_env	**env)
{
	int	x = 0;
	int	y = 0;
	int	i = -1;
	int	white = 0xFFFFFF;
	int	green = 0x00FF00;

	while ((*env)->map[++i] != '\0')
	{
		if (ft_atoi((*env)->map[i]) != 0)
		{
			(*env)->img_datas = ft_memcpy((*env)->img_datas + 
				((y * 4000) + (x * 4)), &white, 4);
		}
		x++;
	}
	expose_hook(env);
}

int		ft_check_map(char *tmp_map, t_env **env)
{
	char	**split_map;
	int		x;
	int		y;

	if (ft_strlen(tmp_map) <= 1)
		ft_error_handler(4);
	split_map = ft_strsplit(tmp_map, ' ');
	x = -1;
	while (split_map[++x])
	{
		y = -1;
		while (split_map[x][++y])
		{
			if (ft_isdigit(split_map[x][y]) == 0 && split_map[x][y] != '\n'
					&& split_map[x][y] != '-')
	 			ft_error_handler(5);
		}
	}
	(*env)->map = split_map;
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
	for (int i = 0; (*env)->map[i] != '\0'; i++)
		ft_putstr((*env)->map[i]);
	// ft_draw_grind(env);
	free(tmp_map);
	return (0);
}
