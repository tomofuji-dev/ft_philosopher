/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:13:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 14:38:17 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"

typedef struct s_args
{
	int		n_philos;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		n_must_eat;
}	t_args;

bool	arg_parse(t_args *args, int argc, char *argv[]);
bool	init(t_env *env, int argc, char *argv[]);

#endif
