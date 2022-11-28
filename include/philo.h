/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:38:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/28 13:29:20 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>

typedef struct timeval	t_timeval;
typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_pthread;

typedef enum e_philo_status
{
	EAT,
	SLEEP,
	THINK
}	t_philo_status;

typedef struct s_philo
{
	t_pthread		pthread;
	int				index;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	t_philo_status	status;
	int				last_meal_time;
	int				n_eat;
	t_mutex			var_mutex;
	struct s_env	*env;
}	t_philo;

typedef struct s_env
{
	int			n_philos;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			n_must_eat;
	int			n_already_eat;
	t_timeval	start;
	t_mutex		*forks;
	t_philo		*philos;
	t_pthread	monitor;
	bool		finish;
	t_mutex		finish_mutex;
}	t_env;

#endif