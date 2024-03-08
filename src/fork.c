/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 16:34:09 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/08 16:51:46 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int ft_ltake_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork->m_fork);
    if (philo->left_fork->owner == 0)
    {
        philo->left_fork->owner = philo->id;
        ft_print(philo->tab, philo->id, FORK);
    }
    else
    {
        pthread_mutex_unlock(&philo->left_fork->m_fork);
        return (0);
    }
    return (1);
}

int ft_rtake_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->right_fork->m_fork);
    if (philo->right_fork->owner == 0)
    {
        philo->right_fork->owner = philo->id;
        ft_print(philo->tab, philo->id, FORK);
    }
    else
    {
        pthread_mutex_unlock(&philo->right_fork->m_fork);
        return (0);
    }
    return (1);
}

int ft_lrelease_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->left_fork->m_fork);
    philo->left_fork->owner = 0;
    pthread_mutex_unlock(&philo->left_fork->m_fork);
    return (0);
}

int ft_rrelease_fork(t_philo *philo)
{
    pthread_mutex_lock(&philo->right_fork->m_fork);
    philo->right_fork->owner = 0;
    pthread_mutex_unlock(&philo->right_fork->m_fork);
    return (0);
}