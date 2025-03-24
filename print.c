/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:01:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/02 23:38:19 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print(char *str, t_philo *philo, int id, size_t start_time)
{
	size_t	time;

	pthread_mutex_lock(philo->mut_print);
	time = get_current_time() - start_time;
	if (!dead(philo))
		printf("%zu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->mut_print);
}

void	t_error(const char *message, t_philo *philos,
t_table *table, pthread_mutex_t *forks)
{
	printf("%s\n", message);
	if (table && forks)
		mut_destroy(table, forks);
	if (forks)
		free(forks);
	if (philos)
		free(philos);
}

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print("has taken a fork", philo, philo->id, philo->table->start_time);
	ft_usleep(philo->table->time_to_die);
	pthread_mutex_unlock(philo->r_fork);
}
