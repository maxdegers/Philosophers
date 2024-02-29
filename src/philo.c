/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 15:16:26 by mbrousse          #+#    #+#             */
/*   Updated: 2024/02/29 19:19:02 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *count_to_100(void *arg)
{
 (void)arg;

 for(int i = 0; i < 100; i++);
 printf("The count has finished\n");
 return (NULL);
}
void *print_hello(void *arg)
{
 (void)arg;

 for(int i = 0; i < 100; i++)
  printf("print, world!\n");
 return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	thread_1;
	pthread_t	thread_2;

	(void) argv;
	(void) argc;
	// if (argc < 5 || argc > 6)
	// 	return (1);
	// ft_init();
	pthread_create(&thread_1, NULL, count_to_100, NULL);
	pthread_create(&thread_2, NULL, print_hello, NULL);
	pthread_join(thread_1, NULL);
	pthread_join(thread_2, NULL);
	return (0);
}
