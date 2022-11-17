/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfujiwar <tfujiwar@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:47:29 by tfujiwar          #+#    #+#             */
/*   Updated: 2022/11/17 15:53:34 by tfujiwar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

bool	init(t_env *env, int argc, char *argv[])
{
	if (arg_to_env(env, argc, argv) == false)
		return (false);
	return (true);
}
