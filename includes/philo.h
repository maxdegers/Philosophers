/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 00:46:55 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/19 15:30:11 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define MAX_PHILO 200
# define MAX_PHILO_STR "\033[1;34mToo many philosophers,\
 set to \033[1;33m200\033[0m\n"

struct	s_tab;

struct	s_fork;

typedef enum e_message
{
	DEAD,
	END,
	THINKING,
	SLEEPING,
	EATING,
	FORK,
}	t_message;

typedef enum e_mutex
{
	M_PRINT,
	M_READY,
	M_DEAD,
}	t_mutex;

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

typedef struct s_philo
{
	int				id;
	struct s_tab	*tab;
	pthread_t		p_thread;
	size_t			eating_count;
	long long		last_meal;
	long long		tt_die;
	struct s_fork	*left_fork;
	struct s_fork	*right_fork;
}	t_philo;

typedef struct s_tab
{
	unsigned long	start_tim;
	size_t			n_philo;
	long			tt_die;
	long			tt_eat;
	long			tt_sleep;
	long			tt_think;
	size_t			eating_count;
	int				is_dead;
	int				is_done;
	t_philo			*tab_philo;
	struct s_fork	*tab_fork;
	pthread_mutex_t	*tab_mutex;
}	t_tab;

typedef struct s_fork
{
	int				owner;
	pthread_mutex_t	m_fork;
}	t_fork;

// atoi.c
long int	ft_atol(const char *str);
int			ft_atoi(const char *str);
// checker.c
int			ft_check(int argc, char **argv);
// error.c
void		ft_perror(t_error error);
void		ft_big_free(t_tab *tab);
// fork.c
int			ft_ltake_fork(t_philo *philo);
int			ft_rtake_fork(t_philo *philo);
void		ft_lrelease_fork(t_philo *philo);
void		ft_rrelease_fork(t_philo *philo);
// initialization.c
int			ft_init(t_tab *tab, int argc, char **argv);
// philo_utils.c
void		ft_print(t_tab *tab, int id, t_message message);
int			ft_dead_status(t_tab *tab);
size_t		ft_strlen(const char *s);
void		ft_end(t_tab *tab);
void		ft_putstr_fd(const char *s, int fd);
// routine.c
void		*ft_routine(void *arg);
// time.c
long		ft_get_time(void);
void		ft_usleep(t_philo *philo, long long time);
#endif