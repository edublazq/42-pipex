42 Madrid - Pipex
valgrind --track-fds=yes --trace-children=yes

PRIMER PROCESO
		dup2(fd_pipe[1], STDOUT_FILENO);
		dup2(pipex->fd[0], STDIN_FILENO);
SEGUNDO PROCESO
		dup2(fd_pipe[0], STDIN_FILENO);
		dup2(pipex->fd[1], STDOUT_FILENO);