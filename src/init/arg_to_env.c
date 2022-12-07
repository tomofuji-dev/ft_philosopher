/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_to_env.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:14:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/07 14:35:41 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include "time_utils.h"
#include <strings.h>

bool	arg_to_env(t_env *env, int argc, char *argv[])
{
	t_args	args;

	memset(&args, 0, sizeof(t_args));
	if (arg_parse(&args, argc, argv) == false)
		return (false);
	env->n_philos = args.n_philos;
	env->time_to_die = args.time_to_die;
	env->time_to_eat = args.time_to_eat;
	env->time_to_sleep = args.time_to_sleep;
	env->n_must_eat = args.n_must_eat;
	env->n_already_eat = 0;
	return (true);
}
