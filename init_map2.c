#include "fdf.h"


int count_x(char *str)
{
	int x;
	int fd;
	char *line;
	char **value;

	x = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	value = ft_split(line, ' ');
	while (value[x])
		x++;
	x = -1;
	while (value[++x])
		free(value[x]);
	free(line);
	free(value);
	close(fd);
	return (x);
}

int count_y(char *str)
{
	int fd;
	int y;
	char *line;

	y = 0;
	fd = open(str, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		y += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (y);
}
