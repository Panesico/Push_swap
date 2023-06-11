/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 16:47:35 by jorgfern          #+#    #+#             */
/*   Updated: 2023/06/11 16:47:35 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jorgfern <jorgfern@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 18:06:01 by jorgfern          #+#    #+#             */
/*   Updated: 2023/05/10 16:49:48 by jorgfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <signal.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int				ft_isspace(char c);
float			ft_recursive_get_decimal(const char *str, int i, float num2);
void			ft_if_negative(const char *str, int *negative, int *i);
double			ft_atod(const char *str);
float			ft_atof(const char *str);
int				ft_atoi(const char *str);
long			ft_atol(const char *str);
void			ft_bzero(void *str, size_t n);
void			*ft_calloc(size_t count, size_t size);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
char			*ft_itoa(int n);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **lst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void(*del)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			**ft_split(char const *s, char c);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup(const char *s);
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
char			*ft_strjoin(char const *s1, char const *s2);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dest, const char *src, size_t size);
size_t			ft_strlen(const char *str);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(const char *s1, const char *s2, size_t n);
char			*ft_strrchr(const char *str, int c);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_tolower(int c);
int				ft_toupper(int c);

int				ft_convert_printf(char c, va_list arglist);
char			*ft_itoa_printf(int num);
size_t			ft_strlen_printf(const char *str);
int				ft_putbase_printf(unsigned int num, char *base);
int				ft_putbasel_printf(unsigned long long num, char *base);
int				ft_putchar_fd_printf(int c, int fd);
int				ft_printf(const char *str, ...);
int				ft_print_itoa_printf(int num);
int				ft_putptr_printf(unsigned long long num, char *base);
int				ft_putstr_fd_printf(char *s, int fd);
unsigned int	ft_putunbr_fd_printf(unsigned int n, int fd);

char			*ft_nlsplit_gnl(char *buffer);
char			*ft_next_line_gnl(char *buffer);
char			*ft_read_gnl(char *buffer, int fd);
char			*get_next_line(int fd);
void			*ft_calloc_gnl(size_t count, size_t size);
size_t			ft_strlen_gnl(const char *str);
char			*ft_strchr_gnl(const char *str, int c);
char			*ft_strjoin_gnl(char *s1, char *s2);

#endif //LIBFT_H