/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apuyane <apuyane@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 17:43:58 by apuyane           #+#    #+#             */
/*   Updated: 2026/02/14 08:17:15 by apuyane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_dprintf
{
	int			i;
	int			printed_char;
	const char	*format;
}				t_dprintf;

// is_functions
bool			ft_isalnum(int c);
bool			ft_isalpha(int c);
bool			ft_isascii(int c);
bool			ft_isdigit(int c);
bool			ft_contain_digit_only(char *s);
bool			ft_isprint(int c);
bool			ft_isspace(char c);

// to_functions
int				ft_tolower(int c);
int				ft_toupper(int c);

// ascii/int conversions
int				ft_atoi(const char *nptr);
long			ft_strtol(const char *nptr, char **endptr);
long long		ft_strtoll(const char *nptr, char **endptr);
char			*ft_itoa(int n);

// memory functions
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_calloc(size_t nmemb, size_t size);

// string manipulation
int				ft_strlen(char *str);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strnstr(const char *big, const char *little, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strdup(const char *s);

// string transformation
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strjoin_free(char *s1, char *s2);
char			*ft_strjoin_tab(char **tab); //add_to_readme
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);

// output functions
int				ft_dprintf(int fd, const char *format, ...);
int				ft_putchar_fd(char c, int fd);
int				ft_putnbr(int nb);
int				ft_putnbr_fd(int nb, int fd);
int				ft_putstr_fd(char *str, int fd);

// input functions
char			*get_next_line(int fd);

#endif
