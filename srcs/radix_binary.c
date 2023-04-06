/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_binary.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:03:33 by fpereira          #+#    #+#             */
/*   Updated: 2023/03/07 15:45:21 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_max(t_list *a)
{
	minmaxlist()->max = INT_MIN;
	while (a)
	{
		if (minmaxlist()->max < a->index)
			minmaxlist()->max = a->index;
		a = a->next;
	}
}

int	max_bits(t_list **a)
{
	int	i;

	i = 0;
	find_max(*a);
	while (minmaxlist()->max != 0 && ++i)
		minmaxlist()->max = minmaxlist()->max >> 1;
	return (i);
}

void	radix_binary(t_list **a, t_list **b)
{
	t_list	*tmp;
	int		i;
	int		maxbits;
	int		len;
	int		j;

	len = ft_lstsize(*a);
	i = -1;
	number_index(a);
	maxbits = max_bits(a);
	while (++i < maxbits)
	{
		j = -1;
		while (++j < len)
		{
			tmp = *a;
			if ((tmp->index >> i & 1) == 1)
				rotate(a, 1);
			else
				push(b, a, 2);
		}
		while (ft_lstsize(*b) != 0)
			push(a, b, 1);
	}	
}

void	number_index(t_list **a)
{
	int		min;
	t_list	*tmp;
	int		i;
	int		len;

	i = -1;
	len = ft_lstsize(*a);
	while (++i < len)
	{
		min = INT_MAX;
		tmp = *a;
		while (tmp)
		{
			if (min > tmp->data && tmp->index == -1)
				min = tmp->data;
			tmp = tmp->next;
		}
		tmp = *a;
		while (min != tmp->data)
			tmp = tmp->next;
		tmp->index = i;
	}
}
