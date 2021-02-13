#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
** Start function prototypes
*/

void			error_func(char *message);

int				call_correct_test(char *first_arg);

extern	size_t	ft_strlen(const char *s);

/*
** End function prototypes
*/

int		main(int ac, char *av[])
{
	int		ret;

	ret = 0;
	if (ac != 2)
		error_func("wrong number of arrguments");
	ret = call_correct_test(av[1]);
	return (ret);
}

/*
** Test functions
*/

int		call_correct_test(char *first_arg)
{
	int		ret;

	ret = 0;

	if (!strcmp("*", first_arg))
		// ret = call_all_test_functions();
		0;
	else if (!strcmp("ft_strlen", first_arg))
		ret = ft_strlen_test();
	else
		ret = 1;
	return(ret);
}

int		ft_strlen_test(void)
{
	int		ret = 0;
	// colorize the tests please, but not now !!

	printf("test: 'Hello World!' \nresult: %ld\n", ft_strlen("Hello World!"));

	return (ret);
}

/*
** Framework functions
*/

void	error_func(char	*message)
{
	printf("Error: %s\n", message);
	exit(0);
}