/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:17:30 by melperri          #+#    #+#             */
/*   Updated: 2021/12/12 21:55:07 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_hash_table	*ft_hashnew(char *key, char *value)
{
	t_hash_table	*list;

	list = malloc(sizeof(*list));
	if (!list)
		return (NULL);
	list->key = ft_strdup(key);
	if (list->key == NULL)
		return (NULL);
	list->value = ft_strdup(value);
	if (list->value == NULL)
		return (NULL);
	list->next = NULL;
	return (list);
}
