/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 17:00:37 by ghanquer          #+#    #+#             */
/*   Updated: 2021/12/12 22:19:29 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

static int	print_value(t_hash_table *hash_tmp, t_list *tmp)
{
	if (ft_strcmp(tmp->key, hash_tmp->key) == 0)
	{
		write(1, hash_tmp->value, ft_strlen(hash_tmp->value));
		write(1, "\n", 1);
	}
	return (1);
}

int	ft_free(t_env *g)
{
	ft_lstclear_dico(g);
	ft_lstclear_search(g);
	ft_clear_hash_table(g);
	if (g->file)
		free(g->file);
	return (-1);
}

int	ft_search(t_env *g, int i)
{
	t_list			*tmp;
	t_hash_table	*hash_tmp;
	int				size;
	int				hash;

	tmp = g->search;
	size = ft_lstsize(g->dico);
	while (tmp)
	{
		hash = ft_hash(tmp->key) % size;
		hash_tmp = g->hash_list[hash];
		if (hash_tmp->next)
		{
			while (hash_tmp)
			{
				i = print_value(hash_tmp, tmp);
				hash_tmp = hash_tmp->next;
			}
		}
		else
			i = print_value(hash_tmp, tmp);
		i = ft_write_error(i);
		tmp = tmp->next;
	}
	return (0);
}

int	set_hash_list(int size, t_env *g)
{
	int	i;

	i = 0;
	while (i < size)
	{
		g->hash_list[i] = malloc(sizeof(t_hash_table));
		if (g->hash_list[i] == NULL)
			return (ft_free(g));
		ft_memset(g->hash_list[i], 0, sizeof(*g->hash_list[i]));
		i++;
	}
	return (0);
}

int	fill_hash_list(t_list *tmp, t_env *g, int hash)
{
	if (g->hash_list[hash]->value != NULL)
	{
		ft_hashadd_back(&g->hash_list[hash], \
				ft_hashnew(tmp->key, tmp->value));
	}
	else
	{
		g->hash_list[hash]->key = ft_strdup(tmp->key);
		g->hash_list[hash]->value = ft_strdup(tmp->value);
	}
	if (g->hash_list[hash]->value == NULL || \
			g->hash_list[hash]->key == NULL || \
			ft_hashlast(g->hash_list[hash]) == NULL)
		return (ft_free(g));
	return (1);
}
