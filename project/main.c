/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:38:18 by aamzouar          #+#    #+#             */
/*   Updated: 2021/03/08 10:38:22 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	1. the program should take arrguments
		for example, the test of a specific function
		or all of them using '*'
	2. add a flag for bonuses
*/

#include "libasm.h"

/*
** Framework functions
*/

void	error_func(char	*message)
{
	printf("Error: %s\n", message);
	exit(0);
}

/*
** Test functions
*/

int		ft_strlen_test(void)
{
	int		ret = 0;
	
	printf("##### ft_strlen #####\n\n");

	printf("test: 'Hello World!'\n%sexpected: %ld\n%sresult: %ld%s\n\n", green, strlen("Hello World!"), yellow, ft_strlen("Hello World!"), reset);
	printf("test: 'Future Is Loading'\n%sexpected: %ld\n%sresult: %ld%s\n\n", green, strlen("Future Is Loading"), yellow, ft_strlen("Future Is Loading"), reset);
	printf("test: '1337'\n%sexpected: %ld\n%sresult: %ld%s\n", green, strlen("1337"), yellow, ft_strlen("1337"), reset);

	return (ret);
}

int		ft_strcpy_test(void)
{
	int		ret = 0;
	char	dst[17];
	
	printf("##### ft_strcpy #####\n\n");

	printf("test: 'Winter Is Coming' \n%sexpected %s\n%sresult: %s%s\n\n", green, strcpy(dst, "Winter Is Coming"), red, ft_strcpy(dst, "Winter Is Coming"), reset);
	printf("test: 'Winter Is Fallin' \n%sexpected %s\n%sresult: %s%s\n\n", green, strcpy(dst, "Winter Is Fallin"), red, ft_strcpy(dst, "Winter Is Fallin"), reset);
	printf("test: 'Winter vs Summer' \n%sexpected %s\n%sresult: %s%s\n\n", green, strcpy(dst, "Winter vs Summer"), red, ft_strcpy(dst, "Winter vs Summer"), reset);
	return (ret);
}

int		ft_strcmp_test(void)
{
	int ret = 0;

	printf("test: 'Hello World!' \nresult: %d\n", ft_strcmp("!d", "!"));
	printf("origin: 'Hello World!' \nresult: %d\n", strcmp("!d", "!"));
	return (ret);
}

int		ft_write_test(void)
{
	int ret = 0;

	// check errno too
	printf("test: %ld\n", ft_write(1, "Hello Ayoubff!\n", 15));
	printf("origin: %ld\n", write(1, "Hello Ayoubff!\n", 15));
	return (ret);
}

int		ft_read_test(void)
{
	int 	ret = 0;
	char	buff[15];

	printf("test: %ld\n", ft_read(0, buff, 12));
	printf("origin: %ld\n", read(0, buff, 12));
	return (ret);
}

int		ft_strdup_test(void)
{
	int 	ret = 0;
	char	*buff;

	buff = ft_strdup("Hello Everybody this is Hardwell");
	printf("test: %s\n", buff);
	free(buff);
	return (ret);
}

int		call_correct_test(char *first_arg)
{
	int		ret;

	ret = 0;

	if (!strcmp("*", first_arg))
		// ret = call_all_test_functions();
		return (0);
	else if (!strcmp("ft_strlen", first_arg))
		ret = ft_strlen_test();
	else if (!strcmp("ft_strcpy", first_arg))
		ret = ft_strcpy_test();
	else if (!strcmp("ft_strcmp", first_arg))
		ret = ft_strcmp_test();
	else if (!strcmp("ft_write", first_arg))
		ret = ft_write_test();
	else if (!strcmp("ft_read", first_arg))
		ret = ft_read_test();
	else if (!strcmp("ft_strdup", first_arg))
		ret = ft_strdup_test();
	else
		ret = 1;
	return(ret);
}

int		main(int ac, char *av[])
{
	int		ret;

	ret = 0;
	if (ac != 2)
		error_func("wrong number of arrguments");
	ret = call_correct_test(av[1]);
	return (ret);
}
