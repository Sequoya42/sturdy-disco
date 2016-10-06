/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbaum <rbaum@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:16:30 by rbaum             #+#    #+#             */
/*   Updated: 2015/09/22 15:38:00 by rbaum            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

# define BUFF_SIZE 32

# define KNRM  "\x1B[0m"
# define KRED  "\x1B[31m"
# define KGRN  "\x1B[32m"
# define KYEL  "\x1B[33m"
# define KBLU  "\x1B[34m"
# define KMAG  "\x1B[35m"
# define KCYN  "\x1B[36m"
# define KWHT  "\x1B[37m"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(char const *s);
size_t				ft_strlcat(char *dst, char const *src, size_t size);
void				ft_init_tab(char **tab);
void				ft_memdel(void **ap);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f) (unsigned int, char *));
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);
void				ft_strlclr(char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putnbrn(int n);
void				ft_putnbrendl(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_strclr(char *s);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_clear_tab(char ***tab);
void				ft_colstr(char *col, char *msg);
void				ft_colendl(char *s);
void				ft_exit(char *name, char *arg, char *msg);
void				ft_print_tab(char **tab);
void				ft_trim_tab(char **tab);
void				ft_print(char *s, ...);
void				msg_exit(char *s, ...);
int					int_exit(char *s, ...);
int					debug(void);
int					ft_atoi(char const *str);
long				ft_atol(const char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isdigitand(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					get_next_line(int const fd, char **line);
int					ft_nb_tab(char **tab);
int					ft_error(char *name, char *arg, char *msg);
int					match(char *s1, char *s2);
int					match_char(char c, char *s1);
int					is_blank(char *s);
int					ft_string_digit(char *s);
int					ft_read(int fd, void *s, int size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strchr(char const *s, int c);
char				*ft_strrchr(char const *s, int c);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);
char				*ft_strdup(char const *s1);
char				*ft_strndup(char const *s1, int i);
char				*ft_strstr(char const *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strmap(char const *s, char (*f) (char));
char				*ft_strmapi(char const *s, char (*f) (unsigned int, char));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				*ft_strtrim_all(const char *s);
char				*ft_itoa(int n);
char				*ft_strctrim(const char *s, char c);
char				*ft_split_char(char *s, int i, char c);
char				**ft_strsplit(const char *s, char c);
char				**ft_update_tab(char **tab);
char				**ft_strdup_tab(char **tab);
char				*ft_base(unsigned int n, int b);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *list, t_list *(*f)(t_list*));
void				print_memory(const void *addr, size_t size);
#endif
