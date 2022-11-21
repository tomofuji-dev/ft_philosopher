/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:46:07 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/21 15:17:38 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "philo.h"
# include "args.h"

bool		init(t_env *env, int argc, char *argv[]);
bool		init_forks(t_env *env);
bool		init_philos(t_env *env);
bool		init_monitors(t_env *env);

#endif