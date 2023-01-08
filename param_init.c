/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 14:19:17 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 22:53:13 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	extra_init(int argc, char *argv)
{
	if (argc == 5)
		return (-1);
	else
		return (ft_atoi(argv));
}

t_param	*param_init(int argc, char **argv)
{
	t_param	*param;

	param = malloc(sizeof(t_param));
	param->flag = 1;
	param->all_ate = 0;
	param->philos = ft_atoi(argv[1]);
	param->time_die = ft_atoi(argv[2]);
	param->time_eat = ft_atoi(argv[3]);
	param->time_sleep = ft_atoi(argv[4]);
	param->meals = extra_init(argc, argv[argc - 1]);
	param->initial_time = get_time();
	return (param);
}

t_philo	*philo_init(t_param *param)
{
	t_philo	*ph;
	int		i;
	int		next;

	i = 0;
	ph = malloc(sizeof(t_philo) * param->philos);
	while (i < param->philos)
	{
		next = i + 1;
		if (next == param->philos)
			next = 0;
		ph[i].idx = i + 1;
		ph[i].last_meal = get_time();
		ph[i].meals_eaten = 0;
		ph[i].param = param;
		ph[i].next_fork = &ph[next].fork;
		i++;
	}
	return (ph);
}

void	mutex_init(t_philo *ph, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philos)
	{
		pthread_mutex_init(&ph[i].fork, NULL);
		pthread_mutex_init(&ph[i].last_meal_locker, NULL);
		i++;
	}
	pthread_mutex_init(&param->printer, NULL);
	pthread_mutex_init(&param->flag_locker, NULL);
	pthread_mutex_init(&param->meals_locker, NULL);
}

void	mutex_destroy(t_philo *ph, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philos)
	{
		pthread_mutex_destroy(&ph[i].fork);
		pthread_mutex_destroy(&ph[i].last_meal_locker);
		i++;
	}
	pthread_mutex_destroy(&param->printer);
	pthread_mutex_destroy(&param->flag_locker);
	pthread_mutex_destroy(&param->meals_locker);
}
