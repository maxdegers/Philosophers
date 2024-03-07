/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 19:38:12 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/07 19:38:24 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_get_time(void)
{
    struct timeval	time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + time.tv_usec / 1000);
}