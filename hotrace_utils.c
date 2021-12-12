/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:32:20 by ghanquer          #+#    #+#             */
/*   Updated: 2021/12/12 21:53:42 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hotrace.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}

static char	*fil_tab(char *str, char *line, char *buffer)
{
	int	j;
	int	i;

	i = 0;
	j = 0;
	if (line)
	{
		while (line[i])
		{
			str[j] = line[i];
			i++;
			j++;
		}
	}
	i = 0;
	if (buffer)
	{
		while (buffer[i])
		{
			str[j] = buffer[i];
			i++;
			j++;
		}
	}
	return (str);
}

char	*ft_strjoin(char *line, char *buffer)
{
	char	*str;

	str = ft_calloc(sizeof(char), (ft_strlen(line) + ft_strlen(buffer) + 1));
	if (!str)
		return (NULL);
	str = fil_tab(str, line, buffer);
	return (str);
}

char	*get_left(char *word)
{
	int		i;
	int		j;
	char	*left;

	j = 0;
	i = 0;
	if (word)
	{
		while (word[i] && word[i] != '\n')
			i++;
		left = malloc(i + 2);
		if (!left)
			return (NULL);
		while (i >= 0)
		{
			left[j] = word[j];
			j++;
			i--;
		}
		left[j] = '\0';
		return (left);
	}
	return (NULL);
}

char	*get_right(char *word)
{
	int		i;
	int		j;
	int		index;
	char	*right;

	j = 0;
	i = 0;
	if (word)
	{
		while (word[i] && word[i] != '\n')
			i++;
		index = i;
		right = malloc(i + 2);
		if (!word)
			return (NULL);
		while (word[index])
		{
			right[j] = word[index];
			j++;
			index++;
		}
		right[j] = '\0';
		return (right);
	}
	return (NULL);
}
