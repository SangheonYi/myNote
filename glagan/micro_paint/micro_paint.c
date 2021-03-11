# include "micro_paint.h"

int ft_strlen(char *str) {
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

int str_error(char *str) {
	write(1, str, ft_strlen(str));
	return (1);
}

void draw_img(t_bg bg, char *img) {
	int i = 0;

	while (i < bg.h)
	{
		write(1, img + i * bg.w, bg.w);
		write(1, "\n", 1);
		i++;
	}
}

char is_inside(float x, float y, t_sh sh) {
	if (sh.y > y || sh.x > x ||
	sh.y + sh.h < y || sh.x + sh.w < x)
		return (0);
	if (x - sh.x < 1. || (sh.x + sh.w) - x < 1. ||
	y - sh.y < 1. || (sh.y + sh.h) - y < 1.)
		return ('r');
	return ('R');
}

void fill_shape(t_bg bg, t_sh sh, char *img) {
	int y = 0;
	int x = 0;
	int is_in = 0;

	while (y < bg.h)
	{
		x = 0;
		while (x < bg.w)
		{
			is_in = is_inside(x, y, sh);
			if ((sh.type == 'r' && is_in == 'r') ||
			(sh.type == 'R' && is_in))
				img[y * bg.w + x] = sh.c;
			x++;
		}
		y++;
	}
}

int read_n_fill(FILE *file, t_bg bg, char *img) {

	int read = 0;
	t_sh sh;

	while ((read = fscanf(file, "%c %f %f %f %f %c\n",
	 &sh.type, &sh.x, &sh.y, &sh.w, &sh.h, &sh.c)) && read == 6)
	{
		if (!(sh.w > 0 && sh.h > 0) || (sh.type != 'r' && sh.type != 'R'))
			return (1);
		fill_shape(bg, sh, img);
	}
	if (read != -1)
		return (1);
	return (0);
}

int main(int argc, char *argv[]) {
	FILE *file;
	t_bg bg;
	char *img;

	if (argc != 2)
		return (str_error("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (str_error("Error: Operation file corrupted\n"));
	if (fscanf(file, "%d %d %c\n", &bg.w, &bg.h, &bg.c) != 3)
		return (str_error("Error: Operation file corrupted\n"));
	if (!(0 < bg.w && bg.w <= 300 && 0 < bg.h && bg.h <= 300))
		return (str_error("Error: Operation file corrupted\n"));
	img = malloc(sizeof(char) * bg.w * bg.h);
	memset(img, bg.c, bg.w * bg.h);
	if (read_n_fill(file, bg, img)) {
		free(img);
		return (str_error("Error: Operation file corrupted\n"));
	}
	draw_img(bg, img);
	free(img);
	return (0);
}
