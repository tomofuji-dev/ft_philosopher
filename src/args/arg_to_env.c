/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:14:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 15:51:52 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include <strings.h>

bool				arg_to_env(t_env *env, int argc, char *argv[]);
static t_timeval	ms_to_timeval(long ms);

bool	arg_to_env(t_env *env, int argc, char *argv[])
{
	t_args	args;

	bzero(&args, sizeof(t_args));
	if (arg_parse(&args, argc, argv) == false)
		return (false);
	env->n_philos = args.n_philos;
	env->time_to_die = ms_to_timeval(args.time_to_die);
	env->time_to_eat = ms_to_timeval(args.time_to_eat);
	env->time_to_sleep = ms_to_timeval(args.time_to_sleep);
	env->n_must_eat = args.n_must_eat;
	return (true);
}

static t_timeval	ms_to_timeval(long ms)
{
	return ((t_timeval){
		.tv_sec = ms / 1000,
		.tv_usec = (ms % 1000) * 1000
	});
}
