/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:20 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/24 17:56:28 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str)
		i++;
	return (0);
}

void	print_status(t_grams *p, int pid, char *string)
{
	pthread_mutex_lock(&p->g.output);
	printf("%lld %d %s", get_time() - p->g.start_time, pid + 1, string);
	if (string[0] != 'd')
		pthread_mutex_unlock(&p->write);
}

void	*death(void	*data)
{
	t_philo	*ph;

	ph = (t_philo *)data;
	ft_usleep(ph->g->die + 1);
	pthread_mutex_lock(&ph->g->time_eat);
	pthread_mutex_lock(&ph->g->finish);
	if (!check_death(ph, 0) && !ph->finish && ((actual_time() - ph->ms_eat) \
		>= (long)(ph->g->die)))
	{
		pthread_mutex_unlock(&ph->g->time_eat);
		pthread_mutex_unlock(&ph->g->finish);
		pthread_mutex_lock(&ph->g->write_mutex);
		write_status("died\n", ph);
		pthread_mutex_unlock(&ph->g->write_mutex);
		check_death(ph, 1);
	}
	pthread_mutex_unlock(&ph->g->time_eat);
	pthread_mutex_unlock(&ph->g->finish);
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
		pthread_create(&ph->thread_death_id, NULL, death, data);
		activity(ph);
		pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_eat == ph->g->must_eat_nb)
		{
			pthread_mutex_lock(&ph->g->finish);
			ph->done = 1;
			ph->g->nb_p_finish++;
			if (ph->g->nb_p_finish == ph->g->total)
			{
				pthread_mutex_unlock(&ph->g->finish);
				check_death(ph, 2);
			}
			pthread_mutex_unlock(&ph->g->finish);
			return (NULL);
		}
	}
	return (NULL);
}

int	threading(t_grams *p)
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
