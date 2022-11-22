/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:09:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/22 13:09:43 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_utils.h"

int			timestamp_ms(t_timeval start_time);
void		set_start_time(t_env *env);
t_timeval	add_timeval(t_timeval t1, t_timeval t2);
t_timeval	ms_to_timeval(int ms);
int			timeval_to_ms(t_timeval t);

int	timestamp_ms(t_timeval start_time)
{
	t_timeval	now;
	int			t;

	gettimeofday(&now, NULL);
	t = (now.tv_sec - start_time.tv_sec) * 10000 \
			+ (now.tv_usec - start_time.tv_usec) / 100;
	return (t / 10);
}

t_timeval	add_timeval(t_timeval t1, t_timeval t2)
{
	t_timeval	sum;

	sum.tv_usec = t1.tv_usec + t2.tv_usec;
	sum.tv_sec = t1.tv_sec + t2.tv_sec + sum.tv_usec / 1000000;
	sum.tv_usec %= 1000000;
	return (sum);
}

t_timeval	ms_to_timeval(int ms)
{
	return ((t_timeval){
		.tv_sec = ms / 1000,
		.tv_usec = (ms % 1000) * 1000
	});
}

int	timeval_to_ms(t_timeval t)
{
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}
