/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 15:47:10 by melperri          #+#    #+#             */
/*   Updated: 2021/12/12 21:52:06 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	if (alst && new)
	{
		if (*alst == NULL)
			*alst = new;
		else
			ft_lstlast(*alst)->next = new;
	}
}
