/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 14:43:35 by fpereira          #+#    #+#             */
/*   Updated: 2023/03/15 16:48:12 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;

	a = NULL;
	b = NULL;
	if (argc <= 1)
		exit_process(0, &a);
	parser(argv, &a);
	if (!find_dup(a))
		exit_process(1, &a);
	if (!check_sorted(a))
	{
		if (ft_lstsize(a) == 2)
			swap(&a, 1);
		if (ft_lstsize(a) == 3)
			sort_three(&a);
		if (ft_lstsize(a) == 4)
			sort_four(&a, &b);
		if (ft_lstsize(a) == 5)
			sort_five(&a, &b);
		if (ft_lstsize(a) >= 6)
			radix_binary(&a, &b);
	}	
	exit_process(0, &a);
}
