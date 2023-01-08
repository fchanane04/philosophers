/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:48:01 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 23:04:54 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

int	flag_state(t_philo *ph)
{
	int	i;

	pthread_mutex_lock(&ph->param->flag_locker);
	i = ph->param->flag;
	pthread_mutex_unlock(&ph->param->flag_locker);
	return (i);
}

void	*simulator(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	pthread_mutex_lock(&ph->last_meal_locker);
	ph->last_meal = get_time();
	pthread_mutex_unlock(&ph->last_meal_locker);
	while (flag_state(ph))
	{
		ft_eat(ph);
		if (ph->meals_eaten == ph->param->meals)
			return (NULL);
		ft_sleep(ph);
		ft_think(ph);
	}
	return (NULL);
}

void	create_threads(t_philo *ph, int count)
{
	int	i;

	i = 0;
	if (count == 1)
		lonely_philo(&ph[i]);
	else
	{
		while (i < count)
		{	
			pthread_create(&ph[i].th, NULL, &simulator, (void *)&ph[i]);
			usleep(50);
			i++;
		}
	}
}

void	destroy_threads(t_philo *ph, t_param *param)
{
	int	i;

	i = 0;
	while (i < param->philos)
	{
		if (!param->flag)
			return ;
		pthread_join(ph[i].th, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_param	*param;
	t_philo	*ph;

	if (parsing(argc, argv))
		return (1);
	param = param_init(argc, argv);
	ph = philo_init(param);
	mutex_init(ph, param);
	create_threads(ph, param->philos);
	if (supervisor(ph, param) == 1)
	{
		garbage_collector(ph);
		mutex_destroy(ph, param);
		return (0);
	}
	return (0);
}
