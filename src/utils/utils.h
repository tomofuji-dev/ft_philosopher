/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 10:31:31 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/12/03 17:05:16 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "philo.h"

void	precise_usleep(int micros);
void	print_log(t_philo *philo, char *message);
void	wait_until(t_timeval t);
void	first_think_print(t_philo *philo, int ms);
bool	check_finish(t_env	*env);

#endif