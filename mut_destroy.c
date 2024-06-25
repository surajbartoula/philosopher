/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mut_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 08:49:56 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/25 15:26:26 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mut_destroy(t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (++i < table->no_of_philos)
		pthread_mutex_destroy(&forks[i]);
	pthread_mutex_destroy(&table->mut_dead);
	pthread_mutex_destroy(&table->mut_last_meal);
	pthread_mutex_destroy(&table->mut_print);
}
