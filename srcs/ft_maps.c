/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/28 21:39:48 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_verify_line(char *line);

int		ft_read_map(t_env **env, int fd)
{
	char *line;
	char **tmp;
	int x;
	int y;

	x = -1;
	y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		tmp = ft_strsplit(line, ' ');
		while (*tmp)
		{
			ft_verify_line(*tmp);
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

void		ft_verify_line(char *line)
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