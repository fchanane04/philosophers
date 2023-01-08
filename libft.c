/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:10:26 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 22:57:51 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
			write(1, &s[i++], 1);
	}
}

static int	ft_check_sign(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

long	ft_atoi(char *str)
{
	int			i;
	int			sign;
	long long	number;

	i = 0;
	sign = 1;
	number = 0;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		if ((number * 10 + (str[i] - '0')) / 10 != number)
			return (ft_check_sign(sign));
		if (str[i] == '-' || str[i] == '+')
			return (number * sign);
		number = number * 10 + (str[i++] - 48);
	}
	return (number * sign);
}
