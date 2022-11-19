/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:53:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/19 13:52:56 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	*process_monitor(t_philo *monitor)
{
	t_env	*env;

	env = monitor->env;
	wait_until(env->start);
	while (env->finish == false)
	{
		// check now < philo->last_meal_time + env->time_to_die
		// check n_already_eat > n_must_eat
		// if check pass, change finish_mutex change to true
		// if 
	}
}
