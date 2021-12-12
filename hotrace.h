/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotrace.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghanquer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 09:40:04 by ghanquer          #+#    #+#             */
/*   Updated: 2021/12/12 22:07:11 by melperri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOTRACE_H
# define HOTRACE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>

# define BUFFER_SIZE 4096

typedef struct s_list		t_list;

struct	s_list {
	char	*key;
	char	*value;
	t_list	*next;
};

typedef struct s_hash_table	t_hash_table;

struct	s_hash_table {
	char			*key;
	char			*value;
	t_hash_table	*next;
};

typedef struct s_env {
	t_list			*dico;
	t_list			*search;
	t_hash_table	**hash_list;
	char			*file;
}t_env;

int				ft_write_error(int i);
void			ft_clear_hash_table(t_env *g);
void			ft_lstclear_dico(t_env *g);
void			ft_lstclear_search(t_env *g);
int				ft_hash(char *str);
int				fill_hash_list(t_list *tmp, t_env *g, int hash);
int				set_hash_list(int size, t_env *g);
int				ft_search(t_env *g, int i);
int				ft_free(t_env *g);
size_t			ft_strlen(const char *str);
void			*ft_calloc(size_t nmemb, size_t size);
void			*ft_memset(void *s, int c, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
void			ft_putstr(char *s);
char			*ft_strchr(const char *s, int c);
char			*ft_strcpy(char *dest, const char *src);
char			*ft_strjoin(char *word, char *buffer);
t_list			*ft_lstnew(char *key, char *value);
void			ft_lstadd_front(t_list **alst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
t_hash_table	*ft_hashlast(t_hash_table *lst);
t_hash_table	*ft_hashnew(char *key, char *value);
void			ft_hashadd_back(t_hash_table **alst, t_hash_table *new);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			ft_printlst(t_list *lst);
void			ft_bzero(void *s, size_t n);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strdup(const char *src);
char			*ft_strdup_pimp(char *start, char *end);

#endif
