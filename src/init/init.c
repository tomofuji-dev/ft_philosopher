/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:14:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 14:40:18 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <strings.h>

bool				init(t_env *env, int argc, char *argv[]);
static void			set_env_from_args(t_env *env, t_args *args);
static t_timeval	ms_to_timeval(long ms);

bool	init(t_env *env, int argc, char *argv[])
{
	t_args	args;

	if (arg_parse(&args, argc, argv) == false)
		return (false);
	bzero(env, sizeof(t_env));
	set_env_from_args(env, &args);
	return (true);
}

static void	set_env_from_args(t_env *env, t_args *args)
{
	env->n_philos = args->n_philos;
	env->time_to_die = ms_to_timeval(args->time_to_die);
	env->time_to_eat = ms_to_timeval(args->time_to_die);
	env->time_to_sleep = ms_to_timeval(args->time_to_die);
	env->n_must_eat = args->n_must_eat;
}

static t_timeval	ms_to_timeval(long ms)
{
	return ((t_timeval){
		.tv_sec = ms / 1000,
		.tv_usec = (ms % 1000) * 1000
	});
}
