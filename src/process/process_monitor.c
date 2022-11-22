/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:53:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/22 11:28:39 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "process.h"
#include "utils.h"
#include "time_utils.h"

void		*process_monitor(void *argv);
static bool	judge_time_to_die(t_philo *philo, t_timeval t);

void	*process_monitor(void *argv)
{
	t_monitor	*monitor;
	t_env		*env;
	t_philo		*philo;
	t_timeval	now;

	monitor = argv;
	env = monitor->env;
	philo = monitor->obj_philo;
	wait_until(env->start);
	while (env->finish == false)
	{
		pthread_mutex_lock(&(philo->var_mutex));
		pthread_mutex_lock(&(env->finish_mutex));
		gettimeofday(&now, NULL);
		if (env->finish == false && judge_time_to_die(philo, now))
		{
			print_log(timestamp_ms(env->start), philo->index, "died");
			env->finish = true;
		}
		if (env->n_must_eat != -1 && env->n_already_eat == env->n_must_eat)
			env->finish = true;
		pthread_mutex_unlock(&(env->finish_mutex));
		pthread_mutex_unlock(&(philo->var_mutex));
	}
	return (NULL);
}

static bool	judge_time_to_die(t_philo *philo, t_timeval t)
{
	return (timeval_to_micros(t) - timeval_to_micros(philo->last_meal_time) \
			> timeval_to_micros(philo->env->time_to_die));
}
