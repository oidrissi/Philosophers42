/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 18:16:28 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/25 15:41:10 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
    t_params  *game;
    
	game = (t_params *)malloc(sizeof(t_params));
    if (ac != 4)
        return (0);
    parse_philo(game, av, ac);
    game->ph = (t_philo *)malloc(sizeof(t_philo) * game->g.nb_philo);
    if (!game->ph)
		return (0);
	
}