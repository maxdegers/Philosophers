/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrousse <mbrousse@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 18:30:59 by mbrousse          #+#    #+#             */
/*   Updated: 2024/03/07 18:31:01 by mbrousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *str)
{
	int					i;
	unsigned long int	nbr;
	int					sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((char)str[i] == '-' || (char)str[i] == '+')
		if ((char)str[i++] == '-')
			sign++;
	while ((char)str[i] >= '0' && (char)str[i] <= '9')
		nbr = nbr * 10 + ((char)str[i++] - '0');
	if (sign % 2 == 1)
		return (nbr * -1);
	return (nbr);
}

long int	ft_atol(const char *str)
{
	long int			i;
	unsigned long int	nbr;
	int					sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if ((char)str[i] == '-' || (char)str[i] == '+')
		if ((char)str[i++] == '-')
			sign++;
	while ((char)str[i] >= '0' && (char)str[i] <= '9')
		nbr = nbr * 10 + ((char)str[i++] - '0');
	if (sign % 2 == 1)
		return (nbr * -1);
	return (nbr);
}