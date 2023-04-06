/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:53:45 by fpereira          #+#    #+#             */
/*   Updated: 2023/03/15 16:48:57 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>

typedef struct s_stack
{
	t_list			*a;
	t_list			*b;
}				t_stack;

void	exit_process(int i, t_list **a);
void	is_nbr(char *s, t_list **a);
long	ft_atoi_ps(char **str);
void	parser(char **argv, t_list **a);
void	add_content(t_list **a, int num);
t_list	*minmaxlist(void);
int		find_dup(t_list *a);
int		check_sorted(t_list *a);
void	push(t_list **x, t_list **z, int command);
void	r_rotate(t_list **x, int command);
void	do_rrr(t_list **a, t_list **b);
void	swap(t_list **x, int command);
void	do_ss(t_list **a, t_list **b);
void	rotate(t_list **x, int command);
void	do_rr(t_list **a, t_list **b);
void	find_max(t_list *a);
int		max_bits(t_list **a);
void	radix_binary(t_list **a, t_list **b);
void	number_index(t_list **a);
void	sort_three(t_list **a);
void	find_min_max(t_list *a);
void	sort_four(t_list **a, t_list **b);
void	sort_five(t_list **a, t_list **b);
void	free_list(t_list **a);

#endif