/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oidrissi <oidrissi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/18 20:03:14 by oidrissi          #+#    #+#             */
/*   Updated: 2021/09/19 18:34:41 by oidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

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
	int		nb_philo;
	bool	philo_action;
	int		forks;
	int		interrupt;
	
}	t_game;

typedef	struct s_philo
{
	bool	eat;
	bool	sleep;
	bool	think;
	bool	d_forks;
	bool	h_t_forks;
	bool	starving;
	bool	ate;
	bool	dead;
	
}	t_philo;



#endif