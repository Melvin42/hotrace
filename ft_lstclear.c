/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melperri <melperri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:47:35 by melperri          #+#    #+#             */
/*   Updated: 2021/12/12 21:58:35 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_lstclear_dico(t_env *g)
{
	t_list	*tmp;

	while (g->dico)
	{
		tmp = g->dico;
		g->dico = g->dico->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		if (tmp)
			free(tmp);
	}
	free(g->dico);
}

void	ft_lstclear_search(t_env *g)
{
	t_list	*tmp;

	while (g->search)
	{
		tmp = g->search;
		g->search = g->search->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		if (tmp)
			free(tmp);
	}
	free(g->search);
}

void	ft_lstclear_hash(t_hash_table *lst)
{
	t_hash_table	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		if (tmp->key)
			free(tmp->key);
		if (tmp->value)
			free(tmp->value);
		if (tmp)
			free(tmp);
	}
	free(lst);
}

void	ft_clear_hash_table(t_env *g)
{
	int				i;

	i = 0;
	while (g->hash_list[i])
	{
		ft_lstclear_hash(g->hash_list[i]);
		i++;
	}
	free(g->hash_list);
}
