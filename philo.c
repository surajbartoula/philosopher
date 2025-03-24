/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:21:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/07/01 12:24:41 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table			table;
	t_philo			*philos;
	pthread_mutex_t	*forks;

	if (parse_input(argc, argv) > 0)
		return (0);
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!forks)
		return (0);
	init_forks(forks, ft_atoi(argv[1]));
	init_table(&table, argv);
	philos = malloc(sizeof(t_philo) * ft_atoi(argv[1]));
	if (!philos)
		return (0);
	init_philos(philos, &table, forks);
	if (thread_create(philos, &table, forks) == -1)
	{
		t_error("Error creating threads\n", philos, &table, forks);
		return (0);
	}
	mut_destroy(&table, forks);
	free(forks);
	free(philos);
	return (0);
}
