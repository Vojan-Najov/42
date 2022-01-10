#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <math.h>

#define ERROR 1

static const char	g_arg_err[] = "Error: argument\n";
static const char	g_file_err[] = "Error: Operation file corrupted\n";

typedef struct s_zone
{
	int		width;
	int		height;
	char	bg;
}			t_zone;

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	r;
	char	fg;
}			t_circle;

static char	*get_zone(FILE *file, t_zone *zone);

static int	draw_circle(FILE *file, char *matrix, t_zone *zone);

static void	fill_matrix(char *matrix, t_zone *zone, t_circle *cl);

static void	print_result(char *matrix, t_zone *zone);

int	main(int argc, char **argv)
{
	FILE	*file;
	t_zone	zone;
	char	*matrix;
	int		ret;

	if (argc != 2)
	{
		write(STDOUT_FILENO, g_arg_err, sizeof(g_arg_err));
		return (ERROR);
	}
	file = fopen(argv[1], "r");
	if (!file)
	{
		write(STDOUT_FILENO, g_file_err, sizeof(g_file_err));
		return (ERROR);
	}
	matrix = get_zone(file, &zone);
	if (!matrix)
	{
		fclose(file);
		write(STDOUT_FILENO, g_file_err, sizeof(g_file_err));
		return (ERROR);
	}	
	ret = draw_circle(file, matrix, &zone);
	if (ret)
	{
		free(matrix);
		fclose(file);
		write(STDOUT_FILENO, g_file_err, sizeof(g_file_err));
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
	if (zone->width < 0 || zone->width > 300)
		return (NULL);
	if (zone->height < 0 || zone->height > 300)
		return (NULL);
	matrix = (char *) malloc(sizeof(char) * zone->width * zone->height);
	if (!matrix)
		return (NULL);
	memset(matrix, zone->bg, zone->width * zone->height);
	return (matrix);
}

static int	draw_circle(FILE *file, char *matrix, t_zone *zone)
{
	int			ret;
	t_circle	cl;

	ret = fscanf(file, "%c %f %f %f %c\n", &cl.type, &cl.x, &cl.y, &cl.r, &cl.fg);
	while (ret == 5)
	{
		if (cl.type != 'c' && cl.type != 'C')
			return (ERROR);
		if (cl.r <= 0.)
			return (ERROR);
		fill_matrix(matrix, zone, &cl);
		ret = fscanf(file, "%c %f %f %f %c\n", &cl.type, &cl.x, &cl.y, &cl.r, &cl.fg);
	}
	if (ret != EOF)
		return (ERROR);
	return (0);
}

static void	fill_matrix(char *matrix, t_zone *zone, t_circle *cl)
{
	int		x;
	int		y;
	float	fx;
	float	fy;
	float	r2;

	y = -1;
	while (++y < zone->height)
	{
		x = -1;
		while (++x < zone->width)
		{
			fx = (float) x;
			fy = (float) y;
			r2 = powf(fx - cl->x, 2.) + powf(fy - cl->y, 2.);
			if (r2 - powf(cl->r, 2.) > 0.)
				continue ;
			if (cl->type == 'C')
			{
				matrix[y * zone->width + x] = cl->fg;
				continue ;
			}
			if (cl->r - sqrtf(r2) - 1. < 0.)
				matrix[y * zone->width + x] = cl->fg;
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
