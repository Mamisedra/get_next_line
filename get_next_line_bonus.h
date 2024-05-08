/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mranaivo <mranaivo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 12:31:19 by mranaivo          #+#    #+#             */
/*   Updated: 2024/04/11 15:10:59 by mranaivo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

int		ft_strlen(char *str);
int		ft_strchr(char *store, char c);

char	*ft_strjoin(char *s1, char *s2);
char	*ft_extracteline(char *store);
char	*ft_getreste(char *store);
char	*ft_read(char *reste, int fd);
char	*get_next_line(int fd);
char	*ft_strdup(char *buffer);

void	ft_strcpy(char *store, char *reste);

#endif
