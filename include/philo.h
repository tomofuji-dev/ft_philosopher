/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:38:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/18 14:53:47 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

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
	t_pthread		*pthread;
	int				index;
	int				left_fork;
	int				right_fork;
	t_philo_status	status;
	t_timeval		last_meal_time;
	int				n_eat;
	t_mutex			eating_mutex;
}	t_philo;

typedef struct s_monitor
{
	t_pthread	*pthread;
	int			index;
	t_philo		obj_philo;
}	t_monitor;

typedef struct s_env
{
	int			n_philos;
	t_timeval	time_to_die;
	t_timeval	time_to_eat;
	t_timeval	time_to_sleep;
	int			n_must_eat;
	t_timeval	start;
	t_philo		*philos;
	t_mutex		*forks;
	t_monitor	*monitors;
	bool		finish;
	t_mutex		*finish_mutex;
}	t_env;

#endif