/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mut_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 08:49:56 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/20 08:58:36 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mut_destroy(char *str, t_philo *philos, pthread_mutex_t *forks)
{
	int	i;

	i = -1;
	while (++i < philos->table->no_of_philos)
		pthread_mutex_destroy(&forks[i]);
	pthread_mutex_destroy(philos->mut_meal);
	pthread_mutex_destroy(philos->mut_dead);
	pthread_mutex_destroy(philos->mut_last_meal);
	pthread_mutex_destroy(philos->mut_print);
}