/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:49:07 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/24 17:55:36 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	activity(t_philo *p)
{
    
}

void	sleep_think(t_philo *ph)
{
	pthread_mutex_lock(&ph->g->output);
	write_status("is sleeping\n", ph);
	pthread_mutex_unlock(&ph->g->output);
	ft_usleep(ph->g->sleep);
	pthread_mutex_lock(&ph->g->output);
	write_status("is thinking\n", ph);
	pthread_mutex_unlock(&ph->g->output);
}