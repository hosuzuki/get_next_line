/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:53 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/12/10 19:06:21 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include<stdio.h>
# include<unistd.h>
# include<stdlib.h>

# define GOOD 1
# define ERROR -1
# define END 0

typedef struct sllist
{
	int fd;
	char *str;
	struct sllist *next;
}	node;


size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strndup(const char *content, size_t len);
node	*ft_lstnew(int fd, void *content);

//void	ft_free_lst(node *holder);
//node	*ft_create_lst(int fd, node *holder);
char	*get_next_line(int fd);

#endif
