/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 13:01:46 by fpereira          #+#    #+#             */
/*   Updated: 2023/03/15 13:45:49 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	find_min_max(t_list *a)
{
	minmaxlist()->min = INT_MAX;
	minmaxlist()->max = INT_MIN;
	while (a)
	{
		if (minmaxlist()->min > a->data)
			minmaxlist()->min = a->data;
		if (minmaxlist()->max < a->data)
			minmaxlist()->max = a->data;
		a = a->next;
	}
}

void	sort_four(t_list **a, t_list **b)
{
	find_min_max(*a);
	while ((*a)->data != minmaxlist()->min && (*a)->data != minmaxlist()->max)
		rotate(a, 1);
	push(b, a, 2);
	sort_three(a);
	if ((*b)->data == minmaxlist()->max)
	{
		push(a, b, 1);
		rotate(a, 2);
	}
	else if ((*b)->data == minmaxlist()->min)
		push(a, b, 1);
}

void	sort_five(t_list **a, t_list **b)
{
	find_min_max(*a);
	while ((*a)->data != minmaxlist()->min && (*a)->data != minmaxlist()->max)
		rotate(a, 1);
	push(b, a, 2);
	find_min_max(*a);
	while ((*a)->data != minmaxlist()->min && (*a)->data != minmaxlist()->max)
		rotate(a, 1);
	push(b, a, 2);
	sort_three(a);
	while (*b)
	{
		push(a, b, 1);
		if ((*a)->data > (*a)->next->data)
			rotate(a, 1);
	}
}
