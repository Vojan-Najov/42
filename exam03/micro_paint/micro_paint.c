#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#define ERROR 1

static const char	g_arg_err[] = "Error: argument\n";
static const char	g_file_err[] = "Error: Operation file corrupted\n";

typedef struct s_zone
{
	int		width;
	int		height;
	char	bg;
}			t_zone;

typedef struct s_rectangle
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	fg;
}			t_rectangle;

static char	*get_zone(FILE *file, t_zone *zone);

static int	draw_rectangle(FILE *file, char *matrix, t_zone *zone);

static void	fill_matrix(char *matrix, t_zone *zone, t_rectangle *rect);

static void	print_result(char *matrix, t_zone *zone);

int	main(int argc, char **argv)
{
	FILE	*file;
	t_zone	zone;
	char	*matrix;
	int		ret;

	if (argc != 2)
	{
		write(STDOUT_FILENO, g_arg_err, sizeof(g_arg_err) - 1);
		return (ERROR);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		write(STDOUT_FILENO, g_file_err, sizeof(g_file_err) - 1);
		return (ERROR);
	}
	matrix = get_zone(file, &zone);
	if (!matrix)
	{
		fclose(file);
		write(STDOUT_FILENO, g_file_err, sizeof(g_file_err) - 1);
		return (ERROR);
	}
	ret = draw_rectangle(file, matrix, &zone);
	if (ret)
	{
		fclose(file);
		free(matrix);
		write(STDOUT_FILENO, g_file_err, sizeof(g_file_err) - 1);
		return (ERROR);
	}
	print_result(matrix, &zone);
	fclose(file);
	free(matrix);
	return (0);
}

static char	*get_zone(FILE *file, t_zone *zone)
{
	char	*matrix;
	int		ret;

	ret = fscanf(file, "%d %d %c\n", &zone->width, &zone->height, &zone->bg);
	if (ret != 3)
		return (NULL);
	if (zone->width <= 0 || zone->width > 300)
		return (NULL);
	if (zone->height <= 0 || zone->height > 300)
		return (NULL);
	matrix = (char *) malloc(sizeof(char) * zone->width * zone->height);
	if (!matrix)
		return (NULL);
	memset(matrix, zone->bg, zone->width * zone->height);
	return (matrix);
}

static int	draw_rectangle(FILE *file, char *matrix, t_zone *zone)
{
	int			ret;
	t_rectangle	rect;

	ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, \
												&rect.width, &rect.height, &rect.fg);
	while (ret == 6)
	{
	if (rect.type != 'r' && rect.type != 'R')
		return (ERROR);
	if (rect.width <= 0 || rect.height <= 0)
		return (ERROR);
	fill_matrix(matrix, zone, &rect);
	ret = fscanf(file, "%c %f %f %f %f %c\n", &rect.type, &rect.x, &rect.y, \
												&rect.width, &rect.height, &rect.fg);
	}
	if (ret != EOF)
		return (ERROR);
	return (0);
}

static void	fill_matrix(char *matrix, t_zone *zone, t_rectangle *rect)
{
	int		x;
	float	fx;
	int		y;
	float	fy;

	y = -1;
	while (++y < zone->height)
	{
		x = -1;
		while (++x < zone->width)
		{
			fx = (float) x;
			fy = (float) y;
			if ((fx - rect->x < 0.) || (rect->x + rect->width - fx < 0.))
				continue ;
			if ((fy - rect->y < 0.) || (rect->y + rect->height - fy < 0.))
				continue ;
			if (rect->type == 'R')
			{
				matrix[y * zone->width + x] = rect->fg;
				continue ;
			}
			if ((fx - rect->x - 1. < 0.) || (rect->x + rect->width - fx - 1. < 0.) || \
				(fy - rect->y - 1. < 0.) || (rect->y + rect->height -fy - 1. < 0.))
					matrix[y * zone->width + x] = rect->fg;
		}
	}
}

static void	print_result(char *matrix, t_zone *zone)
{
	int	d;
	int	i;

	d = 0;
	i = -1;
	while (++i < zone->height)
	{
		write(STDOUT_FILENO, matrix + d, zone->width);
		write(STDOUT_FILENO, "\n", 1);
		d += zone->width;
	}
}
