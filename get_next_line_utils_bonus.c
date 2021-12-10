/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:52 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/12/10 19:11:24 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char	*)&s[i]);
		i++;
	}
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	size_t i;
	
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dst;
	size_t	i;
	size_t	j;
	
	if (!s1 || !s2)
		return (NULL);
	dst = (char	*)malloc(sizeof(char) * ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dst)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	free ((char	*)s1);
	while (s2[j])
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strndup(const char *s, size_t len)
{
	char	*dst;
	size_t	i;

	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = s[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

node	*ft_lstnew(int fd, void	*content)
{
	node	*buf_lst;

	buf_lst = (node *)malloc(sizeof(node));
	if (!buf_lst)
		return (NULL);
	buf_lst->fd = fd;
/*	if (content[0] == '\0');
	{
		content = (char	*)malloc(sizeof(char));
		content[0] == '\0';
	}
*/
	buf_lst->str = ft_strndup(content, 0);
	buf_lst->next = NULL;
	return (buf_lst);
}




