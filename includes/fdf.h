/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:13:41 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/14 18:33:30 by Mangata          ###   ########.fr       */
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

typedef	struct 		s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		w_x;
	int		w_y;
	char	*img_datas;
	int		bpp; //bits per pixel = 3
	int		sl;  //size line = w_x * bpp
	int		end;
}					t_env;

void				ft_error_handler(int error_code);
int 				key_hook(int keycode, t_env *env);
int 				expose_hook(t_env *env);
int 				loop_hook(t_env *env);
int 				ft_read_map(int fd, t_env **env);
t_env				*init_env(void);

#endif
