/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:39:45 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/22 11:28:32 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "close.h"

void	close_all(t_env *env);
void	close_forks(t_mutex *forks, int size);
void	close_philos(t_philo *philos, int size);

void	close_all(t_env *env)
{
	int	i;

	i = 0;
	while (i < env->n_philos)
		pthread_join(env->monitors[i].pthread, NULL);
	while (i < env->n_philos)
		pthread_join(env->philos[i].pthread, NULL);
	close_philos(env->philos, env->n_philos);
	close_forks(env->forks, env->n_philos);
}

void	close_forks(t_mutex *forks, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(forks);
	forks = NULL;
}

void	close_philos(t_philo *philos, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		pthread_mutex_destroy(&(philos[i].var_mutex));
		i++;
	}
	free(philos);
	philos = NULL;
}
