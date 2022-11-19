/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:26:14 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/19 11:29:07 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <stdlib.h>
#include <strings.h>

bool		init_forks(t_env *env);
bool		init_philos(t_env *env);
static bool	init_a_philo(t_env *env, int index);

bool	init_forks(t_env *env)
{
	int	i;

	env->forks = malloc(env->n_philos * sizeof(t_mutex));
	if (env->forks == NULL)
		return (false);
	bzero(env->forks, env->n_philos * sizeof(t_mutex));
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
	bzero(env->philos, env->n_philos * sizeof(t_philo));
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
}

static bool	init_a_philo(t_env *env, int index)
{
	t_philo	*philo;

	philo = &(env->philos[index]);
	if (pthread_create(&(philo->pthread), NULL, process_philo, philo) != 0)
		return (false);
	philo->index = index;
	if (index == 0)
	{
		philo->left_fork = &(env->forks[env->n_philos - 1]);
		philo->right_fork = &(env->forks[index]);
	}
	else
	{
		philo->left_fork = &(env->forks[index]);
		philo->right_fork = &(env->forks[index - 1]);
	}
	philo->status = THINK;
	philo->last_meal_time = env->start;
	philo->n_eat = 0;
	if (pthread_mutex_init(&(philo->eating_mutex), NULL) != 0)
		return (false);
	philo->env = env;
	return (false);
}

bool	init_monitors(t_env *env)
{
	int	i;

	env->monitors = malloc(env->n_philos * sizeof(t_monitor));
	if (env->monitors == NULL)
		return (false);
	bzero(env->monitors, env->n_philos * sizeof(t_monitor));
	i = 0;
	while (i < env->n_philos)
	{
		if (pthread_create(&(env->monitors[i].pthread), \
							NULL, process_monitor, &(env->monitors[i])) != 0)
		{
			free(env->monitors);
			return (false);
		}
		env->monitors[i].index = i;
		env->monitors[i].obj_philo = &(env->philos[i]);
		env->monitors[i].env = env;
		i++;
	}
}
