/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:04:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/22 12:54:55 by tfujiwar         ###   ########.fr       */
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
		precise_usleep(500);
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
	pthread_mutex_lock(&(philo->var_mutex));
	pthread_mutex_lock(philo->left_fork);
	philo->log_time = timestamp_ms(philo->env->start);
	print_log(philo, "has taken a fork");
	pthread_mutex_lock(philo->right_fork);
	philo->log_time = timestamp_ms(philo->env->start);
	philo->last_meal_time = philo->log_time + philo->env->time_to_eat;
	print_log(philo, "has taken a fork");
	print_log(philo, "is eating");
	precise_usleep(philo->env->time_to_eat * 1000);
	pthread_mutex_lock(&(philo->env->finish_mutex));
	philo->n_eat += 1;
	if (philo->n_eat == philo->env->n_must_eat && philo->env->n_must_eat != -1)
		philo->env->n_already_eat += 1;
	pthread_mutex_unlock(&(philo->env->finish_mutex));
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&(philo->var_mutex));
}

static void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	philo->log_time = timestamp_ms(philo->env->start);
	print_log(philo, "is sleeping");
	precise_usleep(philo->env->time_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	philo->status = THINK;
	philo->log_time = timestamp_ms(philo->env->start);
	print_log(philo, "is thinking");
}
