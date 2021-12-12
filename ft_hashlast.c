/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hashlast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:17:41 by melperri          #+#    #+#             */
/*   Updated: 2021/12/12 21:51:51 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

t_hash_table	*ft_hashlast(t_hash_table *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}
