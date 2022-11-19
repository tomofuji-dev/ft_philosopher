/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_monitor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 09:53:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/19 10:24:37 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process.h"

void	*process_monitor(t_monitor *monitor)
{
	t_env	*env;

	env = monitor->env;
	usleep(-1 * timestamp_ms(env->start) * 1000);
	while (env->finish == false)
	{
		
	}
}
