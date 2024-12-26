/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrhilane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 20:08:02 by hrhilane          #+#    #+#             */
/*   Updated: 2024/12/24 20:08:05 by hrhilane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


size_t	ft_strlen(const char *str)
{
	const char	*s = str;

	while (*s != '\0')
		s++;
	return (s - str);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == src)
		return (dest);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	while (n--)
	{
		*d = *s;
		d++;
		s++;
	}
	return (dest);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	if (src_len + 1 < size)
		ft_memcpy(dst, src, src_len + 1);
	else
	{
		ft_memcpy(dst, src, size - 1);
		dst[size - 1] = '\0';
	}
	return (src_len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	sub_size;
	size_t	s_len;

	sub_size = 0;
	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
	{
		sub = (char *)malloc(1 * sizeof(char));
		if (sub == NULL)
			return (NULL);
		sub[0] = '\0';
		return (sub);
	}
	if (len > ft_strlen(s) - (size_t)start)
		sub_size = s_len - (size_t)start;
	else
		sub_size = len;
	sub = (char *)malloc((sub_size + 1) * sizeof(char));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, s + start, sub_size + 1);
	return (sub);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	space_left;
	size_t	src_len;
	size_t	dst_len;
	size_t	size_tot;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (src_len + dstsize);
	space_left = dstsize - dst_len - 1;
	size_tot = src_len + dst_len;
	while (*src && space_left--)
		*(dst + dst_len++) = *src++;
	*(dst + dst_len) = '\0';
	return (size_tot);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	len1;
	size_t	len2;

	if (s1)
		len1 = ft_strlen(s1);
	else
		len1 = 0;
	if (s2)
		len2 = ft_strlen(s2);
	else
		len2 = 0;
	s = (char *)malloc(len1 + len2 + 1);
	if (!s)
		return (NULL);
	if (s1)
		ft_strlcpy(s, s1, len1 + 1);
	else
		s[0] = '\0';
	if (s2)
		ft_strlcat(s, s2, len1 + len2 + 1);
	return (s);
}
