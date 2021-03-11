# ifndef MINI_PAINT_H
# define MINI_PAINT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>

	typedef struct	s_back_ground
	{
		int		b_width;
		int		b_height;
		char	b_char;
	}				t_bg;

	typedef struct	s_shape
	{
		char	type;
		float	center_x;
		float	center_y;
		float	r;
		char	c_char;
		float	distance;
	}				t_shape;

# endif
