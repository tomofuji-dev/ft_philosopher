/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: t.fuji <t.fuji@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 10:19:28 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/30 16:29:11 by t.fuji           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "args.h"
#include <strings.h>
#include <limits.h>

bool		arg_parse(t_args *args, int argc, char *argv[]);
static bool	check_all_digit(int argc, char *argv[]);
static int	ft_isdigit(int c);
static int	parse_int(char *str);
static bool	check_args(t_args *args);

bool	arg_parse(t_args *args, int argc, char *argv[])
{
	if (argc != 5 && argc != 6)
		return (false);
	if (check_all_digit(argc, argv) == false)
		return (false);
	args->n_philos = parse_int(argv[1]);
	args->time_to_die = parse_int(argv[2]);
	args->time_to_eat = parse_int(argv[3]);
	args->time_to_sleep = parse_int(argv[4]);
	if (argc == 6)
		args->n_must_eat = parse_int(argv[5]);
	if (check_args(args) == false)
		return (false);
	if (argc == 5)
		args->n_must_eat = -1;
	return (true);
}

static bool	check_all_digit(int argc, char *argv[])
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (false);
			j++;
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

static bool	check_args(t_args *args)
{
	if (args->n_philos <= 0 || args->n_philos > 200 \
		|| args->time_to_die < 60 || args->time_to_eat < 60 \
		|| args->time_to_sleep < 60 || args->n_must_eat == -1)
		return (false);
	return (true);
}
