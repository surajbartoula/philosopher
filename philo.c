/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:21:10 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/20 10:06:28 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_table			table;
	t_philo			philos;
	pthread_mutex_t	*forks;

	if (parse_input(argc, argv) > 0)
		return (0);
	forks = malloc(sizeof(pthread_mutex_t) * ft_atoi(argv[1]));
	if (!forks)
		return (0);
	init_forks(forks, ft_atoi(argv[1]));
	init_table(&table, argv);
	init_philos(&philos, &table, forks);
	thread_create(&philos, &table);
	mut_destroy(&philos, forks);
	free(forks);
	return (0);
}
