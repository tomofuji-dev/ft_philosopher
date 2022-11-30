/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:04:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/30 16:59:42 by t.fuji           ###   ########.fr       */
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
	{
		print_log(philo, "is thinking");
		precise_usleep(500);
	}
	while (env->finish == false)
	{
		if (philo->status == EAT)
			philo_sleep(philo);
		else if (philo->status == SLEEP)
			philo_think(philo);
		else if (philo->status == THINK)
		{
			philo_eat(philo);
			if (philo->env->n_philos == 1)
				return (NULL);
		}
	}
	return (NULL);
}

static void	philo_eat(t_philo *philo)
{
	int	time_for_log;

	philo->status = EAT;
	pthread_mutex_lock(philo->left_fork);
	print_log(philo, "has taken a fork");
	if (philo->env->n_philos == 1)
		return ;
	pthread_mutex_lock(philo->right_fork);
	time_for_log = timestamp_ms(philo->env->start);
	pthread_mutex_lock(&(philo->var_mutex));
	philo->last_meal_time = time_for_log;
	pthread_mutex_unlock(&(philo->var_mutex));
	print_log(philo, "has taken a fork");
	print_log(philo, "is eating");
	wait_until(add_timeval(philo->env->start, \
		ms_to_timeval(philo->last_meal_time + philo->env->time_to_eat)));
	pthread_mutex_lock(&(philo->var_mutex));
	philo->n_eat += 1;
	if (philo->n_eat == philo->env->n_must_eat && philo->env->n_must_eat != -1)
		philo->env->n_already_eat += 1;
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(&(philo->var_mutex));
}

static void	philo_sleep(t_philo *philo)
{
	philo->status = SLEEP;
	print_log(philo, "is sleeping");
	precise_usleep(philo->env->time_to_sleep * 1000);
}

static void	philo_think(t_philo *philo)
{
	philo->status = THINK;
	print_log(philo, "is thinking");
}
