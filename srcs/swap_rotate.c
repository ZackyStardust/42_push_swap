/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:04:08 by fpereira          #+#    #+#             */
/*   Updated: 2023/02/28 18:16:15 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	swap(t_list **x, int command)
{
	t_list	*temp;

	temp = (*x)->next;
	(*x)->next = temp->next;
	temp->next = *x;
	*x = temp;
	if (command == 1)
		ft_printf("sa\n");
	else if (command == 2)
		ft_printf("sb\n");
}

void	do_ss(t_list **a, t_list **b)
{
	swap(a, 0);
	swap(b, 0);
	ft_printf("ss\n");
}

void	rotate(t_list **x, int command)
{
	t_list	*temp;
	t_list	*start;

	temp = ft_lstlast(*x);
	temp->next = *x;
	temp = *x;
	start = (*x)->next;
	temp->next = NULL;
	*x = start;
	if (command == 1)
		ft_printf("ra\n");
	if (command == 2)
		ft_printf("rb\n");
}

void	do_rr(t_list **a, t_list **b)
{
	rotate(a, 0);
	rotate(b, 0);
	ft_printf("rr\n");
}
