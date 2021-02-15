/*
	1. the program should take arrguments
		for example, the test of a specific function
		or all of them using '*'
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
	// colorize the tests please, but not now !!

	printf("test: 'Hello World!' \nresult: %ld\n", ft_strlen("Hello World!"));

	return (ret);
}

int		ft_strcpy_test(void)
{
	int		ret = 0;
	char	dst[13];

	printf("test: 'Hello World!' \nresult: %s\n", ft_strcpy(dst, "Hello World!"));
	printf("test: 'Hello World!' \nresult: %s\n", dst);
	return (ret);
}

int		call_correct_test(char *first_arg)
{
	int		ret;

	ret = 0;

	if (!strcmp("*", first_arg))
		// ret = call_all_test_functions();
		0;
	else if (!strcmp("ft_strlen", first_arg))
		ret = ft_strlen_test();
	else if (!strcmp("ft_strcpy", first_arg))
		ret = ft_strcpy_test();
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