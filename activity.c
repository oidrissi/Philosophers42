/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   activity.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 17:49:07 by oidrissi          #+#    #+#             */
/*   Updated: 2021/10/03 19:10:27 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void	activity(t_philo *p)
{
	int i;

	i = 0;
    while (i < p->g->nb_philo)
	{
		pthred_mutex_lock(&p->id);
		pthread_mutex_lock(&p->r_fork);
		pthread_mutex_lock(&p->l_fork);
		write_status("has taken a fork", p);
		pthread_mutex_unlock(&p->id);
		pthread_mutex_unlock(&p->r_fork);
		pthread_mutex_unlock(&p->l_fork);
		pthread_mutex_lock(&p->id);
		write_status("is eating", p);
		pthread_mutex_unlock(&p->id);
		i++;
	}
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

// void	death(t_philo *ph)
// {
// 	int i;
	
// 	i = 0;
// 	lt_ml_time = get_time(void) - last_time(void);
// 	// check if time consumed since last meal < time to die 
// 	if ( < ph->g->t_t_die)
// 		pthread_mutex_lock(&ph->g->output);
// 		write_status("is sleeping\n", ph);
// 		pthread_mutex_unlock(&ph->g->output);
		
// }