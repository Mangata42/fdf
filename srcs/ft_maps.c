#include "../includes/fdf.h"

int 	ft_read_map(int fd, t_env *env)
{
	char	*line;
	char	*tmp_map;
	int 	ret;

	line = NULL;
	tmp_map = NULL;
	ret = 42;
	while (ret > 0)
	{
		if (ret == -1)
			ft_error_handler(2);
		ret = get_next_line(fd, &line);
		tmp_map = ft_strjoin(tmp_map, line);
		tmp_map = ft_strjoin(tmp_map, "\n");
		free(line);
	}
	return (0);
}
