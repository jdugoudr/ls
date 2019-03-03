/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdugoudr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 09:49:12 by jdugoudr          #+#    #+#             */
/*   Updated: 2019/03/03 19:12:04 by jdugoudr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include "includes_printf/ft_printf.h"
# include "get_next_line.h"

# define MY_INT_MAX 2147483647
# define MY_INT_MIN -2147483648

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** ------				print					------
*/
void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char const *s);
void				ft_putnstr(const char *str, size_t len);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnstr_fd(const char *str, size_t len, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(int n);
void				ft_putnbr_fd(int n, int fd);
/*
** ------				print utility			------
*/
int					ft_isalnum(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
/*
** ------				number					------
*/
int					ft_atoi(const char *str);
int					ft_atoi_base(const char *str, const char *base);
unsigned int		ft_atoui_base(const char *str, const char *base);
unsigned long		ft_atoul_base(const char *str, const char *base);
int					ft_isdigit(int c);
unsigned int		ft_nblen(intmax_t n);
void				ft_swap(size_t *a, size_t *b);
/*
 ** ------				maths with str			------
*/
char				*ft_addstr(char *a, char *b);
char				*ft_faddstr(char *a, char *b);
char				*ft_subtrackstr(char *a, char *b);
char				*ft_multistr(char *a, char *b);
char				*ft_fmultistr(char *a, char *b);
char				*ft_divstr(char *a, char *b, char **r);
char				*ft_fdivstr(char *a, char *b);
char				*ft_expstr(size_t i, char *s);
char				*ft_powerstr(char *value, char *power);
char				*put_point(char *nb, size_t nb_dec_a, size_t nb_dec_b);
/*
** ------				str	basic				------
*/
int					ft_isascii(int c);
int					ft_isalpha(int c);
char				*ft_strtoupper(char *str);
size_t				ft_strlen(const char *s);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_acmpi(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t len);
char				*ft_strdup(const char *s);
char				*ft_strndup(const char *s, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char **str, char *buff);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
/*
** ------				str utility				------
*/
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_tabstrdel(char ***str, size_t size);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				**ft_strsplit(char const *s, char c);
size_t				ft_tablen(const char **t);
void				ft_swapstr(char **a, char **b);
char				*ft_strfill(char *str, char c, size_t len);
char				**ft_tabsort(char **tab, size_t len);
char				**ft_strrev(char **tab, size_t len);
/*
** ------				to str				------
*/
char				*ft_itoa(int n);
char				*ft_stoa(short n);
char				*ft_ctoa(char c);
char				*ft_ltoa(long n);
char				*ft_lltoa(long long n);
char				*ft_ftoa(double n, int precision);
char				*ft_dbtoa(double f);
char				*ft_lftoa(long double n, int precision);
char				*ft_ldbtoa(long double f);
char				*ft_imaxtoa(intmax_t n);
char				*ft_zttoa(size_t n);
char				*ft_szttoa(ssize_t n);
char				*ft_uitoa(unsigned int n);
char				*ft_uctoa(unsigned char n);
char				*ft_ustoa(unsigned short n);
char				*ft_ultoa(unsigned long n);
char				*ft_ulltoa(unsigned long long n);
char				*ft_uimaxtoa(uintmax_t n);
char				*ft_itoa_base(int n, const char *base);
char				*ft_stoa_base(short n, const char *base);
char				*ft_ltoa_base(long n, const char *base);
char				*ft_zttoa_base(size_t n, const char *base);
char				*ft_uitoa_base(unsigned int n, const char *base);
char				*ft_uctoa_base(unsigned char n, const char *base);
char				*ft_ustoa_base(unsigned short n, const char *base);
char				*ft_ultoa_base(unsigned long n, const char *base);
char				*ft_ulltoa_base(unsigned long long n, const char *base);
char				*ft_uimaxtoa_base(uintmax_t n, const char *base);
char				*ft_itoa_hex(int n);
char				*ft_ltoa_hex(long n);
char				*ft_zttoa_hex(size_t n);
char				*ft_uitoa_hex(unsigned int n);
char				*ft_ultoa_hex(unsigned long n);
char				*ft_ulltoa_hex(unsigned long long n);
char				*ft_uimaxtoa_hex(uintmax_t n);
char				*ft_zttoa_oct(size_t n);
char				*ft_uitoa_oct(unsigned int n);
char				*ft_uctoa_oct(unsigned char n);
char				*ft_ustoa_oct(unsigned short n);
char				*ft_ultoa_oct(unsigned long n);
char				*ft_ulltoa_oct(unsigned long long n);
char				*ft_uimaxtoa_oct(uintmax_t n);
char				**ft_lsttostr(const t_list *l, size_t len);
char				*ft_lstjoinstr(const t_list *l);
char				*ft_tabtostr(const char **tab);
/*
** ------				list				------
*/
t_list				*ft_lstnew(const void *content, size_t contenant_size);
t_list				*ft_lstnewstr(char *content);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *mnew);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstappend(t_list *l, t_list *mnew);
void				ft_lstdelstr(t_list **list);
void				ft_lstremove(t_list **list, t_list **el, void (*f)(void*));
/*
** ------				list utility		------
*/
void				ft_lstprint(t_list *l, void (*f)(void*));
t_list				*ft_splittolst(char *s, char c);
size_t				ft_lstlen(const t_list *l);
t_list				*ft_strtolst(char *s[]);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
/*
** ------				memory				------
*/
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memprint(const void *addr, size_t size);
/*
** ------				utility				------
*/
char				*mant_toa(unsigned long mant, char *mant_max, char *str_e,
					char *c);
char				*manage_dec_utility(char *a, char *b, size_t len_a,
					size_t len_b);
char				**ft_tabstr_realloc(char **tab, int old_size, int new_size);
#endif
