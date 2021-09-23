/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:20 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/23 18:02:54 by oidrissi         ###   ########.fr       */
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

void	print_status(t_params *p, int pid, char *string)
{
	pthread_mutex_lock(&p->g.output);
	printf("%lld %d %s", actual_time() - p->g.start_time, pid + 1, string);
	if (string[0] != 'd')
		pthread_mutex_unlock(&p->write);
}

void	ft_usleep(int i)
{
	usleep(i);
}

void	*thread(void *data)
{
	t_philo					*ph;

	ph = (t_philo *)data;
	if (ph->id % 2 == 0)
		ft_usleep(ph->g->t_t_eat / 10);
	while (!check_death(ph, 0))
	{
		pthread_create(&ph->thread_death_id, NULL, is_dead, data);
		activity(ph);
		pthread_detach(ph->thread_death_id);
		if ((int)++ph->nb_eat == ph->pa->must_eat_nb)
		{
			pthread_mutex_lock(&ph->pa->finish);
			ph->finish = 1;
			ph->pa->nb_p_finish++;
			if (ph->pa->nb_p_finish == ph->pa->total)
			{
				pthread_mutex_unlock(&ph->pa->finish);
				check_death(ph, 2);
			}
			pthread_mutex_unlock(&ph->pa->finish);
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
