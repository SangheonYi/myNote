# ifndef MICROSHELL_H
# define MICROSHELL_H
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/wait.h>

typedef	struct			s_cmd
{
	char				**args;
	int					is_pipe;
	int					fd[2];
	struct	s_cmd		*prev;
	struct	s_cmd		*next;
}						t_cmd;

# endif
