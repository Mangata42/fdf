/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/03/30 16:17:03 by nghaddar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_error_handler(int error_code)
{
	if (error_code == 1)
		ft_putendl("Malloc error");
	else if (error_code == 2)
		ft_putendl("Can't open fd");
	else if (error_code == 3)
		ft_putendl("Can't read on fd");
	else if (error_code == 4)
		ft_putendl("Empty file");
	else if (error_code == 5)
		ft_putendl("Forbidden symbol in input");
	else if (error_code == 6)
		ft_putendl("usage: ./fdf source_file");
	else
		ft_putendl("Unknown error");
	ft_putendl("Exiting ...");
	exit(EXIT_FAILURE);
}
