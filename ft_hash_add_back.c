/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_add_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 13:17:22 by melperri          #+#    #+#             */
/*   Updated: 2021/12/12 21:54:25 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_hashadd_back(t_hash_table **alst, t_hash_table *new)
{
	if (alst && new)
	{
		if (*alst == NULL)
			*alst = new;
		else
			ft_hashlast(*alst)->next = new;
	}
}
