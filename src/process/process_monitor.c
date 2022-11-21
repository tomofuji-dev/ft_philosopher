/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:53:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/21 14:37:49 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void		*process_monitor(t_philo *monitor);
static bool	judge_time_to_die(t_timeval t);

void	*process_monitor(t_philo *monitor)
{
	t_env		*env;
	t_philo		*philo;
	t_timeval	now;

	env = monitor->env;
	philo = monitor->philo;
	wait_until(env->start);
	while (env->finish == false)
	{
		pthread_mutex_lock(&(philo->eating_mutex));
		pthread_mutex_lock(&(env->finish_mutex));
		now = gettimeofday(&now, NULL);
		if (env->finish == false && judge_time_to_die(now))
		{
			print_log(timestamp_ms(env->start), philo->index, "died");
			env->finish = true;
		}
		if (env->n_must_eat != -1 && env->n_already_eat == env->n_must_eat)
			env->finish = true;
		pthread_mutex_unlock(&(env->finish_mutex));
		pthread_mutex_unlock(&(philo->eating_mutex));
	}
	return (NULL);
}

static bool	judge_time_to_die(t_timeval t)
{
	return (timeval_to_micros(t) - timeval_to_micros(philo->last_meal_time) \
			> timeval_to_micros(env->time_to_die));
}
