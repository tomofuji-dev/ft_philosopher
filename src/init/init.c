/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:47:29 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/28 14:27:41 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "time_utils.h"
#include "close.h"

#define MS_UNTIL_START 1000

bool		init(t_env *env, int argc, char *argv[]);
static bool	init_env(t_env *env);
static void	set_start_time(t_env *env);

bool	init(t_env *env, int argc, char *argv[])
{
	if (arg_to_env(env, argc, argv) == false)
		return (false);
	if (init_env(env) == false)
		return (false);
	return (true);
}

static bool	init_env(t_env *env)
{
	set_start_time(env);
	if (init_forks(env) == false)
		return (false);
	if (init_philos(env) == false)
	{
		close_forks(env->forks, env->n_philos);
		return (false);
	}
	if (init_monitor(env) == false)
	{
		env->finish = true;
		close_philos(env->philos, env->n_philos);
		close_forks(env->forks, env->n_philos);
		return (false);
	}
	env->finish = false;
	if (pthread_mutex_init(&(env->finish_mutex), NULL) != 0)
	{
		env->finish = true;
		close_philos(env->philos, env->n_philos);
		close_forks(env->forks, env->n_philos);
		return (false);
	}
	return (true);
}

static void	set_start_time(t_env *env)
{
	t_timeval	now;

	gettimeofday(&now, NULL);
	now.tv_usec /= 1000;
	now.tv_usec *= 1000;
	env->start = add_timeval(now, ms_to_timeval(MS_UNTIL_START));
}
