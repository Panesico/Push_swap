#include "../includes/push_swap.h"

int *ft_free_split(char **str, int *tab)
{
	int	i;

	i = -1;
	while(str[++i])
		free(str[i]);
	free(str);
	if (tab)
		free(tab);
	return (0);
}

int	*ft_parser1(char **argv, int *size)
{
	char	**str;
	int		*tab;
	int		i;
	long	long_num;

	tab = 0;
	str = ft_split(argv[1], ' ');
	if (!ft_check_if_num_split(str))
		return(ft_free_split(str, 0));
	while (str[*size])
		*size += 1;
	tab = (int *)malloc(sizeof(int) * (*size));
	if (!tab)
		ft_free_split(str, tab);
	i = 0;
	long_num = 0;
	while (str[i])
	{
		long_num = ft_atol(str[i]);
		if(long_num > 2147483647)
			ft_free_split(str, tab);
		tab[i] = ft_atoi(str[i]);
		printf("%d", *size);
		i++;
	}
	return (tab);
}

int	*ft_parser2(int argc, char **argv, int *size)
{
	int		*tab;
	int		i;
	long	long_num;

	tab = 0;
	if (!ft_check_if_num_argv(argc, argv))
		return(0);
	*size = argc - 1;
	tab = (int *)malloc(sizeof(int) * *size);
	i = 1;
	long_num = 0;
	while (i <= *size)
	{
		long_num = ft_atol(argv[i]);
		if(long_num > 2147483647)
			return (0);
		tab[i - 1] = ft_atoi(argv[i]);
		printf("%d", *size);
		i++;
	}
	return (tab);
}

int	*ft_parser(int argc, char **argv, int *size)
{
	int *tab;

	tab = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
		tab = ft_parser1(argv, size);
	else
		tab = ft_parser2(argc, argv, size);
	return (tab);
}