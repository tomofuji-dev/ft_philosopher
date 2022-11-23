/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:53:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/23 12:06:36 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "process.h"
#include "utils.h"
#include "time_utils.h"

void		*process_monitor(void *argv);
static bool	judge_time_to_die(t_philo *philo);

void	*process_monitor(void *argv)
{
	t_monitor	*monitor;
	t_env		*env;
	t_philo		*philo;

	monitor = argv;
	env = monitor->env;
	philo = monitor->obj_philo;
	wait_until(env->start);
	while (env->finish == false)
	{
		pthread_mutex_lock(&(philo->var_mutex));
		pthread_mutex_lock(&(env->finish_mutex));
		if (env->finish == false && judge_time_to_die(philo))
		{
			print_log(philo, timestamp_ms(env->start), "died");
			env->finish = true;
		}
		if (env->n_must_eat != -1 && env->n_already_eat == env->n_philos)
			env->finish = true;
		pthread_mutex_unlock(&(env->finish_mutex));
		pthread_mutex_unlock(&(philo->var_mutex));
		precise_usleep(100);
	}
	return (NULL);
}

static bool	judge_time_to_die(t_philo *philo)
{
	return (timestamp_ms(philo->env->start) - philo->last_meal_time \
			> philo->env->time_to_die);
}
