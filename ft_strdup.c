/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 17:26:19 by melperri          #+#    #+#             */
/*   Updated: 2021/12/12 21:53:22 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!src)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * ft_strlen(src) + 1);
	if (!dest)
		return (NULL);
	ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strdup_pimp(char *start, char *end)
{
	char	*dest;
	int		size;
	int		i;

	if (!start)
		return (NULL);
	size = ft_strlen(start) - ft_strlen(end);
	dest = (char *)malloc(sizeof(char) * size + 1);
	if (!dest)
		return (NULL);
	dest[size] = '\0';
	i = -1;
	while (++i < size)
		dest[i] = start[i];
	return (dest);
}
