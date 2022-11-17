/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:13:33 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 16:28:00 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_H
# define ARGS_H

# include "philo.h"

typedef struct s_args
{
	int		n_philos;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		n_must_eat;
}	t_args;

bool	arg_parse(t_args *args, int argc, char *argv[]);
bool	arg_to_env(t_env *env, int argc, char *argv[]);

#endif
