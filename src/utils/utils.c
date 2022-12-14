/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:32:10 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/03 17:45:01 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "time_utils.h"
#include <stdio.h>
#include <unistd.h>

void	precise_usleep(int micros)
{
	t_timeval	start;
	t_timeval	now;
	int			end;

	gettimeofday(&start, NULL);
	end = timeval_to_ms(start) * 1000 + micros;
	now = start;
	while (timeval_to_ms(now) * 1000 < end)
	{
		usleep(100);
		gettimeofday(&now, NULL);
	}
}

void	print_log(t_philo *philo, char *message)
{
	pthread_mutex_lock(&(philo->env->finish_mutex));
	if (philo->env->finish == false)
		printf("%d %d %s\n", timestamp_ms(philo->env->start), \
				philo->index + 1, message);
	pthread_mutex_unlock(&(philo->env->finish_mutex));
}

void	wait_until(t_timeval t)
{
	t_timeval	now;
	int			diff_ms;

	gettimeofday(&now, NULL);
	diff_ms = timeval_to_ms(t) - timeval_to_ms(now);
	if (diff_ms > 0)
		precise_usleep(diff_ms * 1000);
}

void	first_think_print(t_philo *philo, int ms)
{
	print_log(philo, "is thinking");
	wait_until(add_timeval(philo->env->start, ms_to_timeval(ms)));
}

bool	check_finish(t_env	*env)
{
	bool	finish;

	pthread_mutex_lock(&env->finish_mutex);
	finish = env->finish;
	pthread_mutex_unlock(&env->finish_mutex);
	return (finish);
}
