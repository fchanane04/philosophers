/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 00:27:47 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 22:54:26 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

void	printer(char *msg, t_philo *ph)
{
	long	time;

	time = get_time() - (ph->param->initial_time);
	pthread_mutex_lock(&ph->param->printer);
	printf("%ld ms %d %s\n", time, ph->idx, msg);
	pthread_mutex_unlock(&ph->param->printer);
}
