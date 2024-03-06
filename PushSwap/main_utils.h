/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehammoud <ehammoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:46:16 by ehammoud          #+#    #+#             */
/*   Updated: 2024/02/20 15:54:14 by ehammoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_UTILS_H
# define MAIN_UTILS_H

# include <stdlib.h>
# include "extra_utils.h"
# include "string_utils.h"

int	valid_args(int c, char **s);
int	*parse_args(int *argc, char **argv);

#endif