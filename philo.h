/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbartoul <sbartoul@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 14:23:47 by sbartoul          #+#    #+#             */
/*   Updated: 2024/06/20 09:02:21 by sbartoul         ###   ########.fr       */
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

typedef struct	table_fork
{
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
}	t_fork;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				finished_eating;
	int				meals_eaten;
	int				*dead;
	size_t			last_meal;
	pthread_mutex_t	*mut_meal;
	t_fork			forks;
	pthread_mutex_t	*mut_dead;
	pthread_mutex_t	*mut_print;
	pthread_mutex_t	*mut_last_meal;
	t_table			*table;
}		t_philo;

typedef struct table
{
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
	size_t		start_time;
	int			no_of_philos;
	int			n_t_eachmusteat;
}	t_table;

int		parse_input(int argc, char *argv[]);
int		is_number(char *str);
int		ft_atoi(char *str);
size_t	get_current_time();
int		dead(t_philo *philo);
int		ft_usleep(size_t time_milisec);
void	init_table(t_table *table, char *argv[]);
void	init_forks(pthread_mutex_t *forks, int no_of_philo);
void	init_philos(t_philo *philos, t_table *table, pthread_mutex_t *forks);
void	mut_destroy(char *str, t_philo *philos, pthread_mutex_t *forks);
int		thread_create(t_philo *philos, t_table *table);
void	print(char *str, t_philo *philo, int id, size_t start_time);

#endif
