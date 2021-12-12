/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:32:11 by ghanquer          #+#    #+#             */
/*   Updated: 2021/12/13 00:56:12 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

int	ft_hash(char *str)
{
	int	i;
	int	hash;

	i = 0;
	hash = 0;
	if (str)
	{
		while (str[i])
		{
			hash += str[i];
			i++;
		}
	}
	return (hash);
}

static int	ft_get_key_to_search(t_env *g, char *start)
{
	char	*end;

	end = start;
	while (*start && *end)
	{
		if (*end == '\n')
		{
			ft_lstadd_back(&g->search, ft_lstnew(NULL, NULL));
			ft_lstlast(g->search)->key = ft_strdup_pimp(start, end);
			if (ft_lstlast(g->search)->key == NULL)
				return (ft_free(g));
			start = end + 1;
		}
		end++;
	}
	return (0);
}

static int	get_word(t_env *g)
{
	char	*start;
	char	*end;
	int		flag;

	flag = 0;
	start = g->file;
	end = g->file;
	while (*start && *end)
	{
		if (*end == '\n' && flag == 0)
		{
			ft_lstadd_back(&g->dico, ft_lstnew(NULL, NULL));
			ft_lstlast(g->dico)->key = ft_strdup_pimp(start, end);
			if (ft_lstlast(g->dico)->key == NULL)
				return (ft_free(g));
			flag = 1;
			start = end + 1;
			if (*start == '\n')
			{
				if (ft_get_key_to_search(g, end + 2) == -1)
					return (-1);
				break ;
			}
		}
		else if (*end == '\n' && flag == 1)
		{
			ft_lstlast(g->dico)->value = ft_strdup_pimp(start, end);
			if (ft_lstlast(g->dico)->value == NULL)
				return (ft_free(g));
			start = end + 1;
			flag = 0;
			if (*start == '\n')
			{
				if (ft_get_key_to_search(g, end + 2) == -1)
					return (-1);
				break ;
			}
		}
		end++;
	}
	return (0);
}

static int	ft_read_file(t_env *g)
{
	char	*buf;
	char	*tofree;
	int		ret;

	buf = NULL;
	g->file = malloc(sizeof(char));
	if (g->file == NULL)
		return (-1);
	g->file[0] = '\0';
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buf == NULL)
		return (ft_free(g));
	ret = read(0, buf, BUFFER_SIZE);
	if (ret < 0)
		return (ft_free(g));
	buf[ret] = '\0';
	tofree = g->file;
	g->file = ft_strjoin(g->file, buf);
	free(tofree);
	if (g->file == NULL)
		return (ft_free(g));
	free(buf);
	buf = NULL;
	return (0);
}

int	hotrace(t_env *g)
{
	t_list	*tmp;
	int		hash;
	int		size;

	if (ft_read_file(g) == -1)
		return (-1);
	if (get_word(g) == -1)
		return (-1);
	size = ft_lstsize(g->dico);
	g->hash_list = malloc(sizeof(g->hash_list) * (size + 1));
	if (!g->hash_list)
		return (ft_free(g));
	g->hash_list[size] = NULL;
	if (set_hash_list(size, g) == -1)
		return (-1);
	tmp = g->dico;
	while (tmp->next)
	{
		hash = ft_hash(tmp->key) % size;
		if (!fill_hash_list(tmp, g, hash))
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_env	g;

	(void)av;
	if (ac != 1)
		return (0);
	ft_memset(&g, 0, sizeof(g));
	if (hotrace(&g) == -1)
		return (-1);
	ft_search(&g, 0);
	ft_free(&g);
	return (0);
}
