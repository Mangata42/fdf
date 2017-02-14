/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/14 15:27:04 by Mangata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// int		ft_check_map(char *tmp_map)
// {
// 	char	**split_map;

// 	split_map = ft_strsplit(tmp_map, ' ');
// 	while (split_map)
// 	{
// 		while (*split_map)
// 		{
// 			if (ft_isdigit(**split_map) == 0 && **split_map != '\n')
// 				ft_error_handler(4);
// 			*split_map++;
// 		}
// 		split_map++;
// 	}
// 	return (0);
// }

int 	ft_read_map(int fd, t_env **env)
{
	char	*line;
	char	*tmp_map;
	int 	ret;

	ret = 42;
	tmp_map = (char *)malloc(1); //useful to realloc
	while (ret > 0)
	{
		if (ret == -1)
			ft_error_handler(2);
		ret = get_next_line(fd, &line);
		tmp_map = ft_realloc((void **)&tmp_map, ft_strlen(line) + 3);
		tmp_map = ft_strcat(tmp_map, line);
		tmp_map = ft_strcat(tmp_map, "\n");
		free(line);
	}
	// ft_check_map(tmp_map);
	free(tmp_map);
	return (0);
}
