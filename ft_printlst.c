/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printlst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:31:10 by melperri          #+#    #+#             */
/*   Updated: 2021/12/12 22:20:55 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_printlst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	while (tmp->next)
	{
		printf("%s\n", tmp->key);
		printf("%s\n", tmp->value);
		tmp = tmp->next;
	}
}
