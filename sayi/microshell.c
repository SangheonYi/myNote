# include "microshell.h"

int		ft_strlen(char *s) {
	int i= 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s) {
	write(2, s, ft_strlen(s));
}

int		exit_fatal() {
	ft_putstr("error: fatal\n");
	exit(1);
}

char	*ft_strdup(char *str) {
	int i = 0;
	char *p;

	if (!(p = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		exit_fatal();
	while(str[i]) {
		p[i] = str[i];
		i++;
	}
	p[i] = str[i];
	return (p);
}

void	clear(t_cmd *cmd) {
	t_cmd *tmp;
	int i = 0;

	while (cmd) {
		i = 0;
		while (cmd->args[i])
		{
			free(cmd->args[i]);
			i++;
		}
		free(cmd->args);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
}

