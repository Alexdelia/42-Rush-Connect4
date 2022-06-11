/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 15:47:54 by adelille          #+#    #+#             */
/*   Updated: 2022/06/11 19:56:22 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "color.h"

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
# include <stdint.h>

# define STDIN	0
# define STDOUT	1
# define STDERR	2

# ifndef PB_BUFFER
#  define PB_BUFFER	40000
# endif

void			*ft_memset(void *s, int c, size_t len);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *nptr);
long			ft_atol(const char *nptr);

void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);

ssize_t			ft_ps(const char *str);
ssize_t			ft_psc(const char *str, const char *color);
ssize_t			ft_pser(const char *str);
ssize_t			ft_pserc(const char *str, const char *color);
ssize_t			ft_pn(int nbr);
ssize_t			ft_pner(int nbr);
ssize_t			ft_pnc(int nbr, const char *color);
ssize_t			ft_pnerc(int nbr, const char *color);
void			ft_pb(const bool w, const char *str);
void			ft_pb_s(const bool w, const char *str, const size_t size);
size_t			ft_pb_f(const bool w, const char *str);


int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strcpy(char *dst, const char *src);

int				ft_nbrlen(int nb);
int				ft_abs(int n);

#endif
