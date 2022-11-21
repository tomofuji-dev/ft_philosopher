/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:38:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/21 15:11:55 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>
# include <stdbool.h>

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
	t_timeval		last_meal_time;
	int				n_eat;
	t_mutex			eating_mutex;
	struct s_env	*env;
}	t_philo;

typedef struct s_monitor
{
	t_pthread		pthread;
	int				index;
	t_philo			*obj_philo;
	struct s_env	*env;
}	t_monitor;

typedef struct s_env
{
	int			n_philos;
	t_timeval	time_to_die;
	t_timeval	time_to_eat;
	t_timeval	time_to_sleep;
	int			n_must_eat;
	int			n_already_eat;
	t_timeval	start;
	t_mutex		*forks;
	t_philo		*philos;
	t_monitor	*monitors;
	bool		finish;
	t_mutex		finish_mutex;
}	t_env;

#endif