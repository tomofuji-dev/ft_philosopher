/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:04:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/03 17:46:53 by tfujiwar         ###   ########.fr       */
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
static void	philo_first_think(t_philo *philo);

void	*process_philo(void *argv)
{
	t_philo	*philo;
	t_env	*env;

	philo = argv;
	env = philo->env;
	wait_until(env->start);
	philo_first_think(philo);
	while (check_finish(env) == false)
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

static void	philo_first_think(t_philo *philo)
{
	t_env	*env;
	int		wait;

	env = philo->env;
	if (env->n_philos % 2 == 0)
	{
		if (philo->index % 2 == 0)
			first_think_print(philo, 1);
		return ;
	}
	if (philo->index == 0)
		return ;
	if (philo->index == env->n_philos - 1)
		return (first_think_print(philo, env->time_to_eat));
	if (philo->index % 2 == 1)
	{
		wait = (philo->index - 1) * env->time_to_eat / (env->n_philos - 1);
		return (first_think_print(philo, wait + 1));
	}
	else
	{
		wait = philo->index * env->time_to_eat / (env->n_philos - 1);
		return (first_think_print(philo, wait));
	}
}
