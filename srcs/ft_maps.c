/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/30 17:45:47 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_test_ret(int ret)
{
	if (ret < 0)
		ft_error_handler(3);
	if (ret == 0)
		return (0);
	return (1);
}

int		ft_read_map(t_env **env, int fd)
{
	char	*line;
	char	**tmp;
	int		x;
	int		y;

	x = -1;
	y = 0;
	while (ft_test_ret(get_next_line(fd, &line)) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		ft_verify_line(line);
		while (*tmp)
		{
			ft_add_node(&(*env)->coords, ++x, y, ft_atoi(*tmp));
			tmp++;
		}
		(*env)->x_max = x;
		x = -1;
		y++;
		free(line);
	}
	(*env)->y_max = y - 1;
	ft_manage_view(env);
	return (0);
}

void	ft_verify_line(char *line)
{
	int i;

	i = -1;
	while (line[++i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0 && line[i] != '\n'
			&& line[i] != '-' && line[i] != ' ')
			ft_error_handler(5);
	}
}
