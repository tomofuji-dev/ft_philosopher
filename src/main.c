/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:39:40 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 15:50:48 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "init.h"
#include <stdio.h>
#include <strings.h>

static void	print_timeval(char *s, t_timeval t)
{
	printf("%s%ld.%06ld\n", s, (long)t.tv_sec, (long)t.tv_usec);
}

int	main(int argc, char *argv[])
{
	t_env	env;

	bzero(&env, sizeof(t_env));
	if (init(&env, argc, argv) == false)
		return (1);
	printf("n_philos: %d\n", env.n_philos);
	print_timeval("time_to_die: ", env.time_to_die);
	print_timeval("time_to_eat: ", env.time_to_eat);
	print_timeval("time_to_sleep: ", env.time_to_sleep);
	printf("n_must_eat: %d\n", env.n_must_eat);
}
