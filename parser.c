/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:21:48 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/23 16:14:26 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



void	init_mutexes(t_params *p)
{
	pthread_mutex_init(&p->g.output, NULL);
	pthread_mutex_init(&p->g.dead, NULL);
	pthread_mutex_init(&p->g.time_eat, NULL);
	pthread_mutex_init(&p->g.finish, NULL);
}

int     parse_philo(t_params *p, char **argv, int ac)
{
	if ((ac == 5 || ac == 6) && alphanumeric(argv, 0, 1))
	{
		p->g.nb_philo = ft_atoi(argv[1]);
		p->g.t_t_die = ft_atoi(argv[2]);
		p->g.t_t_eat = ft_atoi(argv[3]);
		p->g.t_t_sleep = ft_atoi(argv[4]);
		if (ac == 6)
			p->g.must_eat_nb = ft_atoi(argv[5]);
		if (p->g.nb_philo <= 0 || p->g.t_t_die <= 0 || p->g.t_t_eat <= 0
			|| p->g.t_t_sleep <= 0)
			return (0);
		return (1);
	}
	return (0);   
}

void	init_game(t_params *p)
{
	int	i;

	i = 0;
	p->g.start_time = get_time();
	p->g.interrupt = 0;
	p->g.nb_p_action = 0;
	init_mutexes(p);
	while (i < p->g.nb_philo)
	{
		p->ph[i].id = i + 1;
		p->ph[i].ms_eat = 0;
		p->ph[i].done = 0;
		p->ph[i].r_fork = NULL;
		pthread_mutex_init(&p->ph[i].l_fork, NULL);
		if (p->g.nb_philo == 1)
			return (1);
		if (i == p->g.nb_philo - 1)
			p->ph[i].r_fork = &p->ph[0].l_fork;
		else
			p->ph[i].r_fork = &p->ph[i + 1].l_fork;
		i++;
	}
	return (1);
}