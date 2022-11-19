/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:09:31 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/19 11:19:10 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_H
# define TIME_H

# include "philo.h"

int			timestamp_ms(t_timeval start_time);
t_timeval	add_timeval(t_timeval t1, t_timeval t2);
t_timeval	ms_to_timeval(int ms);
int			timeval_to_micros(t_timeval t);

#endif