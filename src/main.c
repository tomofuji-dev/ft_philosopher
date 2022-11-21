/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 08:39:40 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/21 16:31:44 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "init.h"
#include "close.h"
#include "time_utils.h"
#include <stdio.h>
#include <strings.h>

int	main(int argc, char *argv[])
{
	t_env	env;

	bzero(&env, sizeof(t_env));
	if (init(&env, argc, argv) == false)
		return (1);
	close_all(&env);
}
