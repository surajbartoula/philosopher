/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mut_destroy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 08:49:56 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/24 12:54:13 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mut_destroy(t_philo **philos, t_fork *forks)
{
	int	i;

	i = -1;
	while (++i < (*philos)->table->no_of_philos)
	{
		pthread_mutex_destroy(forks[i].r_fork);
		pthread_mutex_destroy(forks[i].l_fork);
	}
	pthread_mutex_destroy((*philos)->mut_meal);
	pthread_mutex_destroy((*philos)->mut_dead);
	pthread_mutex_destroy((*philos)->mut_last_meal);
	pthread_mutex_destroy((*philos)->mut_print);
}