/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:46:55 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/08 16:54:05 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <stdint.h>
# include <time.h>
# include <sys/time.h>
# include <limits.h>

# define MAX_PHILO 200

struct	s_tab;

struct	s_fork;

typedef enum e_message
{
	DEAD,
	EATING,
	SLEEPING,
	THINKING,
	FORK,
	END,
	M_PHILO,
}	t_message;

typedef enum e_error
{
	MALLOC,
	THREAD_CREATE,
	THREAD_JOIN,
	THREAD_INIT,
	MUTEX_INIT,
	ARGS_U,
	ARGS_D,
	ARGS_N,
	TIME,
}	t_error;

typedef struct	s_philo
{
	int				id;
	struct s_tab	*tab;
	pthread_t		p_thread;
	size_t			eating_count;
	unsigned long	last_meal;
	t_fork			*left_fork;
	t_fork			*right_fork;
}				t_philo;

typedef struct	s_tab
{
	unsigned long	start_tim;
	size_t			n_philo;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	size_t			eating_count;
	int				is_dead;
	int				is_done;
	t_philo			*tab_philo;
	t_fork			*tab_fork;
	pthread_mutex_t m_ready;
	pthread_mutex_t	m_print;
	pthread_mutex_t	m_time;
}		t_tab;

typedef struct	s_fork
{
	int				owner;
	pthread_mutex_t	m_fork;
}		t_fork;

// atoi.c
long int	ft_atol(const char *str);
int			ft_atoi(const char *str);
// checker.c
int			ft_check(int argc, char **argv);
// error.c
void    	ft_perror(t_error error);
void    	ft_big_free(t_tab *tab);
// time.c
long		ft_get_time(void);
void		ft_usleep(t_tab *tab, unsigned long time);
// routine.c
void		*ft_routine(t_philo	*philo);
int			ft_eat(t_philo *philo);
int			ft_sleep(t_philo *philo);
// initialization.c
int			ft_init(int argc, char **argv, t_tab *tab);
int			ft_set_mutex(t_tab *tab);
int			ft_set_philo(t_tab *tab);
int			ft_set_threads(t_tab *tab);
// philo_utils.c
int			ft_dead_status(t_tab *tab);
void		ft_print(t_tab *tab, int id, t_message message);
// fork.c
int			ft_ltake_fork(t_philo *philo);
int			ft_rtake_fork(t_philo *philo);
int			ft_lrelease_fork(t_philo *philo);
int			ft_rrelease_fork(t_philo *philo);
#endif