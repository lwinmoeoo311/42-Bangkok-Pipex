/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lwoo <lwoo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/02 20:57:32 by lwoo              #+#    #+#             */
/*   Updated: 2026/01/03 23:11:10 by lwoo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
	return (NULL);
}

static char	*get_full_path(char *path, char *pgm)
{
	char	*path_with_slash;
	char	*full_path;

	path_with_slash = ft_strjoin((const char *)path, "/");
	full_path = ft_strjoin((const char *)path_with_slash, pgm);
	free(path_with_slash);
	return (full_path);
}

static void	get_access_error(int err, char *cmd)
{
	if (err == EACCES)
		perror(cmd);
	else if (err == ENOTDIR)
		perror(cmd);
	else if (err == ENOENT)
		perror(cmd);
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
	while (path_dir && path_dir[i])
	{
		full_path = get_full_path(path_dir[i], pgm_cmd[0]);
		if (access(full_path, F_OK | X_OK | R_OK) == 0)
			return (full_path);
		free(full_path);
		i++;
	}
	free_memory(path_dir);
	free_memory(pgm_cmd);
	if (path == NULL && !ft_strnstr(cmd, "/", ft_strlen(cmd)))
		exit (127);
	get_access_error(errno, cmd);
	return (cmd);
}
