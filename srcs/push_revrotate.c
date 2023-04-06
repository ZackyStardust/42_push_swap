/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_revrotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 17:13:06 by fpereira          #+#    #+#             */
/*   Updated: 2023/02/28 18:12:56 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	push(t_list **x, t_list **z, int command)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*z)
		return ;
	tmp2 = (*x);
	tmp = (*z)->next;
	ft_lstadd_front(x, *z);
	(*x)->next = tmp2;
	(*z) = tmp;
	if (command == 1)
		ft_printf("pa\n");
	if (command == 2)
		ft_printf("pb\n");
}

void	r_rotate(t_list **x, int command)
{
	t_list	*tmp;
	t_list	*last;

	last = ft_lstlast(*x);
	tmp = *x;
	while (tmp->next->next)
		tmp = tmp->next;
	tmp->next = 0;
	ft_lstadd_front(x, last);
	*x = last;
	if (command == 1)
		ft_printf("rra\n");
	if (command == 2)
		ft_printf("rrb\n");
}

void	do_rrr(t_list **a, t_list **b)
{
	r_rotate(a, 0);
	r_rotate(b, 0);
	ft_printf("rrr\n");
}
