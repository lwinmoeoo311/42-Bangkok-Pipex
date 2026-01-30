/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 18:52:03 by lwoo              #+#    #+#             */
/*   Updated: 2026/01/30 12:54:49 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	format_exception_bonus(int flag)
{
	if (flag == 0)
	{
		ft_putstr_fd("Command structure is not in format", 1);
		exit(EXIT_SUCCESS);
	}
	else if (flag == 1)
	{
		perror("PIPE: ");
		exit(EXIT_FAILURE);
	}
	else if (flag == 2)
	{
		perror("FORK: ");
		exit(EXIT_FAILURE);
	}
	else if (flag == 3)
	{
		perror("FILE DESCRIPTER: ");
		exit(EXIT_FAILURE);
	}
}

int	open_file(char *file, int flag)
{
	int	fd;

	fd = -1;
	if (flag == 0)
		fd = open(file, O_RDONLY);
	else if (flag == 1)
		fd = open(file, O_TRUNC | O_WRONLY | O_CREAT, 0644);
	else if (flag == 2)
		fd = open(file, O_APPEND | O_WRONLY | O_CREAT, 0644);
	if (fd == -1)
		format_exception_bonus(3);
	return (fd);
}

char	*get_next_line(char **line)
{
	char	*buffer;
	char	c;
	int		byte;
	int		i;

	buffer = (char *)malloc(100000);
	byte = read(0, &c, 1);
	i = 0;
	while (byte && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		byte = read(0, &c, 1);
	}
	buffer[i++] = '\n';
	buffer[i] = '\0';
	*line = buffer;
	return (*line);
}

void	free_memory(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}
