/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:23:47 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/17 17:32:37 by sbartoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>
#include <pthread.h>

typedef struct s_philo
{
	pthread_t	thread;
	int		id;
	int		eating;
	int		finished_eating;
	size_t		last_meal;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		start_time;
	int		no_of_philos;
	int		n_t_eachmusteat;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}		t_philo;

typedef struct s_program
{
	t_philo		*philos;
}	t_program;

int	parse_input(int argc, char *argv[]);
int	is_number(char *str);
int	ft_atoi(char *str);

#endif
