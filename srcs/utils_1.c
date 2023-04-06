/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:59:13 by fpereira          #+#    #+#             */
/*   Updated: 2023/03/15 15:08:40 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	exit_process(int i, t_list **a)
{
	if (i)
		write(STDERR_FILENO, "Error\n", 6);
	free_list(a);
	exit(i);
}

void	is_nbr(char *s, t_list **a)
{
	while (*s == ' ' || (*s > 8 && *s < 14))
		s++;
	if (*s == '+' || *s == '-')
		s++;
	if (*s < '0' || *s > '9')
		exit_process(1, a);
	while (*s >= '0' && *s <= '9')
		s++;
	if (*s != ' ' && (*s <= 8 || *s >= 14) && *s)
		exit_process(1, a);
}

long	ft_atoi_ps(char **str)
{
	long long	num;
	int			minus;

	num = 0;
	minus = 1;
	if (**str == '-' || **str == '+')
	{
		if (**str == '-')
			minus *= -1;
		*str += 1;
	}
	while (**str >= '0' && **str <= '9')
	{
		num = (num * 10 + (minus * (**str - '0')));
		if (num > INT_MAX || num < INT_MIN)
			exit_process(1, &minmaxlist()->next);
		*str += 1;
	}
	while (**str == ' ' || (**str > 8 && **str < 14))
		*str += 1;
	if (**str && (**str > 8 && **str < 14) && (**str != ' '))
		exit_process(1, &minmaxlist()->next);
	return (num);
}

void	parser(char **argv, t_list **a)
{
	int		i;
	long	num;
	char	*str;

	i = 0;
	while (argv[++i] && argv)
	{
		str = argv[i];
		if (!*str)
			exit_process(1, a);
		while (*str)
		{
			while (*str == ' ')
				str++;
			is_nbr(str, a);
			num = ft_atoi_ps(&str);
			add_content(a, num);
		}
	}
}

void	add_content(t_list **a, int num)
{
	t_list	*temp;

	temp = malloc(sizeof(t_list));
	if (!temp)
		return ;
	temp->data = num;
	temp->next = NULL;
	temp->index = -1;
	ft_lstadd_back(a, temp);
}
