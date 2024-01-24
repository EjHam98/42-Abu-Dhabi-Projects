#include "stacks.h"

int	valid_args(int c, char **s)
{
	int	i;
	int	j;

	if (c < 2)
		return (0);
	i = 0;
	while (++i < c)
	{
		j = (s[i][0] == '-' || s[i][0] == '+');
		if (s[i][j] == '\0')
			return (0);
		while (s[i][j] >= '0' && s[i][j] <= '9')
			j++;
		if (s[i][j] != '\0' || j == 0)
			return (0);
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int				sign;
	unsigned long	lm_l;
	unsigned long	lm_r;
	unsigned long	n;

	if (!str)
		return (INT_MIN);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	sign = 1 - 2 * (str[0] == '-');
	str += (str[0] == '-' || str[0] == '+');
	n = 0;
	lm_l = LONG_MAX / 10;
	lm_r = LONG_MAX % 10;
	while (*str >= '0' && *str <= '9')
	{
		if (n > lm_l || (n == lm_r && (*str - 48ul) == lm_r))
			return (-1 * (sign != -1));
		n = n * 10 + (*str - 48);
		str++;
	}
	return (n * sign);
}

int	*parse_args(int argc, char **argv)
{
	int	i;
	int	*arr;

	arr = malloc(sizeof(int) * (argc - 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (++i < argc)
		arr[i - 1] = ft_atoi(argv[i]);
	return (arr);
}

t_stack	*make_stack(int *arr, int size)
{
	t_stack	*stack;
	int		i;

	stack = NULL;
	i = -1;
	while (++i < size)
		push(&stack, new_node(arr[i]));
	return stack;
}