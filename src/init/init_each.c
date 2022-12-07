/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:26:14 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/07 14:36:02 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "process.h"
#include "close.h"
#include <stdlib.h>
#include <strings.h>

bool		init_forks(t_env *env);
bool		init_philos(t_env *env);
static bool	init_a_philo(t_env *env, int index);
bool		init_monitor(t_env *env);

bool	init_forks(t_env *env)
{
	int	i;

	env->forks = malloc(env->n_philos * sizeof(t_mutex));
	if (env->forks == NULL)
		return (false);
	memset(env->forks, 0, env->n_philos * sizeof(t_mutex));
	i = 0;
	while (i < env->n_philos)
	{
		if (pthread_mutex_init(&(env->forks[i]), NULL) != 0)
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

	env->philos = malloc(env->n_philos * sizeof(t_philo));
	if (env->philos == NULL)
		return (false);
	memset(env->philos, 0, env->n_philos * sizeof(t_philo));
	i = 0;
	while (i < env->n_philos)
	{
		if (init_a_philo(env, i) == false)
		{
			close_philos(env->philos, i);
			return (false);
		}
		i++;
	}
	return (true);
}

static bool	init_a_philo(t_env *env, int index)
{
	t_philo	*philo;

	philo = &(env->philos[index]);
	philo->env = env;
	philo->index = index;
	if (index % 2 == 0)
	{
		philo->left_fork = &(env->forks[index]);
		if (index == 0)
			philo->right_fork = &(env->forks[env->n_philos - 1]);
		else
			philo->right_fork = &(env->forks[index - 1]);
	}
	else
	{
		philo->left_fork = &(env->forks[index - 1]);
		philo->right_fork = &(env->forks[index]);
	}
	philo->status = THINK;
	if (pthread_create(&(philo->pthread), NULL, process_philo, philo) != 0)
		return (false);
	if (pthread_mutex_init(&(philo->var_mutex), NULL) != 0)
		return (false);
	return (true);
}

bool	init_monitor(t_env *env)
{
	if (pthread_create(&(env->monitor), \
						NULL, process_monitor, env) == 0)
		return (true);
	return (false);
}
