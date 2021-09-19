/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:16:28 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/19 18:46:11 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
    t_game  game;
	t_philo *philo;
    

    if (ac != 4)
        return (0);
    parse_philo(game);
    philo = (t_philo)malloc(sizeof(t_philo) * game->nb_philo)
}