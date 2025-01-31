/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbossio <kbossio@student.42firenze.it>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:13:11 by kbossio           #+#    #+#             */
/*   Updated: 2025/01/31 23:42:31 by kbossio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"

# include <stdlib.h>
# include <unistd.h>

typedef struct s_li
{
	void			*content;
	struct s_li	*next;
}	t_li;

int		ft_isalpha(int a);
int		ft_isdigit(int a);
int		ft_isalnum(int a);
int		ft_isascii(int a);
int		ft_isprint(int a);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *p, int c, size_t n);
void	*ft_bzero(void *p, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dest, const char *src, size_t n);
size_t	ft_strlcat(char *dest, const char *src, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *str, int c);
char	*ft_strrchr(const char *str, int c);
int		ft_strncmp(char *s1, const char *s2, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *str1, const void *str2, size_t n);
char	*ft_strnstr(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
t_li	*ft_lstnew(void *content);
void	ft_lstadd_front(t_li **lst, t_li *new);
int		ft_lstsize(t_li *lst);
t_li	*ft_lstlast(t_li *lst);
void	ft_lstadd_back(t_li **lst, t_li *new);
void	ft_lstdelone(t_li *lst, void (*del)(void *));
void	ft_lstclear(t_li **lst, void (*del)(void *));
void	ft_lstiter(t_li *lst, void (*f)(void *));
t_li	*ft_lstmap(t_li *lst, void *(*f)(void *), void (*del)(void *));

#endif
