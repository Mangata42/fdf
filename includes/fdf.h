/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:13:41 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/16 21:31:57 by nghaddar         ###   ########.fr       */
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

# define K_1 18
# define K_2 19
# define K_3 20
# define K_ESC 53
# define K_UP 126
# define K_DOWN 125
# define K_RIGHT 124
# define K_LEFT 123
# define K_MIN 27
# define K_MAX 24

typedef	struct 			s_draw
{
	int dx;
	int sx;
	int dy;
	int sy;
	int err;
	int e2;
}						t_draw;

typedef	struct 			s_coords
{
	int 			x;
	int 			y;
	int 			z;
	int             col;
	struct s_coords *next;	
}						t_coords;

typedef	struct 			s_env
{
	t_coords	*coords;
	void		*mlx;
	void		*win;
	void		*img;
	int 		x_max;
	int 		y_max;
	char		*img_datas;
	char		**map;
	int			bpp; //bits per pixel = 32
	int			sl;  //size line = w_x * (bpp / 8)
	int			end; //endian
	int 		step;
	int 		view;
}						t_env;

void				ft_error_handler(int error_code);
int 				key_hook(int keycode, t_env **env);
int 				expose_hook(t_env **env);
int 				ft_read_map(t_env **env, int fd);
int 				ft_check_map(t_env **env, char *tmp_map);
void				ft_store_map(t_env **env, char **split_map);
void				ft_add_node(t_coords **coords, int x, int y, int z);
t_coords			*ft_move_node(t_coords *coords, int pos);
t_coords			*ft_copy_struct(t_coords *to_copy);
void				ft_print_struct(t_coords *coords);
void				ft_free_struct(t_coords **coords);
void				ft_put_pixel(t_env **env, int pos);
void				ft_print_grind(t_env **env, t_coords *coords);
void				ft_manage_view(t_env **env);
void				ft_std_view(t_env **env, t_coords *coords);
void				ft_iso_view(t_env **env, t_coords *coords);
void 				ft_paral_view(t_env **env, t_coords *coords);
void				ft_con_view(t_env **env, t_coords *coords);
void				ft_draw_grind(t_env **env);
void				ft_line(t_env **env, t_coords a, t_coords b);
t_env				*init_env(void);

void  				ft_horizontal_draw(t_env **env, t_coords *coords);
void				ft_vertical_draw(t_env **env, t_coords *coords);

#endif
