/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:39:45 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/18 17:30:52 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "close.h"

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
		pthread_mutex_destroy(&philos[i].eating_mutex);
		i++;
	}
	free(philos);
	philos = NULL;
}