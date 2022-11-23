/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:32:10 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/23 12:01:51 by t.fuji           ###   ########.fr       */
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

void	print_log(t_philo *philo, int timestamp, char *message)
{
	if (philo->env->finish == false)
		printf("%d %d %s\n", timestamp, philo->index, message);
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
