/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 16:56:31 by lwoo              #+#    #+#             */
/*   Updated: 2025/12/12 15:35:58 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	execute_cmd(char *param, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(param, ' ');
	path = get_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("Command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_memory (cmd);
		exit(0);
	}
}

static void	child_process(char **param, int *p_fd, char **env)
{
	int	fd;

	fd = open(param[1], O_RDONLY);
	if (fd == -1)
		exit(0);
	dup2(fd, 0);
	dup2(p_fd[1], 1);
	close(p_fd[0]);
	execute_cmd(param[2], env);
}

static void	parent_process(char **param, int *p_fd, char **env)
{
	int	fd;

	fd = open(param[4], O_WRONLY | O_TRUNC | O_CREAT, 07777);
	if (fd == -1)
		exit(0);
	dup2(fd, 1);
	dup2(p_fd[0], 0);
	close(p_fd[1]);
	execute_cmd(param[3], env);
}

int	main(int ac, char **av, char **env)
{
	int		p_fd[2];
	pid_t	pid;

	if (ac != 5)
		format_exception();
	if (pipe(p_fd) == -1)
		exit(1);
	pid = fork();
	if (!pid)
		child_process(av, p_fd, env);
	waitpid(pid, NULL, 0);
	parent_process(av, p_fd, env);
	return (0);
}
