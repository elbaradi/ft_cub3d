/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   libft.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: tel-bara <tel-bara@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/26 17:54:56 by tel-bara      #+#    #+#                 */
/*   Updated: 2021/02/27 22:58:21 by tel-bara      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include "ft_getnextline/get_next_line.h"

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
size_t				ft_strclen(const char *s, const char c);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_calloc(size_t count, size_t size);
char				*ft_strdup(const char *s1);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(long long n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
long long			ft_exp(long long base, long long exp);
long long			ft_abs(long long n);
int					ft_numlen(long long nbr);
int					ft_unumlen(unsigned long long nbr);
int					ft_hexlen(unsigned long long nbr);
void				ft_putchar_fd(char c, int fd);
ssize_t				ft_putlchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putstr(char *s);
int					ft_putlstr_fd(char *s, int fd);
int					ft_putlnstr_fd(char *s, int fd, int len);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(long long n, int fd);
void				ft_putunbr_fd(unsigned long long n, int fd);
int					ft_putlnbr_base_fd(long long nbr, char *basestr, int fd);
int					ft_putlunbr_base_fd(unsigned long long nbr, char *basestr,
						int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

char				ft_trnc(int condition, char a, char b);
double				ft_trnf(int condition, double a, double b);
int					ft_trni(int condition, int a, int b);
long				ft_trnld(int condition, long a, long b);
long long			ft_trnlld(int condition, long long a, long long b);
void				*ft_trnp(int condition, void *a, void *b);
char				*ft_trns(int condition, char *a, char *b);
size_t				ft_trnsize_t(int condition, size_t a, size_t b);
unsigned char		ft_trnuc(int condition, unsigned char a, unsigned char b);
unsigned int		ft_trnud(int condition, unsigned int a, unsigned int b);
unsigned long		ft_trnuld(int condition, unsigned long a, unsigned long b);
unsigned long long	ft_trnulld(int condition, unsigned long long a,
						unsigned long long b);

#endif
