/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lide <lide@student.s19.be>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 18:10:54 by lide              #+#    #+#             */
/*   Updated: 2022/03/02 16:52:48 by lide             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

int		backspace(char *s);
int		ft_find(char *s);
int		ft_strlen(char *s);
char	*ft_line(char *save, int len);
char	*ft_save(char *save, int len);
char	*get_next_line(int fd);
char	*ft_read(int fd, char *save);
char	*ft_strjoin(char *s1, char *s2, int i, int j);

#endif
