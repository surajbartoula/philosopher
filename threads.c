/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 09:48:31 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/19 10:01:27 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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