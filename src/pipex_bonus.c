/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 20:37:26 by lwoo              #+#    #+#             */
/*   Updated: 2025/12/18 17:47:11 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	open_file(char *file, int flag)
{
	int	fd;

	if (flag == 0)
		fd = open(file, O_RDONLY);
	else
		fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		exit (EXIT_FAILURE);
	return (fd);
}

static void	do_pipe(int ac, char **av, char **env)
{
	pid_t	pid;
	int		p_fd[2];
	int		i;
	int		fd;

	i = 2;
	while (i < ac - 1)
	{
		if (pipe(p_fd) == -1)
			exit (EXIT_FAILURE);
		pid = fork();
		if (!pid)
		{
			
		}
	}
}

int	main(int ac, char *av[], char **env)
{
	if (ac <= 5)
		format_exception_bonus();
	if (ft_strncmp(av[1], "here_doc", 8) != 0)
	{
		do_pipe(ac, av, env);
	}
	return (0);
}
