#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <inttypes.h>
#include <errno.h>

#ifndef LIBASM_H
#define LIBASM_H

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_write(int fd, const void *buff, size_t nbytes);
size_t	ft_read(int fd, const void *buff, size_t nbytes);
char	*ft_strdup(const char *s1);

#define red "\033[1;31m"
#define yellow "\033[1;33m"
#define green "\033[1;32m"
#define reset "\033[0m"

#endif