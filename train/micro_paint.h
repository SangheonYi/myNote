# ifndef MY_H
# define MY_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <string.h>

typedef struct	s_bg
{
	int w;
	int h;
	char c;
}				t_bg;

typedef struct	s_sh
{
	char type;
	float x;
	float y;
	float w;
	float h;
	char c;
}				t_sh;

# endif
