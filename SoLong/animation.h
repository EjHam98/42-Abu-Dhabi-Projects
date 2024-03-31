/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:19:45 by ehammoud          #+#    #+#             */
/*   Updated: 2024/03/26 20:03:32 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMATION_H
# define ANIMATION_H

# include "structs.h"
# include <stdlib.h>
# include "extra_utils.h"
# include "mlx.h"
# include "hook_handles.h"

void	check_textures(t_map *g, t_tex t);
void	get_cd_tex(t_map *g);
int		handle_keys(int keycode, t_map *g);
void	free_textures(t_map g);

#endif