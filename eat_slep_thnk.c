/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat_slep_thnk.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 18:27:13 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/01 11:29:06 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	eat(t_philo *philo, t_table *table)
{
	pthread_mutex_lock(philo->r_fork);
	print("has taken a fork", philo, philo->id, table->start_time);
	if (table->no_of_philos == 1)
	{
		ft_usleep(table->time_to_die);
		pthread_mutex_unlock(philo->r_fork);
		return ;
	}
	pthread_mutex_lock(philo->l_fork);
	print("has taken a fork", philo, philo->id, table->start_time);
	philo->eating = 1;
	print("is eating", philo, philo->id, table->start_time);
	pthread_mutex_lock(philo->mut_last_meal);
	philo->last_meal = get_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->mut_last_meal);
	ft_usleep(table->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
}

void	slep(t_philo *philo, t_table *table)
{
	print("is sleeping", philo, philo->id, table->start_time);
	ft_usleep(table->time_to_sleep);
}

void	think(t_philo *philo, t_table *table)
{
	print("is thinking", philo, philo->id, table->start_time);
}
