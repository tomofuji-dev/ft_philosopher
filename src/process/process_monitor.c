/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:53:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/03 12:30:04 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include "process.h"
#include "utils.h"
#include "time_utils.h"

void		*process_monitor(void *argv);
static void	monitor_philo(t_env *env, int index);
static bool	judge_time_to_die(t_philo *philo);

void	*process_monitor(void *argv)
{
	t_env	*env;
	int		i;

	env = argv;
	wait_until(env->start);
	while (1)
	{
		pthread_mutex_lock(&(env->finish_mutex));
		i = 0;
		while (i < env->n_philos && env->finish == false)
		{
			monitor_philo(env, i);
			i++;
		}
		if (env->finish == true)
		{
			pthread_mutex_unlock(&(env->finish_mutex));
			break ;
		}
		pthread_mutex_unlock(&(env->finish_mutex));
		precise_usleep(800);
	}
	return (NULL);
}

static void	monitor_philo(t_env *env, int index)
{
	t_philo	*philo;

	philo = &(env->philos[index]);
	pthread_mutex_lock(&(philo->var_mutex));
	if (env->finish == false && judge_time_to_die(philo))
	{
		printf("%d %d %s\n", timestamp_ms(philo->env->start), \
				philo->index + 1, "died");
		env->finish = true;
	}
	if (env->n_must_eat != -1 && env->n_already_eat == env->n_philos)
		env->finish = true;
	pthread_mutex_unlock(&(philo->var_mutex));
}

static bool	judge_time_to_die(t_philo *philo)
{
	return (timestamp_ms(philo->env->start) - philo->last_meal_time \
			> philo->env->time_to_die);
}
