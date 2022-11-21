/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:04:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/21 14:36:43 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "time.h"
#include "utils.h"
#include <unistd.h>

void		*process_philo(t_philo *philo);
static void	eat(t_philo *philo);
static void	sleep(t_philo *philo);
static void	think(t_philo *philo);

void	*process_philo(t_philo *philo)
{
	t_env	*env;

	env = philo->env;
	wait_until(env->start);
	while (env->finish == false)
	{
		if (env->status == EAT)
			sleep(philo);
		else if (env->status == SLEEP)
			think(philo);
		else if (env->status == THINK)
			eat(philo);
	}
	return (NULL);
}

static void	eat(t_philo *philo)
{
	pthread_mutex_lock((&philo->left_fork));
	print_log(timestamp_ms(philo->env->start), \
							philo->index, "has taken a fork");
	pthread_mutex_lock((&philo->right_fork));
	print_log(timestamp_ms(philo->env->start), \
							philo->index, "has taken a fork");
	gettimeofday(&(philo->last_meal_time, NULL));
	pthread_mutex_lock(&(philo->eating_mutex));
	pthread_mutex_lock(&(philo->env->finish_mutex));
	if (philo->env->finish_mutex == false)
		print_log(timestamp_ms(philo->env->start), philo->index, "is eating");
	philo->n_eat += 1;
	if (philo->n_eat == philo->env->n_must_eat && philo->env->n_must_eat != -1)
		philo->env->n_already_eat += 1;
	pthread_mutex_unlock(&(philo->env->finish_mutex));
	wait_until(add_timeval(philo->last_meal_time, philo->env->time_to_eat));
	pthread_mutex_unlock((&philo->right_fork));
	pthread_mutex_unlock((&philo->left_fork));
	pthread_mutex_unlock(&(philo->eating_mutex));
}

static void	sleep(t_philo *philo)
{
	print_log(timestamp_ms(philo->env->start), philo->index, "is sleeping");
	usleep(timeval_to_micros(philo->env->time_to_sleep));
}

static void	think(t_philo *philo)
{
	print_log(timestamp_ms(philo->env->start), philo->index, "is thinking");
}
