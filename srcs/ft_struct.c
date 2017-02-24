/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/24 19:16:06 by nghaddar         ###   ########.fr       */
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
	env->i_x = 0;
	env->i_y = 0;
	env->win = mlx_new_window(env->mlx, W_X, W_Y, "fdf.c");
	env->img = mlx_new_image(env->mlx, W_X, W_Y);
	env->img_datas = mlx_get_data_addr(env->img, &(env->bpp), &(env->sl), 
	 		&(env->end));
	env->step = 10;
	env->view = 1;
	if (!env->mlx || !env->win || !env->img)
		return (NULL);
	return (env);
}

void	ft_add_node(t_coords **coords, int x, int y, int z)
{
	t_coords	*new_node;
	t_coords	*tmp;

	new_node = (t_coords *)malloc(sizeof(t_coords));
	new_node->x = x;
	new_node->y = y;
	new_node->z = z;
	new_node->next = NULL;
	if (*coords == NULL)
		*coords = new_node;
	else
	{
		tmp = *coords;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_node;
	}
}

t_coords	*ft_copy_struct(t_coords *to_copy)
{
	t_coords	*new_struct;

	new_struct = NULL;
	while (to_copy != NULL)
	{
		ft_add_node(&new_struct, to_copy->x, to_copy->y, to_copy->z);
		to_copy = to_copy->next;
	}
	return (new_struct);
}

void	ft_free_struct(t_coords **to_del)
{
	t_coords *tmp;

	while ((*to_del) != NULL)
	{
		tmp = (*to_del);
		(*to_del) = (*to_del)->next;
		free(tmp);
	}
	(*to_del) = NULL;
	to_del = NULL;
}

void	ft_print_struct(t_coords *coords)
{
	t_coords	*to_print;

	to_print = coords;
	while (to_print != NULL)
	{
		printf("x = %d, y = %d, z = %d\n", to_print->x, to_print->y, to_print->z);
		to_print = to_print->next;
	}
	printf("NULL\n");
}