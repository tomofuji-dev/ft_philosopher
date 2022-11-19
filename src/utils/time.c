/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:09:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/19 11:19:31 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

int			timestamp_ms(t_timeval start_time);
void		set_start_time(t_env *env);
t_timeval	add_timeval(t_timeval t1, t_timeval t2);
t_timeval	ms_to_timeval(int ms);
int			timeval_to_micros(t_timeval t);

int	timestamp_ms(t_timeval start_time)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return ((int)(now.tv_sec - start_time.tv_sec) * 1000 \
			+ (int)(now.tv_usec - start_time.tv_usec) / 1000;
}

t_timeval	add_timeval(t_timeval t1, t_timeval t2)
{
	t_timeval	added_timeval;

	added_timeval.tv_usec = t1.tv_usec + t2.tv_usec;
	added_timeval.tv_sec = t1.tv_sec + t2.tv_sec + added_timeval.tv_usec / 1000000;
	added_timeval.tv_usec %= 1000000;
	return (t);
}

t_timeval	ms_to_timeval(int ms)
{
	return ((t_timeval){
		.tv_sec = ms / 1000,
		.tv_usec = (ms % 1000) * 1000
	});
}

int	timeval_to_micros(t_timeval t)
{
	return (t.tv_sec * 1000000 + t.tv_usec);
}
