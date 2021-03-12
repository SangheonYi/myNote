# include "microshell.h"

int	ft_strlen(char *str) {
	int i = 0;

	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(2, s, ft_strlen(s));
}

void	exit_fatal()
{
	ft_putstr("error fatal\n");
	exit(1);
}

char	*ft_strdup(char *s)
{
	int	i = 0;
	char *p;
	if (!(p = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		exit_fatal();
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}
