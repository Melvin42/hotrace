/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:28:17 by melperri          #+#    #+#             */
/*   Updated: 2021/12/12 21:59:04 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

/*
** The ft_strlen() function calculates the length of the string pointed to by s,
** excluding the terminating null byte ('\0').
*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (str)
		while (str[i])
			i++;
	return (i);
}
