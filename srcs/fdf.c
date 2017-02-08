/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:27:02 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/03 15:27:27 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int 	key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int 	ft_read_map(int fd, t_env *env)
{
	char	*line;

	line = NULL;
	while ((get_next_line(fd, &line)) > 0)
	{
		env->map = ft_strjoin(env->map, line);
		env->map = ft_strjoin(env->map, "\n");
		free(line);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	t_env	*env;
	int 	fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (-1);
	env = init_env();
	ft_read_map(fd, env);
	ft_putstr(env->map);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}