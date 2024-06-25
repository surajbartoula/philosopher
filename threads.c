/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:48:31 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/25 09:34:43 by sbartoul         ###   ########.fr       */
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

void	*monitor(void *ptr)
{
	t_philo	*philos;

	philos = (t_philo *)ptr;
	while (1)
		if (!all_alive(philos) || !all_ate(philos))
			break ;
	return (ptr);
}

void	*philo_routine(void *ptr)
{
	t_philo *philo;

	philo = (t_philo *)ptr;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead(philo))
	{
		eat(philo, philo->table);
		slep(philo, philo->table);
		think(philo, philo->table);
	}
	return (ptr);
}

int	thread_create(t_philo *philos, t_table *table, pthread_mutex_t *forks)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, philos) != 0)
	{
		mut_destroy(table, forks);
		return (-1);
	}
	i = 0;
	while (i < table->no_of_philos)
	{
		if (pthread_create(&(philos[i].thread), NULL, &philo_routine, &philos[i]) != 0)
			mut_destroy(table, forks);
		i++;
	}
	printf("pthread_cerate done\n");
	if (pthread_join(observer, NULL) != 0)
	{
		mut_destroy(table, forks);
		return (-1);
	}
	printf("Working on pthread_join\n");
	i = 0;
	while (i < table->no_of_philos)
	{
		if (pthread_join(philos[i].thread, NULL) != 0)
		{
			mut_destroy(table, forks);
			return (-1);
		}
		i++;
	}
	return (0);
}
