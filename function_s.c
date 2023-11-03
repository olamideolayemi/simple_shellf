#include "shell.h"

/**
 * copy_str - copies a string from one string array to another
 * @dst: A pointer
 * @src: * source string
 * Return: destination string
 */

char *copy_str(char *dst, char *src)
{
	int i = 0;

	if (dst == src || src == NULL)
		return (dst);

	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i += 1;
	}
	dst[i] = '\0';

	return (dst);
}

/**
 * cmp_str - compares two strings
 * @str1: A pointer to the first string
 * @str2: A pointer to the second string
 * Return: 0 (success)
 */
int cmp_str(char *str1, char *str2)
{
	int i = 0;

	if (str1 == NULL || str2 == NULL)
	{
		if (str1 == NULL && str2 == NULL)
			return (0);
		else
			return (-1);
	}

	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);

		i += 1;
	}

	if (str1[i] != '\0' || str2[i] != '\0')
		return str1[i] - str2[i];
	
	return (0);
}

/**
 * len_str - calculates the length of a string
 * @str: pointer to the input string
 * Return: Length of string
 */
int len_str(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * concat_str - concatenates two strings
 * @dst: pointer to the destination of the string array to copy to
 * @src: pointer to the source string
 * Return: pointer to the destination string
 */
char *concat_str(char *dst, char *src)
{
	int dst_len = 0, i = 0;

	while (dst[i] != '\0')
	{
		dst_len += 1;
		i++;
	}
	i = 0;

	while (src[i] != '\0')
	{
		dst[dst_len + i] = src[i];
		i++;
	}

	dst[dst_len + i] = '\0';

	return (dst);
}

/**
 * dup_str - duplicates a string from one string array to a buffer
 * @src: pointer to the source string
 * Return: duplicated string pointer
 */
char *dup_str(const char *src)
{
	int len = 0, i;
	char *dst;

	if (src == NULL)
		return (NULL);

	while (src[len] != '\0')
		len++;

	dst = malloc(sizeof(char) * (len + 1));

	if (dst == NULL)
		return (NULL);

	for (i = 0; i <= len; i++)
	{
		dst[i] = src[i];
	}

	return (dst);
}
