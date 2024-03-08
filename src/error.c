/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:34:15 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/07 23:13:05 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    ft_perror(t_error error)
{
    if (error == MALLOC)
        write(2, "Error: MALLOC Fail.\n", 27);
    if (error == THREAD_CREATE)
        write(2, "Error: Thread creation fail.\n", 30);
    if (error == THREAD_JOIN)
        write(2, "Error: Thread join fail.\n", 26);
    if (error == THREAD_INIT)    
        write(2, "Error: Thread init fail.\n", 26);
    if (error == ARGS_U)
        write(2, "Error: Too much arguments.\n", 27);
    if (error == ARGS_D)
        write(2, "Error: Too few arguments.\n", 26);
    if (error == ARGS_N)
        write(2, "Error: invalide arguments.\n", 27);
    if (error == MUTEX_INIT)    
        write(2, "Error: Mutex init fail.\n", 24);  
}

void    ft_big_free(t_tab   *tab)
{
    if (tab->tab_fork)
    {
        /* code */
    }
    
    
}