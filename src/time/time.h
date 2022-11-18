/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:09:31 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/18 16:42:20 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "philo.h"

int			timestamp_ms(t_timeval start_time);
void		set_start_time(t_env *env);
t_timeval	add_timeval_ms(t_timeval t, int ms);
t_timeval	ms_to_timeval(int ms);

#endif