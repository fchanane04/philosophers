/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 00:26:48 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 22:58:30 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	pick_forks(t_philo *ph)
{
	if (ph->idx % 2 == 0)
	{
		pthread_mutex_lock(&ph->fork);
		printer(FORK, ph);
		pthread_mutex_lock(ph->next_fork);
		printer(FORK, ph);
	}
	else
	{
		pthread_mutex_lock(ph->next_fork);
		printer(FORK, ph);
		pthread_mutex_lock(&ph->fork);
		printer(FORK, ph);
	}
}

void	put_forks(t_philo *ph)
{
	pthread_mutex_unlock(&ph->fork);
	pthread_mutex_unlock(ph->next_fork);
}

void	ft_eat(t_philo *ph)
{
	pick_forks(ph);
	pthread_mutex_lock(&ph->last_meal_locker);
	ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->last_meal_locker);
	printer(EAT, ph);
	ft_usleep(get_time(), ph->param->time_eat);
	ph->meals_eaten++;
	if (ph->param->meals != -1)
	{
		if (ph->meals_eaten == ph->param->meals)
		{
			pthread_mutex_lock(&ph->param->meals_locker);
			ph->param->all_ate++;
			pthread_mutex_unlock(&ph->param->meals_locker);
		}
	}
	put_forks(ph);
}

void	ft_think(t_philo *ph)
{
	printer(THINK, ph);
}

void	ft_sleep(t_philo *ph)
{
	printer(SLEEP, ph);
	ft_usleep(get_time(), ph->param->time_sleep);
}
