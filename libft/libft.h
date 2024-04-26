/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evdos-sa <evdos-sa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 10:15:10 by evdos-sa          #+#    #+#             */
/*   Updated: 2023/08/19 11:32:06 by evdos-sa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

/*	Include external libraries */
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>

/* Libs for 'OPEN' */
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/* GNL - OPEN_MAX */
# include <limits.h>

/* PRINTF */
# include <stdarg.h>
# include <stdint.h>
# include <inttypes.h>

/* MINITALK */
# include <signal.h>

/* Struct */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/* libc */
long int	ft_isldigit(long int c);
long		ft_atol(const char *str);
int			ft_atoi(char *str);
void		ft_bzero(void *s, size_t n);
void		*ft_calloc(size_t nmemb, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memmove(void *dest, const void *src, size_t n);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *little, size_t len);
char		*ft_strrchr(const char *str, int c);
int			ft_tolower(int c);
int			ft_toupper(int c);

/* Additional functions */
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s1, char const *set);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);

//	PRINTF
int			ft_printf(const char *fstarg, ...);
int			ft_putchari_fd(char c, int fd);
int			ft_pointer(unsigned long long address);
int			ft_iputstr_fd(char *s, int fd);
int			ft_putnbri_fd(int n, int fd);
int			ft_putnbase(unsigned long nbr, const char *base, int fd);
int			ft_printfhexa(size_t num, const char format);
size_t		ft_uputnbr_fd(size_t n, int fd);

// GET NEXT LINE
char		*get_next_line(int fd);
char		*fd_read(int fd, char *temp_line);
char		*fd_lastline(char *temp);
char		*fd_newline(char *temp_line);
char		*fd_free(char *temp_line, char *read_buf);
char		*ft_strjoin_gnl(char const *s1, char const *s2);

// Bonus part
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void*));
void		ft_lstclear(t_list **lst, void (*del)(void*));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
