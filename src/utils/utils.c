/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:32:10 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/19 11:12:44 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "time.h"
#include <stdio.h>

void	print_log(int timestamp, int philo_index, char *message)
{
	printf("%d %d %s\n", timestamp, philo_index, message);
}

void	wait_until(t_timeval t)
{
	t_timeval	now;
	int			diff_micros;

	gettimeofday(&now, NULL);
	diff_micros = timeval_to_micros(t) - timeval_to_micros(now);
	if (diff_micros > 0)
		usleep(diff_micros);
}
