# ifndef MICROSHELL_H
# define MICROSHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

typedef	struct		s_cmd
{
	char **args;
	int		fd[2];
	int		is_pipe;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}					t_cmd;

# endif