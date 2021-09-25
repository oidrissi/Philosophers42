/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:20 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/25 15:35:18 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*death(void	*data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->g->t_t_die + 1);
	pthread_mutex_lock(&ph->g->t_t_eat);
	pthread_mutex_lock(&ph->g->done);
	if (!check_death(ph, 0) && !ph->done && ((actual_time() - ph->ms_eat) \
		>= (long)(ph->g->t_t_die)))
	{
		pthread_mutex_unlock(&ph->g->t_t_eat);
		pthread_mutex_unlock(&ph->g->done);
		pthread_mutex_lock(&ph->g->output);
		write_status("died\n", ph);
		pthread_mutex_unlock(&ph->g->output);
		check_death(ph, 1);
	}
	pthread_mutex_unlock(&ph->g->t_t_eat);
	pthread_mutex_unlock(&ph->g->done);
	return (NULL);
}

void	*thread(void *data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->g->t_t_eat / 10);
	while (!check_death(ph, 0))
	{
		pthread_create(&ph->death_thread_id, NULL, death, data);
		activity(ph);
		pthread_detach(ph->death_thread_id);
		if ((int)++ph->nb_ate == ph->g->must_eat_nb)
		{
			pthread_mutex_lock(&ph->g->done);
			ph->done = 1;
			ph->g->done++;
			if (ph->g->done == ph->g->nb_p_action)
			{
				pthread_mutex_unlock(&ph->g->done);
				check_death(ph, 2);
			}
			pthread_mutex_unlock(&ph->g->done);
			return (NULL);
		}
	}
	return (NULL);
}

int	threading(t_params *p)
{
	int	i;

	i = 0;
	while (i < p->g.nb_philo)
	{
		p->ph[i].g = &p->g;
		if (pthread_create(&p->ph[i].thread_id, NULL, thread,
				&p->ph[i] != 0))
			return (0);
		i++;
	}
	return (1);
}
