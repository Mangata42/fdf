/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/22 14:51:58 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int argc, char **argv)
{
	t_env	*env;
	int 	fd;

	if (argc != 2)
		ft_error_handler(6);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		ft_error_handler(2);
	if (!(env = init_env()))
		ft_error_handler(0);
	if ((ft_read_map(&env, fd)) == -1)
		ft_error_handler(3);
	mlx_key_hook(env->win, key_hook, &env);
	mlx_expose_hook(env->win, expose_hook, &env);
	mlx_loop(env->mlx);
	ft_free_struct(&(env)->coords);
	free(env);
	return (0);
}