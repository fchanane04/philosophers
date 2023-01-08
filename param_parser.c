/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 20:03:46 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 23:02:27 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	error_msg(char *msg)
{
	ft_putstr("ERROR\n");
	ft_putstr(msg);
	ft_putstr("\n");
	return (1);
}

int	arguments_type(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		if (!argv[i][0])
			return (1);
		j = 0;
		if (argv[i][j] == '-' || argv[i][j] == '+')
			j++;
		if (!argv[i][j])
			return (1);
		while (argv[i][j])
		{
			if (argv[i][j] < '0' || argv[i][j] > '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	arguments_valid(int argc, char **argv)
{
	int		i;
	long	nbr;

	i = 1;
	while (i < argc)
	{
		nbr = ft_atoi(argv[i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (1);
		if (i == 1 && nbr < 1)
			return (1);
		if (i > 1 && nbr < 0)
			return (1);
		if (argc == 6 && ft_atoi(argv[argc - 1]) < 1)
			return (1);
		i++;
	}
	return (0);
}

int	parsing(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_msg(ARG));
	if (arguments_type(argc, argv))
		return (error_msg(NBR));
	if (arguments_valid(argc, argv))
		return (error_msg(VALID));
	return (0);
}
