/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:58:00 by khirsig           #+#    #+#             */
/*   Updated: 2021/08/19 11:47:30 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define BUFFER_SIZE 100
# define TRUE 1
# define FALSE 0
/*
** -----------------------------------------------------------------------------
** Includes
*/
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

/*
** -----------------------------------------------------------------------------
** Structs and typedef.
*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	int				sorting;
	int				chunk;
}t_list;

/*
** -----------------------------------------------------------------------------
** Function prototypes
*/
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strrchr(const char *str, int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strchr(const char *s, int c);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memccpy(void *dst, const void *src, int c, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
int			ft_tolower(int c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strdup(const char *src);
int			ft_atoi(const char *str);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_isdigit(int c);
int			ft_toupper(int c);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
/*
** -----------------------------------------------------------------------------
** My Bonus Function prototypes
*/
char		*ft_utoa(long long u);
char		*ft_strcpy(char *dest, const char *src);
int			ft_cntnbr(long long n);
int			ft_count_lines(char *file);
char		*get_next_line(int fd);
int			ft_count_lines(char *file);
int			ft_new_line(char *str);

#endif
