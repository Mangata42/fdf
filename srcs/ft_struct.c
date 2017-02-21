/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/16 18:00:47 by Mangata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_env	*init_env(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (NULL);
	env->coords = NULL;
	env->mlx = mlx_init();
	env->w_x = W_X;
	env->w_y = W_Y;
	env->win = mlx_new_window(env->mlx, env->w_x, env->w_y, "fdf.c");
	env->img = mlx_new_image(env->mlx, env->w_x, env->w_y);
	env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl), 
	 		&(env->end));
	env->step = 10;
	if (!env->mlx || !env->win || !env->img)
		return (NULL);
	return (env);
}

void	ft_add_node(t_env **env, int x, int y, int z)
{
	t_coords	*new_node;
	t_coords	*tmp;

	new_node = (t_coords *)malloc(sizeof(t_coords));
	tmp = (*env)->coords;
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->next = NULL;
	if ((*env)->coords == NULL)
		(*env)->coords = new_node;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	tmp->next = new_node;
	}
}

void	ft_print_struct(t_env **env)
{
	t_coords	*to_print;

	to_print = (*env)->coords;
	while (to_print != NULL)
	{
		printf("x = %d, y = %d, z = %d\n", to_print->x, to_print->y, to_print->z);
		to_print = to_print->next;
	}
	printf("NULL\n");
}