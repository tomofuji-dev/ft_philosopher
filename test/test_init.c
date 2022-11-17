/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:54:00 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 14:42:20 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "init.h"
#include <stdio.h>

static void	print_timeval(char *s, t_timeval t)
{
	printf("%s%ld.%06ld\n", s, (long)t.tv_sec, (long)t.tv_usec);
}

int	main(int argc, char *argv[])
{
	t_env	env;

	if (init(&env, argc, argv) == false)
		return (1);
	printf("n_philos: %d\n", env.n_philos);
	print_timeval("time_to_die: ", env.time_to_die);
	print_timeval("time_to_eat: ", env.time_to_eat);
	print_timeval("time_to_sleep: ", env.time_to_sleep);
	printf("n_must_eat: %d\n", env.n_must_eat);
}
