/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 19:01:21 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/25 15:19:48 by sbartoul         ###   ########.fr       */
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
