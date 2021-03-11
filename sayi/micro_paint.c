#include "micro_paint.h"

int     ft_strlen(char *str)
{
    int     i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}

int     str_error(char *str)
{
    write(1, str, ft_strlen(str));
    return (1);
}

void write_img(t_bg bg, char *image) {
    int i = 0;

    while (i < bg.b_height)
    {
        write(1, image + i * bg.b_width, bg.b_width);
        write(1, "\n", 1);
        i++;
    }
}

int is_inside(float x, float y, t_shape sh) {
    if (x < sh.start_x || x > sh.start_x + sh.width ||
        y < sh.start_y || y > sh.start_y + sh.height)
        return (0);
    if (x - sh.start_x < 1. || (sh.start_x + sh.width) - x < 1. ||
        y - sh.start_y < 1. || (sh.start_y + sh.height) - y < 1.)
        return (2);
    return(1);
}

void fill_shape(t_bg bg, t_shape sh, char* image) {
    int y = 0;
    int x = 0;
    int is_in = 0;

    while (y < bg.b_height)
    {
        x = 0;
        while (x < bg.b_width)
        {
            is_in = is_inside(x, y, sh);
            if ((sh.type == 'r' && is_in == 2)
            || (sh.type == 'R' && is_in))
                image[y * bg.b_width + x] = sh.c_char;
            x++;
        }
        y++;
    }
}

int read_n_fill(FILE *file, char *image, t_bg bg)
{
    int     read;
    t_shape sh;

    while ((read = fscanf(file, "%c %f %f %f %f %c\n",
     &sh.type, &sh.start_x, &sh.start_y, &sh.width, &sh.height, &sh.c_char))
     && read == 6)
    {
        if (!(sh.width > 0 && sh.height > 0) || !(sh.type == 'R' || sh.type == 'r'))
            return (1);
        fill_shape(bg, sh, image);
    }
    if (read != -1)
		return (1);
    return (0);
}

int     main(int argc, char *argv[])
{
    FILE    *file;
    char    *image;
    t_bg    bg;

    if (argc != 2)
        return (str_error("Error: argument\n"));
    if (!(file = fopen(argv[1], "r")))
        return (str_error("Error: Operation file corrupted\n"));
    if (fscanf(file, "%d %d %c\n", &bg.b_width, &bg.b_height, &bg.b_char) != 3)
        return (str_error("Error: Operation file corrupted\n"));
    if (!(bg.b_width > 0 && bg.b_width <= 300 && bg.b_height > 0 && bg.b_height <= 300))
        return (str_error("Error: Operation file corrupted\n"));
    image = (char*)malloc(sizeof(char) * (bg.b_width * bg.b_height));
    memset(image, bg.b_char, bg.b_width * bg.b_height);
    if (read_n_fill(file, image, bg))
    {
		free(image);
        return (str_error("Error: Operation file corrupted\n"));
    }
    write_img(bg, image);
    free(image);
    fclose(file);
    return (0);
}

