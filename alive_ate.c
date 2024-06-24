/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alive_ate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:44:45 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/24 22:32:08 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_died(t_philo *philos)
{
	pthread_mutex_lock(philos->mut_last_meal);
	if (get_current_time() - philos->last_meal >= philos->table->time_to_die && philos->eating == 0)
	{
		pthread_mutex_unlock(philos->mut_last_meal);
		return (1);
	}
	pthread_mutex_unlock(philos->mut_last_meal);
	return (0);
}

int	all_alive(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].table->no_of_philos)
	{
		if (philo_died(&philos[i]))
		{
			print("died", &philos[i], philos[i].id, philos[i].table->start_time);
			pthread_mutex_lock(philos[0].mut_dead);
			*philos->dead = 1;
			pthread_mutex_unlock(philos[0].mut_dead);
			return (0);
		}
		i++;
	}
	return (1);
}

int	all_ate(t_philo *philos)
{
	int	i;

	i = 0;
	if (philos[0].table->n_t_eachmusteat == -1)
		return (0);
	while (i < philos->table->no_of_philos)
	{
		pthread_mutex_lock(philos[0].mut_dead);
		*philos->dead = 1;
		pthread_mutex_unlock(philos[0].mut_dead);
		return (0);
	}
	return (0);
}