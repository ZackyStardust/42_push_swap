/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 16:34:30 by fpereira          #+#    #+#             */
/*   Updated: 2023/03/15 16:44:56 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

t_list	*minmaxlist(void)
{
	static t_list	list;

	return (&list);
}

int	find_dup(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		tmp = a->next;
		while (tmp)
		{
			if (a->data == tmp->data)
				return (0);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (1);
}

int	check_sorted(t_list *a)
{
	if (a)
	{
		while (a->next && (a))
		{
			if (a->data > a->next->data)
				return (0);
			a = a->next;
		}
	}
	return (1);
}

void	free_list(t_list **a)
{
	t_list	*tmp;

	while (*a)
	{
		tmp = *a;
		*a = (*a)->next;
		free (tmp);
	}
}
