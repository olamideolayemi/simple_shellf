#include "shell.h"

/**
 * concat_n - conacatenates two strings
 * @dest: string destination
 * @src: string source
 * @bytes: number of bytes used
 * Return: strings destination
 */
char *concat_n(char *dest, char *src, int bytes)
{
	int len = 0;
	int i;

	for (i = 0; dest[i] != '\0'; i++)
		len += 1;

	for (i = 0; i < bytes && src[i] != '\0'; i++)
		dest[len + i] = src[i];

	return (dest);
}

/**
 * cmp_n - compares the first n characters of multiple strings
 * @str1: string 1
 * @str2: string 2
 * @n: bytes to compare
 * Return: 0 (if strings are the same)
 */
int cmp_n(const char *str1, const char *str2, int n)
{
	while (n > 0)
	{
		char c1 = *str1;
		char c2 = *str2;

		if (c1 == '\0' || c1 != c2)
			return ((int)(c1 - c2));

		str1++;
		str2++;
		n--;
	}
	return (0);
}

/**
 * copy_n - copies string bytes onto another
 * @dest: string destination
 * @src: string source
 * @bytes: amount of bytes copied
 * Return: string destination
 */
char *copy_n(char *dest, char *src, int bytes)
{
	int i = 0;

	while (i < bytes && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	while (i < bytes)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * is_digit - checks for digit in characters
 * @ch: character to be checked
 * Return: 1 if ch is a digit, otherwise 0
 */
int is_digit(int ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	else
		return (0);
}

/**
 * find_char - searches for charater in strings
 * @str: the string parsed
 * @ch: sought character
 * Return: the searched string
 */
char *find_char(char *str, char ch)
{
	if (str != NULL)
	{
		while (*str != '\0')
		{
			if (*str == ch)
				return (str);
			str++;
		}
	}
	return (NULL);
}
