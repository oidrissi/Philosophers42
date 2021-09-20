/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 19:21:48 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/20 19:36:20 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int     parse_philo(t_game *game, char **argv, int ac)
{
    game->nb_philo = ft_atoi(argv[1]);
    game->ttdie = ft_atoi(argv[2]);
    game->tteat = ft_atoi(argv[3]);
    game->ttsleep = ft_atoi(argv[4]);
    if (ac == 6)
        game->must_eat_nb = ft_atoi(argv[5]);
}
