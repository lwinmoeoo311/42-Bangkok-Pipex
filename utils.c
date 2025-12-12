/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 13:36:05 by lwoo              #+#    #+#             */
/*   Updated: 2025/12/12 15:18:23 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	format_exception(void)
{
	ft_putstr_fd("Command structure is not in format", 1);
	exit(0);
}

void	free_memory(char **cmd)
{
	size_t	i;

	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

static char	*get_pathenv(char **env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (env[i])
	{
		if ((ft_strncmp(env[i], "PATH", 4) == 0))
		{
			while (env[i][j] && env[i][j] != '=')
				j++;
			return (env[i] + j + 1);
		}
		i++;
	}
	return (0);
}

static char	*get_full_path(char *path, char *pgm)
{
	char	*path_with_slash;
	char	*full_path;

	path_with_slash = ft_strjoin((const char *)path, "/");
	full_path = ft_strjoin((const char *)path_with_slash, pgm);
	free (path_with_slash);
	return (full_path);
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	*path;
	char	*full_path;
	char	**path_dir;
	char	**pgm_cmd;

	i = 0;
	path = get_pathenv(env);
	path_dir = ft_split(path, ':');
	pgm_cmd = ft_split(cmd, ' ');
	while (path_dir[i])
	{
		full_path = get_full_path(path_dir[i], pgm_cmd[0]);
		if (access(full_path, F_OK | X_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	free_memory(path_dir);
	free_memory(pgm_cmd);
	return (cmd);
}
