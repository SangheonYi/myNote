# ifndef MINI_PAINT_H
# define MINI_PAINT_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <string.h>

typedef struct 	s_bg
{
	int w;
	int h;
	char c;
}				t_bg;

typedef struct 	s_sh
{
	char type;
	float r;
	float cen_x;
	float cen_y;
	char c;
}				t_sh;

# endif
