/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/23 16:09:20 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/23 16:29:11 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str)
		i++;
	return (0);
}

void	print_mutexes(t_philo *p)
{
	
}

void	thread(t_params *p)
{
	
}

int	threading(t_params *p)
{
    int i;
    
    i = 0;
    while (i < p->g.nb_philo)
        pthread_create(&p->ph[i].thread_id, NULL, thread, &p->ph[i]);
    
}