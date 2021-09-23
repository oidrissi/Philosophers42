/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 18:07:37 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/23 18:08:30 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long long	time_ms(void)
{
	struct timeval	te;
	long long		ms;

	gettimeofday(&te, NULL);
	ms = te.tv_sec * 1000LL + te.tv_usec / 1000;
	return (ms);
}