# include "microshell.h"
void clear(t_cmd *cmd) {
	int i = 0;
	t_cmd *tmp;

	while (cmd)
	{
		i = 0;
		while(cmd->args[i]) {
			free(cmd->args[i]);
			i++;
		}
		free(cmd->args);
		tmp = cmd;
		cmd = cmd->next;
		free(tmp);
	}
}

t_cmd *create_cmd(t_cmd *tmp, char **av, int arg_num, int is_pipe) {
	t_cmd *new;
	int i = 0;

	if (!(new = malloc(sizeof(t_cmd))))
		exit_fatal();
	if (!(new->args = malloc(sizeof(char *) * arg_num)))
		exit_fatal();
	while (i < arg_num)
	{
		new->args[i] = ft_strdup(av[i]);
		i++;
	}
	new->args[i] = NULL;
	new->is_pipe = is_pipe;
	new->prev = tmp;
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	return (new);
}

void arg_pars(int ac, char **av, t_cmd *cmd) {
	t_cmd *tmp;
	int	start = 1;
	int	last = 1;
	int	is_pipe = 0;

	while (last < ac)
	{
		if (!strcmp(av[last], "|") || !strcmp(av[last], ";") || last + 1 == ac)
		{
			if (!strcmp(av[last], "|"))
				is_pipe = 1;
			else if (!strcmp(av[last], ";"))
				is_pipe = 0;
			else
			{
				is_pipe = 0;
				last++;
			}
			if (last != start)
			{
				tmp = create_cmd(tmp, av + start, last - start, is_pipe);
				if (!cmd)
					cmd = tmp;
			}
			start = last + 1;
		}
		last++;
	}
}

int ft_cd(t_cmd *cmd) {
	int i = 0;
	int res = 0;

	while (cmd->args[i])
		i++;
	if (i != 2) {
		ft_putstr("error: cd: bad arguments\n");
		return (1);
	}
	else if ((res = chdir(cmd->args[1])) < 0) {
		ft_putstr("error: cd: cannot change directory to ");
		ft_putstr(cmd->args[1]);
		ft_putstr("\n");
	}
	return (res);
}

int ft_nonbuiltin(t_cmd *cmd, char **env) {
	pid_t pid = 0;
	int	res = 0;

	if (cmd->is_pipe)
		if (pipe(cmd->fd) < 0)
			exit_fatal();
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if(pid == 0) {
		if (cmd->is_pipe && dup2(cmd->fd[1], 1) < 0)
			exit_fatal();
		if (cmd->is_pipe && cmd->prev && dup2(cmd->fd[0], 0) < 0)
			exit_fatal();
		if (execve(cmd->args[0], cmd->args, env) < 0) {
			ft_putstr("error: cannot execute ");
			ft_putstr(cmd->args[0]);
			ft_putstr("\n");
		}
	}
	else
		parent(cmd, pid);
	return (res);
}

int exec(t_cmd *cmd, char **env) {
	int res = 0;

	while(cmd) {
		if (strcmp(cmd->args[0], "cd"))
			res = ft_cd(cmd);
		else
			res = ft_nonbuiltin(cmd, env);
		cmd = cmd->next;
	}
	return (res);
}

int		main(int ac, char **av, char **env)
{
	t_cmd *cmd;
	int res = 0;

	arg_pars(ac, **av, cmd);
	res = exec(cmd, env);
	clear(cmd);
	return (res);
}
