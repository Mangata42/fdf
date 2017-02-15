/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nghaddar <nghaddar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/13 14:18:40 by nghaddar          #+#    #+#             */
/*   Updated: 2017/02/14 17:38:41 by Mangata          ###   ########.fr       */
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
	else
		ft_putendl("Unknown error");
	ft_putendl("Exiting ...");
	exit(EXIT_FAILURE);
}

/*
	Error Code 
		0/ Unknown error
		1/ General Malloc error
		2/ fd is invalid - can't open
		3/ Can't read on fd
		4/ Empty file
		5/ Forbbiden symbol in file
*/