/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:03:14 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/25 15:36:29 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include <stdio.h>		//	printf
# include <stdlib.h>	//	malloc
# include <string.h>	//	memset
# include <unistd.h>	//	usleep
# include <sys/time.h>	//	gettimeofday(struct timeval *restrict tv,
                    	//	struct timezone *restrict tz);
# include <pthread.h>	// 1 - int pthread_create(pthread_t *restrict thread, ------->  The pthread_create() function starts a new thread in the calling
       					//	process.  The new thread starts execution by invoking
       					//	start_routine(); arg is passed as the sole argument of
       					//	start_routine().
                    	//  const pthread_attr_t *restrict attr,
                        //  void *(*start_routine)(void *),
                        //  void *restrict arg);
						
						//	2 - int pthread_detach(pthread_t thread); detach a thread from process
						//	3 - pthread_join -->  The pthread_join() function waits for the thread specified by
       					//	thread to terminate.  If that thread has already terminated, then
						//	pthread_join() returns immediately.  The thread specified by
						//	thread must be joinable.
						//	4 - pthread_mutex_init --> pthread_mutex_init, pthread_mutex_destroy - initialise or destroy a mutex
						//	The pthread_mutex_init() function initialises the mutex referenced by mutex with attributes specified by attr. If attr is NULL,
						//	the default mutex attributes are used; the effect is the same as passing the address of a default mutex attributes object. Upon
						//	successful initialisation, the state of the mutex becomes initialised and unlocked.
						//	5 - int pthread_mutex_lock(pthread_mutex_t *mutex);
						//	6 - int pthread_mutex_unlock(pthread_mutex_t *mutex);
						

typedef	struct	s_game
{
	pthread_mutex_t	output;
	pthread_mutex_t	dead;
	pthread_mutex_t	time_eat;
	pthread_mutex_t	finish;
	int				nb_philo;
	int				nb_p_action;
	long long		start_time;
	int				interrupt;
	int				t_t_die;
	int				t_t_sleep;
	int				t_t_eat;
	int				must_eat_nb;
	int				done;
	
}	t_game;

typedef	struct s_philo
{
	int					id;
	long int			ms_eat;
	pthread_mutex_t		l_fork;
	pthread_mutex_t		*r_fork;
	pthread_t			thread_id;
	pthread_t			death_thread_id;
	int					h_t_forks;
	unsigned int		nb_ate;
	int					done;
	char				*status;
	t_game				*g;
	
}	t_philo;

typedef struct	s_params
{
	t_game	g;
	t_philo	*ph;
	
}	t_params;

int	parse_philo(t_params *p, char **argv, int ac);


#endif