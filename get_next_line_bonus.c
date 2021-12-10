/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/12/10 22:49:20 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	ft_free_lst(node *holder)
{
	node	*tmp;
	
	while (holder)
	{
		tmp = holder->next;
		free (holder->str);
		free (holder);
		holder = tmp;
	}
}

static char	*ft_create_ret(node *buf_lst)
{
	char	*ret;
	char	*ptr;
	char	*tmp;

	ptr = ft_strchr(buf_lst->str, '\n');
	if (!ptr)
	{
		if (*(buf_lst->str) == '\0')
			ret = ft_strndup(buf_lst->str, 1);
		else
			ret = ft_strndup(buf_lst->str, ft_strlen(buf_lst->str) + 1);
	}
	else
	{
		ret = ft_strndup(buf_lst->str, ptr - buf_lst->str + 1);
		tmp = ft_strndup(ptr + 1, ft_strlen(ptr + 1));
		free (buf_lst->str);
		buf_lst->str = tmp;
	}
	return (ret);
}

static int	ft_read(int fd, node *buf_lst)
{
	ssize_t	rc;
	char	*buf;

	while (1)
	{
		buf = NULL;
		if (ft_strchr(buf_lst->str, '\n'))
			return (GOOD);
		buf = (char	*)malloc(sizeof(char) * BUFFER_SIZE + 1);
		if (!buf)
			return (ERROR);
		rc = read(fd, buf, BUFFER_SIZE);
//		printf("ft_read\n");
		if (rc < 0)
		{
			free(buf);
			return (ERROR);
		}
		if (rc == 0)
			return (END);
		buf[BUFFER_SIZE] = '\0';
//		printf("buf_lst->str:\n%s\n", buf_lst->str);
		buf_lst->str = ft_strjoin(buf_lst->str, buf);
		free (buf);
	}
}

static node	*ft_create_lst(int fd, node **holder)
{
	node	*buf_lst;
	
	if (!(*holder))
	{
		buf_lst = ft_lstnew(fd, "");
		*holder = buf_lst;
//		printf("(in ft_creat_lst1)fd = %d\n",fd);
		return (buf_lst);
	}
	buf_lst = *holder;
	while (buf_lst)
	{
		if (buf_lst->fd == fd)
			return (buf_lst);
//		if (buf_lst == *holder)
//			break;
		buf_lst = buf_lst->next;
	}
	buf_lst = ft_lstnew(fd, "");
//	printf("(in ft_creat_lst2)fd = %d\n",fd);
	buf_lst->next = *holder;
	*holder = buf_lst;
	return (buf_lst);
}

char	*get_next_line(int fd)
{
	static node *holder;
	node	*buf_lst;
//	char	*buf;
	char	*ret;
	int	status;
	
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!holder)
		holder = NULL;
	buf_lst = ft_create_lst(fd, &holder);
	status = ft_read(fd, buf_lst);
	if (status == ERROR)
	{
		ft_free_lst(holder);
		return (NULL);
	}
	ret = ft_create_ret(buf_lst);
	if (status == END)
		ft_free_lst(holder);
	return (ret);
}
