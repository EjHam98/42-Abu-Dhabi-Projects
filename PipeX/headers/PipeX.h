/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PipeX.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:07:30 by codespace         #+#    #+#             */
/*   Updated: 2024/01/11 16:42:11 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
#define PIPEX_H

# include "Utils.h"
# include "Split.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>

char	*get_path(char **env);
void	handle(char **a, int n, char *p, char **env);

#endif