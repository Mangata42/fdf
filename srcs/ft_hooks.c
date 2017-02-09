#include "../includes/fdf.h"

int 	key_hook(int keycode, t_env *env)
{
	if (keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}
