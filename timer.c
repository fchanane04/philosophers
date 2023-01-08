/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:01:39 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 19:47:04 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philosophers.h"

long	get_time(void)
{
	struct timeval	val;

	gettimeofday(&val, NULL);
	return ((val.tv_sec * 1000) + (val.tv_usec / 1000));
}

void	ft_usleep(long time_init, int time_sleep)
{
	long	time_final;

	time_final = time_init + time_sleep;
	while (get_time() < time_final)
		usleep(300);
}
