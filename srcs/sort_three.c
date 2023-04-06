/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:30:20 by fpereira          #+#    #+#             */
/*   Updated: 2023/03/15 12:54:43 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

void	sort_three(t_list **a)
{
	if (((*a)->data < (*a)->next->data) && ((*a)->next->data > \
	(*a)->next->next->data) && ((*a)->data < (*a)->next->next->data))
	{
		swap(a, 1);
		rotate(a, 1);
	}
	if (((*a)->data < (*a)->next->data) && ((*a)->next->data > \
	(*a)->next->next->data) && (*a)->data > (*a)->next->next->data)
		r_rotate(a, 1);
	if (((*a)->data > (*a)->next->data) && ((*a)->next->data < \
	(*a)->next->next->data) && (*a)->data < (*a)->next->next->data)
		swap(a, 1);
	if (((*a)->data > (*a)->next->data) && ((*a)->next->data < \
	(*a)->next->next->data) && (*a)->data > (*a)->next->next->data)
		rotate(a, 1);
	if (((*a)->data > (*a)->next->data) && ((*a)->next->data > \
	(*a)->next->next->data) && (*a)->data > (*a)->next->next->data)
	{
		swap(a, 1);
		r_rotate(a, 1);
	}
	return ;
}
