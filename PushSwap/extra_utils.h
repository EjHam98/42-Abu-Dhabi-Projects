/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   extra_utils.h									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: codespace <codespace@student.42.fr>		+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/01/25 16:50:17 by codespace		 #+#	#+#			 */
/*   Updated: 2024/01/26 08:12:27 by codespace		###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef EXTRA_UTILS_H
# define EXTRA_UTILS_H

# include <stdlib.h>
# include <limits.h>
# include "stacks.h"

char	**ft_split(char *s, char sep);
void	n_rotations(t_stack **s, int n1, t_stack **h, int n2);
int		stack_end(t_stack *s);
void	get_min_max(t_stack *s, int *min, int *max);
t_stack	*make_stack(int *arr, int size);
int		has_dups(int *arr, int c);

#endif