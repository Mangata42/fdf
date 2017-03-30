/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:13:41 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/28 21:17:17 by nghaddar         ###   ########.fr       */
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

# define W_X 750
# define W_Y 750

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
# define K_Q 12
# define K_W 13

typedef	struct		s_draw
{
	int				dx;
	int				sx;
	int				dy;
	int				sy;
	int				err;
	int				e2;
}					t_draw;

typedef	struct		s_coords
{
	int				x;
	int				y;
	int				z;
	int				col;
	struct s_coords	*next;
}					t_coords;

typedef	struct		s_env
{
	t_coords		*coords;
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_datas;
	int				bpp;
	int				sl;
	int				end;
	int				x_max;
	int				y_max;
	int				step;
	int				view;
	int				x_pos;
	int				y_pos;
	int				height;
}					t_env;

void				ft_error_handler(int error_code);
int					key_hook(int keycode, t_env **env);
int					expose_hook(t_env **env);
int					ft_read_map(t_env **env, int fd);
void				ft_verify_line(char *line);
void				ft_add_node(t_coords **coords, int x, int y, int z);
t_coords			*ft_move_node(t_coords *coords, int pos);
t_coords			*ft_copy_struct(t_coords *to_copy);
void				ft_print_struct(t_coords *coords);
void				ft_put_pixel(t_env **env, int pos, unsigned int color);
void				ft_print_grind(t_env **env, t_coords *coords);
void				ft_manage_view(t_env **env);
void				ft_std_view(t_env **env, t_coords *coords);
void				ft_iso_view(t_env **env, t_coords *coords);
void				ft_paral_view(t_env **env, t_coords *coords);
void				ft_con_view(t_env **env, t_coords *coords);
void				ft_draw_grind(t_env **env);
void				ft_line(t_env **env, t_coords a, t_coords b);
t_env				*init_env(void);
void				ft_horizontal_draw(t_env **env, t_coords *coords);
void				ft_vertical_draw(t_env **env, t_coords *coords);
void				ft_screen_pos(t_env **env, t_coords *coords);
void				ft_manage_mov(t_env **env, int keycode);
void				ft_manage_height(t_env **env, int keycode);
int					mouse_hook(int button, int x, int y, t_env **env);
void				ft_change_view(t_env **env, int keycode);

#endif
