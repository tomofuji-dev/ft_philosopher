/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:38:54 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 14:12:49 by tfujiwar         ###   ########.fr       */
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
	THINK,
	TAKE_FORK
}	t_philo_status;

typedef struct s_fork_order
{
	int	left;
	int	right;
}	t_fork_order;

typedef struct s_philo
{
	int				index;
	t_pthread		*pthread;
	t_fork_order	fork_order;
	t_philo_status	status;
	t_timeval		last_meal_time;
	int				n_eat;
}	t_philo;

typedef struct s_table
{
	t_philo	*philos;
	t_mutex	*forks;
}	t_table;

typedef struct s_env
{
	int			n_philos;
	t_timeval	start;
	t_timeval	time_to_die;
	t_timeval	time_to_eat;
	t_timeval	time_to_sleep;
	int			n_must_eat;
	t_table		*table;
}	t_env;

#endif