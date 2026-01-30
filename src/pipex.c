/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:56:31 by lwoo              #+#    #+#             */
/*   Updated: 2026/01/28 16:45:21 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	execute_cmd(char *param, char **env)
{
	char	**cmd;
	char	*path;

	if (!(*param) || !param)
		exit(126);
	cmd = ft_split(param, ' ');
	if (!cmd || !(*cmd))
	{
		ft_putstr_fd("Command not found\n", STDERR_FILENO);
		exit(127);
	}
	path = get_path(cmd[0], env);
	execve(path, cmd, env);
	ft_putstr_fd("Command not found: ", STDERR_FILENO);
	ft_putendl_fd(cmd[0], STDERR_FILENO);
	free_memory(cmd);
	exit(127);
}

static void	first_child_process(char **param, int *p_fd, char **env)
{
	int	fd;

	fd = open(param[1], O_RDONLY);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(fd, STDIN_FILENO);
	dup2(p_fd[1], STDOUT_FILENO);
	close(p_fd[0]);
	execute_cmd(param[2], env);
}

static void	second_child_process(char **param, int *p_fd, char **env)
{
	int	fd;

	fd = open(param[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fd == -1)
		exit(EXIT_FAILURE);
	dup2(fd, STDOUT_FILENO);
	dup2(p_fd[0], STDIN_FILENO);
	close(p_fd[1]);
	execute_cmd(param[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid1;
	pid_t	pid2;
	int		status;

	if (ac != 5)
	{
		format_exception();
		exit(0);
	}
	if (pipe(p_fd) == -1)
		exit(1);
	pid1 = fork();
	if (pid1 == 0)
		first_child_process(av, p_fd, env);
	pid2 = fork();
	if (pid2 == 0)
		second_child_process(av, p_fd, env);
	close(p_fd[0]);
	close(p_fd[1]);
	waitpid(pid1, &status, 0);
	waitpid(pid2, &status, 0);
	return (status / 256);
}
