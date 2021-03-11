#include "mini_paint.h"

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

int is_inside(float x, float y, t_sh sh) {
	float dist = sqrtf((x - sh.cen_x) * (x - sh.cen_x)
	+ (y - sh.cen_y) * (y - sh.cen_y) );

	if (dist < sh.r) {
		if (sh.r - dist < 1.)
			return (2);
		return (1);
	}
	return (0);
}

void fill_shape(char *img, t_bg bg, t_sh sh) {
	int x = 0;
	int y = 0;
	int is_in = 0;

	while (y < bg.h) {
		x = 0;
		while (x < bg.w) {
			is_in = is_inside(x, y, sh);
			if ((sh.type == 'c' && is_in == 2)
			|| (sh.type == 'C' && is_in))
				img[y * bg.w + x] = sh.c;
			x++;
		}
		y++;
	}
}

int read_n_fill(char *img, t_bg bg, FILE *file) {
	t_sh sh;
	int read = 0;

	while ((read = fscanf(file, "%c %f %f %f %c\n", &sh.type, &sh.cen_x,& sh.cen_y, &sh.r, &sh.c)) && read == 5) {
		if (sh.r <= 0 || (sh.type != 'c' && sh.type != 'C'))
			return (1);
		fill_shape(img, bg, sh);
	}
	if (read != -1)
	{
		printf("??\n");
		return (1);
	}
	return (0);
}

void draw_shape(char *img, t_bg bg) {
	int i = 0;

	while (i < bg.h) {
		write(1, img + i * bg.w, bg.w);
		write(1, "\n", 1);
		i++;
	}
}

int main(int argc, char *argv[]) {
	FILE *file;
	t_bg bg;
	char *img;

	if (argc != 2)
		return (str_error("Error: argument\n"));
	if (!(file = fopen(argv[1], "r")))
		return (str_error("Error: Operation file corrupted1\n"));
	if (fscanf(file, "%d %d %c\n", &bg.w, &bg.h, &bg.c) != 3)
		return (str_error("Error: Operation file corrupted2\n"));
	if (!(0 < bg.w && bg.w <= 300 && 0 < bg.h && bg.h <= 300))
		return (str_error("Error: Operation file corrupted3\n"));
	img = malloc(sizeof(char) * bg.w * bg.h);
	memset(img, bg.c, bg.h * bg.w);
	if (read_n_fill(img, bg, file)) {
		free(img);
		return (str_error("Error: Operation file corrupted4\n"));
	}
	draw_shape(img, bg);
	free(img);
	fclose(file);
	return (0);
}
