# ifndef MICRO_PAINT_H
# define MICRO_PAINT_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

	// 배경
	typedef struct	s_back_ground
	{
		int		b_width;
		int		b_height;
		char	b_char;
	}				t_bg;

	// 도형
		typedef struct	s_shape
	{
		char	type;
		float	start_x;
		float	start_y;
		float	width;
		float	height;
		char	c_char;
	}				t_shape;

# endif
