/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:27:02 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/09 02:28:50 by Mangata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_env	*env;
	int 	fd;

	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error_handler(1);
	if (!(env = init_env()))
		ft_error_handler(0);
	if ((ft_read_map(fd, env)) == -1)
		ft_error_handler(2);
	mlx_key_hook(env->win, key_hook, env);
	mlx_loop(env->mlx);
	return (0);
}