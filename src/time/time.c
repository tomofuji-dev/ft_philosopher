/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:09:37 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/18 16:42:00 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time.h"

int			timestamp_ms(t_timeval start_time);
void		set_start_time(t_env *env);
t_timeval	add_timeval_ms(t_timeval t, int ms);
t_timeval	ms_to_timeval(int ms);

int	timestamp_ms(t_timeval start_time)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	return ((int)(now.tv_sec - start_time.tv_sec) * 1000 \
			+ (int)(now.tv_usec - start_time.tv_usec) / 1000;
}

void	set_start_time(t_env *env)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	env->start = add_timeval_ms(now, WAIT_UNTIL_START);
}

t_timeval	add_timeval_ms(t_timeval t, int ms)
{
	t_timeval	interval;

	interval = ms_to_timeval(ms);
	t.tv_usec += t.tv_usec;
	t.tv_sec += t.tv_sec + t.tv_usec / 1000000;
	t.tv_usec %= 1000000;
	return (t);
}

t_timeval	ms_to_timeval(int ms)
{
	return ((t_timeval){
		.tv_sec = ms / 1000,
		.tv_usec = (ms % 1000) * 1000
	});
}
