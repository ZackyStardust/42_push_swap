/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpereira <fpereira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 13:50:10 by fpereira          #+#    #+#             */
/*   Updated: 2023/03/15 15:51:46 by fpereira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	ii;
	char	*s3;

	if (!s1 || !s2)
		return (0);
	s3 = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!s3)
		return (0);
	i = 0;
	ii = 0;
	while (s1[ii])
		s3[i++] = s1[ii++];
	ii = 0;
	while (s2[ii])
		s3[i++] = s2[ii++];
	s3[i] = '\0';
	return (s3);
}
