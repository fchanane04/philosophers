/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 14:48:41 by fchanane          #+#    #+#             */
/*   Updated: 2022/10/26 23:26:37 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <sys/time.h>

# define ARG "Please enter valid number of arguments"
# define NBR "Arguments should be numbers"
# define VALID "Numbers are not valid"

# define FORK "has taken a fork"
# define EAT "is eating"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define DEAD "died"

typedef struct s_param
{
	int				flag;
	int				all_ate;
	int				philos;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				meals;
	long			initial_time;
	pthread_mutex_t	printer;
	pthread_mutex_t	flag_locker;
	pthread_mutex_t	meals_locker;
}	t_param;

typedef struct s_philo
{
	pthread_t		th;
	pthread_mutex_t	fork;
	pthread_mutex_t	*next_fork;
	pthread_mutex_t	last_meal_locker;
	int				idx;
	long			last_meal;
	int				meals_eaten;
	t_param			*param;
}	t_philo;

void	ft_putstr(char *s);
long	ft_atoi(char *str);
int		arguments_type(int argc, char **argv);
int		arguments_valid(int argc, char **argv);
int		parsing(int argc, char **argv);
int		error_msg(char *msg);
int		extra_init(int argc, char *argv);
t_philo	*philo_init(t_param *param);
t_param	*param_init(int argc, char **argv);
void	mutex_init(t_philo *ph, t_param *param);
void	mutex_destroy(t_philo *ph, t_param *param);
int		flag_state(t_philo *ph);
void	*simulator(void *arg);
void	create_threads(t_philo *ph, int count);
void	destroy_threads(t_philo *ph, t_param *param);
long	get_time(void);
void	ft_usleep(long time_init, int time_sleep);
void	ft_eat(t_philo *ph);
void	ft_think(t_philo *ph);
void	ft_sleep(t_philo *ph);
void	pick_forks(t_philo *ph);
void	put_forks(t_philo *ph);
void	lonely_philo(t_philo *ph);
int		supervisor(t_philo *ph, t_param *param);
void	garbage_collector(t_philo *ph);
void	printer(char *msg, t_philo *ph);

#endif
