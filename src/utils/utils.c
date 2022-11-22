/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:32:10 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/22 12:04:42 by tfujiwar         ###   ########.fr       */
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

	gettimeofday(&start, NULL);
	gettimeofday(&now, NULL);
	while (timeval_to_micros(now) - timeval_to_micros(start) < micros)
	{
		usleep(100);
		gettimeofday(&now, NULL);
	}
}

void	print_log(t_philo *philo, char *message)
{
	if (philo->env->finish == false)
		printf("%d %d %s\n", philo->log_time, philo->index, message);
}

void	wait_until(t_timeval t)
{
	t_timeval	now;
	int			diff_micros;

	gettimeofday(&now, NULL);
	diff_micros = timeval_to_micros(t) - timeval_to_micros(now);
	if (diff_micros > 0)
		precise_usleep(diff_micros);
}
