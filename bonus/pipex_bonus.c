/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:37:26 by lwoo              #+#    #+#             */
/*   Updated: 2026/02/05 17:51:02 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	execute_cmd(char *param, char **env)
{
	char	**cmd;
	char	*path;

	if (!(*param) || !param)
		exit(126);
	cmd = ft_split(param, ' ');
	if ((!cmd || !(*cmd)))
	{
		perror("Command not found");
		exit(127);
	}
	path = get_path(cmd[0], env);
	execve(path, cmd, env);
	if (errno == ENOENT)
	{
		ft_putstr_fd("Command not found: ", STDERR_FILENO);
		ft_putendl_fd(cmd[0], STDERR_FILENO);
	}
	else
		perror("No such file or directory");
	free_memory(cmd);
	exit(127);
}

static void	do_fork(int i, int pfd[], int prev_fd, char **av)
{
	int	fd;

	if (i == 2)
	{
		fd = open_file(av[1], 0);
		dup2(fd, STDIN_FILENO);
		close(fd);
	}
	else
		dup2(prev_fd, STDIN_FILENO);
	if (av[i + 2] == NULL)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
			fd = open_file(av[i + 1], 2);
		else
			fd = open_file(av[i + 1], 1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
	}
	else
		dup2(pfd[1], STDOUT_FILENO);
	if (prev_fd != -1)
		close(prev_fd);
	close(pfd[0]);
	close(pfd[1]);
}

static int	do_pipe(int i, int ac, char **av, char **env)
{
	int	pfd[2];
	int	pid;
	int	prev_fd;
	int	status;

	prev_fd = -1;
	while (i < ac - 1)
	{
		if (pipe(pfd) == -1)
			format_exception_bonus(1);
		pid = fork();
		if (pid == -1)
			format_exception_bonus(2);
		if (pid == 0)
		{
			do_fork(i, pfd, prev_fd, av);
			execute_cmd(av[i], env);
		}
		close(pfd[1]);
		if (prev_fd != -1)
			close(prev_fd);
		prev_fd = pfd[0];
		i++;
	}
	return (waitpid(pid, &status, 0), status);
}

static void	here_doc(char *limiter)
{
	int		pid;
	int		pfd[2];
	char	*line;

	if (pipe(pfd) == -1)
		format_exception_bonus(1);
	pid = fork();
	if (pid == -1)
		format_exception_bonus(2);
	if (pid == 0)
	{
		close(pfd[0]);
		while (get_next_line(&line))
		{
			if (!ft_strncmp(line, limiter, ft_strlen(limiter)))
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			write(pfd[1], line, ft_strlen(line));
			free(line);
		}
	}
	close(pfd[1]);
	dup2(pfd[0], STDIN_FILENO);
}

int	main(int ac, char *av[], char **env)
{
	int	status;

	if (ac <= 5)
		format_exception_bonus(0);
	if (ft_strncmp(av[1], "here_doc", 8) == 0)
	{
		if (ac < 6)
			format_exception_bonus(0);
		else
		{
			here_doc(av[2]);
			status = do_pipe(3, ac, av, env);
		}
	}
	else
		status = do_pipe(2, ac, av, env);
	while (wait(NULL) > 0)
		;
	return (status / 256);
}
