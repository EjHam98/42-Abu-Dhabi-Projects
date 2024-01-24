/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PipeX.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 18:49:24 by codespace         #+#    #+#             */
/*   Updated: 2024/01/15 12:30:15 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PipeX.h"

char	*get_path(char **env)
{
	int	n;

	n = 0;
	while (env[n] && ft_strncmp(env[n], "PATH", 4))
		n++;
	if (!env[n])
	{
		ft_print("Error: Couldn't find PATH variable in environment.", 2);
		exit (EXIT_FAILURE);
	}
	return (env[n] + 5);
		
}

char	*find_cmd(char *path, char *cmd)
{
	int		i;
	char	*s;
	char	**paths;

	paths = ft_split(path, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		s = ft_strjoin(paths[i], cmd, 1);
		if (!access(s, F_OK | X_OK))
		{
			free(paths);
			return (s);
		}
		free(s);
		i++;
	}
	free(paths);
	return (ft_substr(cmd, 0, ft_strlen(cmd)));
}

void	execute(char *cmd, char *path, char **env)
{
	char	*c;
	char	**args;

	args = ft_split(cmd, ' ');
	c = find_cmd(path, args[0]);
	if (execve(c, args, env))
	{
		free(c);
		free(args);
		ft_print("mybash: command not found: ", 0);
		ft_print(cmd, 2);
		exit (127);
	}
}

void	handle(char **a, int n, char *p, char **env)
{
	int		s2;
	int		status;
	int		fds[2];
	int		tf;
	int		i;
	pid_t	pid;
	pid_t	tmp;

	i = 1;
	while (i < n - 1)
	{
		if (i == n - 2)
		{
			tf = open(a[n - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
			if (tf < 0)
				perror(a[n - 1]);
			if (dup2(tf, STDOUT_FILENO) < 0)
				exit (EXIT_FAILURE);
		}
		pipe(fds);
		pid = fork();
		if (!pid)
		{
			close(fds[0]);
			if (i == 1)
			{
				tf = open(a[0], O_RDONLY);
				if (tf < 0)
					perror(a[0]);
				if (dup2(tf, STDIN_FILENO) < 0)
					exit(EXIT_FAILURE);
				close(tf);
			}
			else
			{
				if (i != n - 2 && dup2(fds[1], STDOUT_FILENO) < 0)
					exit(EXIT_FAILURE);
				close(fds[1]);
			}
			execute(a[i], p, env);
		}
		else
		{
			close(fds[1]);
			if (dup2(fds[0], STDIN_FILENO) < 0)
				exit(EXIT_FAILURE);
			close(fds[0]);
		}
		tf = 0;
		i++;
	}
	s2 = 0;
	tmp = pid + 1;
	while (tmp > 0)
	{
		tmp = wait(&status);
		if (WIFEXITED(status) && tmp == pid)
			s2 = WEXITSTATUS(status);
	}
	exit (s2);
}