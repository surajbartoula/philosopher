/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:48:31 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/19 11:18:29 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead(t_philo *philo)
{
	pthread_mutex_lock(philo->mut_dead);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->mut_dead), 1);
	pthread_mutex_unlock(philo->mut_dead);
	return (0);
}

void	*philo_routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead(philo))
	{
		eat(philo);
		sleep(philo);
		think(philo);
	}
	return (ptr);
}

int	thread_create(t_table *table)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, table->no_of_philos) != 0)
		destroy_all("Thread creation error", table);
	i = 0;
	while (i < table->no_of_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &philo_routine, &table->philos[i]) != 0)
			destroy_all("Thread creation error", table);
		i++;
	}
	if (pthread_join(observer, NULL) != 0)
		destroy_all("Thread join error", table);
	while (i < table->no_of_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			destroy_all("Thread join error", table);
		i++;
	}
	return (0);
}
