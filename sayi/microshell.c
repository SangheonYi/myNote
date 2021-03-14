#include "microshell.h"
# ifdef TEST_SH
# define TEST 1
# else
# define TEST 0
#endif
int		ft_strlen(char *s)
{
	int	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	write(2, s, ft_strlen(s));
	exit(1);
}

void	exit_fatal()
{
	ft_putstr("error: fatal\n");
	exit(1);
}

char	*ft_strdup(char *s)
{
	int		i = 0;
	char	*p;

	if (!(p = malloc(sizeof(char) * (ft_strlen(s) + 1))))
		exit_fatal();
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = s[i];
	return (p);
}

void	clear(t_cmd *cmd)
{
	int		i = 0;
	t_cmd	*tmp;

	while (cmd)
	{
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

t_cmd	*create_cmd(t_cmd *tmp, char *av[], int argnum, int is_pipe)
{
	t_cmd	*new;
	int		i = 0;

	if (!(new = malloc(sizeof(t_cmd))))
		exit_fatal();
	if (!(new->args = malloc(sizeof(char *) * (argnum + 1))))
		exit_fatal();
	while (i < argnum)
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

int		ft_cd(t_cmd *cmd)
{
	int	res = 0;
	int	i = 0;

	while (cmd->args[i])
		i++;
	if (i != 2)
	{
		ft_putstr("error: cd: bad arguments\n");
		return(1);
	}
	else if ((res = chdir(cmd->args[1])) < 0)
	{
		ft_putstr("error: cd: cannot change directory to ");
		ft_putstr(cmd->args[1]);
		ft_putstr("\n");
	}
	return (res);
}

int		ft_non_builtin(t_cmd *cmd, char **env)
{
	pid_t	pid;
	int		res = 0;
	int		status = 0;
	
	if (cmd->is_pipe)
		if (pipe(cmd->fd) < 0)
			exit_fatal();
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
		if (cmd->is_pipe && dup2(cmd->fd[1], 1) < 0)
			exit_fatal();
		if (cmd->prev && cmd->prev->is_pipe && dup2(cmd->prev->fd[0], 0) < 0)
			exit_fatal();
		if ((res = execve(cmd->args[0], cmd->args, env)) < 0)
		{
			ft_putstr("error: cannot execute ");
			ft_putstr(cmd->args[0]);
			ft_putstr("\n");
		}
		exit(res);
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			res = WEXITSTATUS(status);
		if (cmd->is_pipe)
		{
			close(cmd->fd[1]);
			if (!cmd->next)
				close(cmd->fd[0]);
		}
		if (cmd->prev && cmd->prev->is_pipe)
			close(cmd->prev->fd[0]);
	}
	return (res);
}


int		exec(t_cmd *cmd, char **env)
{
	int	res = 0;

	while (cmd)
	{
		if (!strcmp(cmd->args[0], "cd"))
			res = ft_cd(cmd);
		else
			res = ft_non_builtin(cmd, env);
		cmd = cmd->next;
	}
	return (res);
}


int		main(int ac, char *av[], char **env)
{
	t_cmd	*tmp;
	t_cmd	*cmd;
	int		is_pipe = 0;
	int		res = 0;
	int		start = 1;
	int		last = 1;

	while (last < ac)
	{
		if (!strcmp("|", av[last]) || !strcmp(";", av[last]) || last + 1 == ac)
		{
			if (!strcmp("|", av[last]))
				is_pipe = 1;
			else if (!strcmp(";", av[last]))
				is_pipe = 0;
			else
			{
				is_pipe = 0;
				last++;
			}
			if (start != last)
			{
				tmp = create_cmd(tmp, av + start, last - start, is_pipe);
				if (!cmd)
					cmd = tmp;
			}
			start = last + 1;
		}
		last++;
	}
	res = exec(cmd, env);
	clear(cmd);
	while(TEST);
	return (res);
}
