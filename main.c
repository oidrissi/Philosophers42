/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:16:28 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/21 10:36:15 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int  

int	main(int ac, char **av)
{
    t_game  *game;
    
	game = (t_game *)malloc(sizeof(t_game));
    if (ac != 4)
        return (0);
    parse_philo(game);
    game->philo = (t_philo *)malloc(sizeof(t_philo) * game->nb_philo);
    if (!game->philo)
		return (0);
	
}