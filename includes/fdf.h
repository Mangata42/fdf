/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:13:41 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/15 21:41:10 by nghaddar         ###   ########.fr       */
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

typedef	struct 		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		w_x;
	int		w_y;
	char	*img_datas;
	char	**map;
	int		bpp; //bits per pixel = 32
	int		sl;  //size line = w_x * (bpp / 8)
	int		end; //endian
	int 	step; //zoom
}					t_env;

void				ft_error_handler(int error_code);
int 				key_hook(int keycode, t_env **env);
int 				expose_hook(t_env **env);
int 				ft_read_map(int fd, t_env **env);
int 				ft_check_map(char *tmp_map, t_env **env);
t_env				*init_env(void);

#endif
