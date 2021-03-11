cshell : main.c prompt.c builtin.c ls.c redir_pipe.c command.c overkill.c
	gcc -g main.c prompt.c builtin.c ls.c redir_pipe.c command.c overkill.c