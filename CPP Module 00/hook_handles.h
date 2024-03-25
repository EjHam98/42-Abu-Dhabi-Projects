/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_handles.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 20:09:17 by ehammoud          #+#    #+#             */
/*   Updated: 2024/01/29 14:37:45 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_HANDLES_H
# define HOOK_HANDLES_H

# include "structs.h"
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include "render_utils.h"

int	free_up(t_map *game, int msg, int ex);
int	animations(t_map *game);
int	expose_hook(t_map *game);

#endif