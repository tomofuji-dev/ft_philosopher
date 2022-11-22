/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:04:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/22 11:36:32 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"
#include "time_utils.h"
#include "utils.h"
#include <unistd.h>

void		*process_philo(void *argv);
static void	philo_eat(t_philo *philo);
static void	philo_sleep(t_philo *philo);
static void	philo_think(t_philo *philo);

void	*process_philo(void *argv)
{
	t_philo	*philo;
	t_env	*env;

	philo = argv;
	env = philo->env;
	wait_until(env->start);
	if (philo->index % 2 == 0)
		precise_usleep(timeval_to_micros(philo->env->time_to_eat));
	while (env->finish == false)
	{
		if (philo->status == EAT)
			philo_sleep(philo);
		else if (philo->status == SLEEP)
			philo_think(philo);
		else if (philo->status == THINK)
			philo_eat(philo);
	}
	return (NULL);
}

static void	philo_eat(t_philo *philo)
{
	philo->status = EAT;
	pthread_mutex_lock(philo->left_fork);
	print_log(timestamp_ms(philo->env->start), \
							philo->index, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	print_log(timestamp_ms(philo->env->start), \
							philo->index, "has taken a fork");
	gettimeofday(&(philo->last_meal_time), NULL);
	pthread_mutex_lock(&(philo->var_mutex));
	pthread_mutex_lock(&(philo->env->finish_mutex));
	if (philo->env->finish == false)
		print_log(timestamp_ms(philo->env->start), philo->index, "is eating");
	philo->n_eat += 1;
	if (philo->n_eat == philo->env->n_must_eat && philo->env->n_must_eat != -1)
		philo->env->n_already_eat += 1;
	pthread_mutex_unlock(&(philo->env->finish_mutex));
	wait_until(add_timeval(philo->last_meal_time, philo->env->time_to_eat));
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&(philo->var_mutex));
}

static void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	print_log(timestamp_ms(philo->env->start), philo->index, "is sleeping");
	precise_usleep(timeval_to_micros(philo->env->time_to_sleep));
}

static void	philo_think(t_philo *philo)
{
	philo->status = THINK;
	print_log(timestamp_ms(philo->env->start), philo->index, "is thinking");
}
