/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:38:55 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/21 14:46:49 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLOSE_H
# define CLOSE_H

# include "philo.h"

void	close_all(t_env *env);
void	close_forks(t_mutex *forks, int size);
void	close_philos(t_philo *philos, int size);

#endif