/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:13:41 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/22 15:10:33 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./libft.h"
# include "./mlx.h"

# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define W_X 1000
# define W_Y 1000

typedef	struct 			s_coords
{
	int 			x;
	int 			y;
	int 			z;
	struct s_coords *next;	
}						t_coords;

typedef	struct 			s_env
{
	t_coords	*coords;
	void		*mlx;
	void		*win;
	void		*img;
	int			w_x;
	int			w_y;
	char		*img_datas;
	char		**map;
	int			bpp; //bits per pixel = 32
	int			sl;  //size line = w_x * (bpp / 8)
	int			end; //endian
	int 		step; //zoom
}						t_env;

void				ft_error_handler(int error_code);
int 				key_hook(int keycode, t_env **env);
int 				expose_hook(t_env **env);
int 				ft_read_map(t_env **env, int fd);
int 				ft_check_map(t_env **env, char *tmp_map);
void				ft_store_map(t_env **env, char **split_map);
t_coords			*ft_add_node(t_coords **coords, int x, int y, int z);
t_coords			*ft_copy_struct(t_coords *to_copy);
void				ft_print_struct(t_coords **coords);
void				ft_free_struct(t_coords **coords);
void				ft_put_pixel(t_env **env, int pos, void *color);
void				ft_draw_grind(t_env **env);
t_env				*init_env(void);

#endif
