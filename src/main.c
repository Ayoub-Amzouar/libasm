/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aamzouar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:38:18 by aamzouar          #+#    #+#             */
/*   Updated: 2021/03/11 17:07:48 by aamzouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/libasm.h"

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
	
	printf("%s##### ft_strlen #####\n%s", yellow, reset);

	printf("test: 'Hello World!'\n%sexpected: %ld\n%sresult: %ld%s\n\n", green, strlen("Hello World!"), red, ft_strlen("Hello World!"), reset);
	printf("test: 'Future Is Loading'\n%sexpected: %ld\n%sresult: %ld%s\n\n", green, strlen("Future Is Loading"), red, ft_strlen("Future Is Loading"), reset);
	printf("test: '1337'\n%sexpected: %ld\n%sresult: %ld%s\n\n", green, strlen("1337"), red, ft_strlen("1337"), reset);

	return (ret);
}

int		ft_strcpy_test(void)
{
	int		ret = 0;
	char	dst[17];
	
	printf("%s##### ft_strcpy #####\n%s", yellow, reset);

	printf("test: 'Winter Is Coming' \n%sexpected: [%s]\n%sresult: [%s]%s\n\n", green, strcpy(dst, "Winter Is Coming"), red, ft_strcpy(dst, "Winter Is Coming"), reset);
	printf("test: 'Winter Is Fallin' \n%sexpected: [%s]\n%sresult: [%s]%s\n\n", green, strcpy(dst, "Winter Is Fallin"), red, ft_strcpy(dst, "Winter Is Fallin"), reset);
	printf("test: 'Winter vs Summer' \n%sexpected: [%s]\n%sresult: [%s]%s\n\n", green, strcpy(dst, "Winter vs Summer"), red, ft_strcpy(dst, "Winter vs Summer"), reset);
	return (ret);
}

int		ft_strcmp_test(void)
{
	int ret = 0;

	printf("%s##### ft_strcmp #####\n%s", yellow, reset);
	
	printf("test: 'ft_strcmp, strcmp' \n%sexpected: %d\n%sresult: %d%s\n\n", green, strcmp("ft_strcmp", "strcmp"), red, ft_strcmp("ft_strcmp", "strcmp"), reset);
	printf("test: 'Hunter, Hunter' \n%sexpected: %d\n%sresult: %d%s\n\n", green, strcmp("Hunter", "Hunter"), red, ft_strcmp("Hunter", "Hunter"), reset);
	printf("test: 'Melody, Harmony' \n%sexpected: %d\n%sresult: %d%s\n\n", green, strcmp("Melody", "Harmony"), red, ft_strcmp("Melody", "Harmony"), reset);
	return (ret);
}

int		ft_write_test(void)
{
	int ret = 0;

	printf("%s##### ft_write #####\n%s", yellow, reset);
	
	printf("test: 'Hi u corrector!!'\n");
	printf("%sexpected: %ld%s\n", green, write(1, "Hi u corrector!!\n", 18), reset);
	printf("%sresult: %ld%s\n\n", red, ft_write(1, "Hi u corrector!!\n", 18), reset);
	printf("test: 'Bad File Descriptor' \n%sexpected: %ld * errno: %d%s\n", green, write(4, "\n", 1), errno, reset);
	printf("%sresult: %ld * errno: %d%s\n\n", red, ft_write(4, "\n", 1), errno, reset);
	return (ret);
}

int		ft_read_test(void)
{
	int 	ret = 0;
	char	buff[13];
	int		fd;

	buff[12] = '\0';
	fd = open("src/main.c", O_RDONLY);	
	printf("%s##### ft_read #####\n%s", yellow, reset);

	printf("test: 'Read From main.c' \n%sexpected: %ld * '%s'%s\n", green, read(fd, buff, 12), buff, reset);
	printf("%sresult: %ld * '%s'%s\n\n", red, ft_read(fd, buff, 12), buff, reset);
	close(fd);
	printf("test: 'Bad File Descriptor' \n%sexpected: %ld * errno: %d%s\n", green, read(4, buff, 1), errno, reset);
	printf("%sresult: %ld * errno: %d%s\n\n", red, ft_read(4, buff, 1), errno, reset);
	return (ret);
}

int		ft_strdup_test(void)
{
	int 	ret = 0;
	char	*buff;
	
	printf("%s##### ft_strdup #####\n%s", yellow, reset);

	buff = strdup("Yo everbody f_ckin jump!!!");
	printf("%sexpected: %s%s\n", green, buff, reset);
	free(buff);
	buff = ft_strdup("Yo everbody f_ckin jump!!!");
	printf("%sresult: %s%s\n", red, buff, reset);
	free(buff);
	return (ret);
}

void	test_null(void)
{
	char	dst[100];

	// ft_strlen null test
		// ft_strlen(NULL);
		// strlen(NULL);
	
	// ft_strcpy null test
		// ft_strcpy(dst, NULL);
		// ft_strcpy(NULL, "HI");
		// ft_strcpy(NULL, NULL);
		// strcpy(dst, NULL);
		// strcpy(NULL, "HI");
		// strcpy(NULL, NULL);
	
	// ft_strcmp null test
		// ft_strcmp(NULL, "HI");
		// ft_strcmp("HI", NULL);
		// ft_strcmp(NULL, NULL);
		// strcmp(NULL, "HI");
		// strcmp("HI", NULL);
		// strcmp(NULL, NULL);
	
	// ft_write null test
		// ft_write(1, NULL, 1);
		// printf("%d\n", errno);
		// write(1, NULL, 1);
		// printf("%d\n", errno);
	
	// ft_read null test
		// ft_read(0, NULL, 1);
		// printf("%d\n", errno);
		// read(0, NULL, 1);
		// printf("%d\n", errno);
	
	// ft_strdup null test
		// ft_strdup(NULL);
		// strdup(NULL);
}

int		call_correct_test(char *first_arg)
{
	int		ret;

	ret = 0;

	if (!strcmp("ft_strlen", first_arg))
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
	else if (!strcmp("null", first_arg))
		test_null();
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
