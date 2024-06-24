/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 07:02:51 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/24 07:08:56 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_forks(pthread_mutex_t *forks, int no_of_philo)
{
	int	i;

	i = 0;
	while (i < no_of_philo)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	init_table(t_table *table, char *argv[])
{
	table->time_to_die = ft_atoi(argv[2]);
	table->time_to_eat = ft_atoi(argv[3]);
	table->time_to_sleep = ft_atoi(argv[4]);
	table->no_of_philos = ft_atoi(argv[1]);
	if (argv[5])
		table->n_t_eachmusteat = ft_atoi(argv[5]);
	else
		table->n_t_eachmusteat = -1;
	table->start_time = get_current_time();
}

void	init_philos(t_philo **philos, t_table *table, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < table->no_of_philos)
	{
		philos[i]->id = i + 1;
		philos[i]->eating = 0;
		philos[i]->finished_eating = 0;
		philos[i]->last_meal = table->start_time;
		philos[i]->forks.l_fork = &forks[i];
		if (i == 0)
			philos[i]->forks.r_fork = &forks[table->no_of_philos - 1];
		else
			philos[i]->forks.r_fork = &forks[i - 1];
		philos[i]->table = table;
		i++;
	}
}
