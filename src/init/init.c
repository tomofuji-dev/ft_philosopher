/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:47:29 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/18 15:38:28 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>
#include <strings.h>

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
	setup start;
	if (init_fork(env) == false)
		return (false);
	if (init_philos(env) == false)
	{
		close_forks(env->forks, env->n_philos);
		return (false);
	}
	if (init_monitors(env) == false)
	{
		close_philos(env->philos, env->n_philos);
		close_fork(env->forks, env->n_philos);
		return (false);
	}
	setup_finish_mutex;
}

bool	init_fork(t_env *env)
{
	int	i;

	env->forks = malloc(env->n_philos * sizeof(t_mutex));
	if (env->forks == NULL)
		return (false);
	bzero(env->forks, env->n_philos * sizeof(t_mutex));
	i = 0;
	while (i < env->n_philos)
	{
		if (pthread_mutex_init(&env->forks[i], NULL) != 0)
		{
			close_forks(env->forks, i);
			return (false);
		}
		i++;
	}
	return (true);
}

bool	init_philos(t_env *env)
{
	int	i;

	while
	env->philos = malloc(env->n_philos * sizeof(t_philo));
	if (env->philos == NULL)
		return (false);
	bzero(env->philos, env->n_philos * sizeof(t_philo));
	i = 0;
	while (i < env->n_philos)
	{
		if (init_a_philo(env, i) == false)
		{
			close_philos(env->forks, i);
			return (false);
		}
		i++;
	}

}
