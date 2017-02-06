/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:13:41 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/03 15:17:33 by nghaddar         ###   ########.fr       */
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

#define ERROR {ft_putstr("ERROR, exiting ..."); exit(EXIT_FAILURE);}

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
	char	*map;
}					t_env;

t_env				*init_env(void);

#endif
