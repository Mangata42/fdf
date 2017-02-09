#include "../includes/fdf.h"

void	ft_error_handler(int error_code)
{
	if (error_code == 0)
		ft_putendl("Malloc error");
	else if (error_code == 1)
		ft_putendl("Can't open fd");
	else if (error_code == 2)
		ft_putendl("Can't read on fd");
	else
		ft_putendl("Unknown error");
	ft_putendl("Exiting ...");
	exit(EXIT_FAILURE);
}