/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:19:28 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 14:38:11 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include <strings.h>
#include <limits.h>

bool		arg_parse(t_args *args, int argc, char *argv[]);
static bool	check_all_digit(int argc, char *argv[]);
static int	ft_isdigit(int c);
static int	parse_int(char *str);
static long	parse_long(char *str);

bool	arg_parse(t_args *args, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (false);
	if (check_all_digit(argc, argv) == false)
		return (false);
	bzero(args, sizeof(t_args));
	args->n_philos = parse_int(argv[1]);
	args->time_to_die = parse_long(argv[2]);
	args->time_to_eat = parse_long(argv[3]);
	args->time_to_sleep = parse_long(argv[4]);
	if (argc == 6)
		args->n_must_eat = parse_int(argv[4]);
	if (args->n_philos == -1 || args->time_to_die == -1 \
		|| args->time_to_eat == -1 || args->time_to_sleep == -1 \
		|| args->n_must_eat == -1)
		return (NULL);
	if (argc == 5)
		args->n_must_eat = -1;
	return (true);
}

static bool	check_all_digit(int argc, char *argv[])
{
	int	i;

	i = 0;
	while (i < argc)
	{
		while (*argv[i])
		{
			if (ft_isdigit(*argv[i]) == 0)
				return (false);
			argv[i]++;
		}
		i++;
	}
	return (true);
}

static int	ft_isdigit(int c)
{
	return ((c >= '0') && (c <= '9'));
}

static int	parse_int(char *str)
{
	int	n;
	int	d;

	n = 0;
	while (*str)
	{
		d = *str++ - '0';
		if (n <= (INT_MAX - d) / 10)
			n = 10 * n + d;
		else
			return (-1);
	}
	return (n);
}

static long	parse_long(char *str)
{
	long	n;
	long	d;

	n = 0;
	while (*str)
	{
		d = *str++ - '0';
		if (n <= (LONG_MAX - d) / 10)
			n = 10 * n + d;
		else
			return (-1);
	}
	return (n);
}
