/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hokutosuzuki <hosuzuki@student.42toky      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 12:17:51 by hokutosuz         #+#    #+#             */
/*   Updated: 2021/12/10 09:33:42 by hokutosuz        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void	ft_free_buf(t_list **holder, t_list *buf_lst)
{
	t_list	*tmp;

	if (!holder || !(*holder))
		return ;
	if (*holder == buf_lst)
	{
		*holder = buf_lst->next;
		free(buf_lst->str);
		free(buf_lst);
		return ;
	}
	tmp = *holder;
	while (tmp && (tmp->next != buf_lst))
		tmp = tmp->next;
	tmp->next = buf_lst->next;
	free(buf_lst->str);
	free(buf_lst);
}

static int	ft_create_ret(t_list **buf_lst, char *isnewl, char **ret)
{
	char	*tmp;

	if (isnewl)
	{
		*ret = ft_strndup((*buf_lst)->str, isnewl - ((*buf_lst)->str) + 1);
		tmp = ft_strndup(isnewl + 1, ft_strlen(isnewl + 1));
		free((*buf_lst)->str);
		(*buf_lst)->str = tmp;
		return (SUCCESS);
	}
	else
	{
		if ((*buf_lst)->str && *((*buf_lst)->str) == '\0')
			*ret = NULL;
		else
		{
			*ret = ft_strndup((*buf_lst)->str, ft_strlen((*buf_lst)->str));
			tmp = ft_strndup("", 0);
			free((*buf_lst)->str);
			(*buf_lst)->str = tmp;
		}
		return (END);
	}
}

static int	ft_read(t_list *buf_lst, char *buf, char **ret)
{
	ssize_t	rc;
	char	*tmp;
	char	*isnewl;

	while (1)
	{
		isnewl = ft_strchr(buf_lst->str, '\n');
		if (isnewl)
			return (ft_create_ret(&buf_lst, isnewl, ret));
		rc = read(buf_lst->fd, buf, BUFFER_SIZE);
		if (rc == -1)
			return (ERROR);
		else if (rc == 0)
			return (ft_create_ret(&buf_lst, isnewl, ret));
		buf[rc] = '\0';
		tmp = ft_strjoin(buf_lst->str, buf);
		free(buf_lst->str);
		buf_lst->str = tmp;
	}
}

static t_list	*ft_create_lst(int fd, t_list **holder)
{
	t_list	*buf_lst;

	if (!*holder)
	{
		buf_lst = ft_lstnew(fd, "");
		*holder = buf_lst;
		return (buf_lst);
	}
	buf_lst = *holder;
	while (buf_lst && buf_lst->fd != fd)
		buf_lst = buf_lst->next;
	if (buf_lst)
		return (buf_lst);
	buf_lst = ft_lstnew(fd, "");
	buf_lst->next = *holder;
	*holder = buf_lst;
	return (buf_lst);
}

char	*get_next_line(int fd)
{
	static t_list	*holder;
	t_list			*buf_lst;
	char			*buf;
	char			*ret;
	int				status;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf_lst = ft_create_lst(fd, &holder);
	buf = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	ret = NULL;
	status = ft_read(buf_lst, buf, &ret);
	free(buf);
	if ((status == ERROR || status == END))
		ft_free_buf(&holder, buf_lst);
	if (status == ERROR)
		return (NULL);
	return (ret);
}
