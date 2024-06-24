/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:21:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/24 18:35:11 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table			table;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				no_of_philos;

	if (parse_input(argc, argv) > 0)
		return (0);
	no_of_philos = ft_atoi(argv[1]);
	forks = malloc(sizeof(pthread_mutex_t) * no_of_philos);
	if (!forks)
		return (0);
	init_forks(forks, no_of_philos);
	init_table(&table, argv);
	philos = malloc(sizeof(t_philo) * no_of_philos);
	if (!philos)
		return (0);
	init_philos(&philos, &table, forks);
	thread_create(&philos, &table, forks);
	mut_destroy(&philos, forks);
	free(forks);
	free(philos);
	return (0);
}
