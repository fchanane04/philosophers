/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 04:54:32 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 22:57:19 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	supervisor(t_philo *ph, t_param *param)
{
	int	i;

	while (param->flag)
	{
		i = 0;
		while (i < param->philos)
		{
			pthread_mutex_lock(&ph[i].last_meal_locker);
			if ((get_time() - ph[i].last_meal) > param->time_die)
			{
				pthread_mutex_lock(&ph[i].param->flag_locker);
				param->flag = 0;
				pthread_mutex_unlock(&ph[i].param->flag_locker);
				pthread_mutex_lock(&param->printer);
				if (param->all_ate != param->philos)
					printf("%ld ms %d %s\n", (get_time() - param->initial_time),
						ph[i].idx, DEAD);
				usleep(400);
				return (1);
			}
			pthread_mutex_unlock(&ph[i].last_meal_locker);
			i++;
		}
	}
	return (0);
}

void	garbage_collector(t_philo *ph)
{
	free(ph);
	ph = NULL;
}

void	lonely_philo(t_philo *ph)
{
	pthread_mutex_lock(&ph->fork);
	pthread_mutex_lock(&ph->param->printer);
	printf("%ld ms %d %s\n", (get_time() - ph->param->initial_time),
		ph->idx, FORK);
	pthread_mutex_unlock(&ph->param->printer);
}
