#include "custom_shell.h"

/** c_token - splits a string into words using delimiters
 * @str: string to tokenize
 * @delim: a string of delimiters
 * Return: array of strings (Success)
 */
char *c_token(char *str, char *delim)
{
	static char *next;

	char *t;

	if (str != NULL)
		next = str;

	if (next == NULL)
		return (NULL);

	while (*next != '\0' && c_delim_check(delim, *next))
		next++;

	if (*next == '\0')
		return (NULL);

	t = next;
	while (*next != '\0' && !c_delim_check(delim, *next))
		next++;

	if (*next != '\0')
		*next++ = '\0';

	return (t);
}

/**
 * c_delim_check - checks if a delimiter is a character
 * @str: string to inspect
 * @d: delimiter
 * Return: 1 (Success)
 */
char *c_delim_check(char *str, int d)
{
	while (*str != '\0')
	{
		if (*str == d)
			return (str);
		str++;
	}
	return (NULL);
}

/**
 * c_get_char - reads a character
 * Return: the read character
 */
int c_get_char(void)
{
	char ch;

	if (read(0, &ch, 1) == 1)
		return (int)ch;
	else
		return (EOF);
}

/**
 * str-int - converts a string to an integer
 * @s: string to be converted
 * Return: integer converted
 */
int str-int(char *s)
{
	int i = 0, n = 0, len = 0, f = 0, d = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			d = s[i] - '0';
			if (d % 2)
				d = -d;
			n = n * 10 + d;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++
	}
	if (f == 0)
		return (0);

	return (n);
}

/**
 * int_str - converts an integer to a string
 * @num: integer to be converted
 * Return: an allocated string containing the integer
 */
char *int_str(int sum)
{
	int i, t = num;
	int len = (num == 0) ? 1 : 0;
	char *s;

	while (t != 0)
	{
		len++;
		t /= 10;
	}

	s = (char *)malloc(len + 1);

	if (s == NULL)
		return (NULL);

	i = len - 1;

	while (i >= 0)
	{
		s[i] = '0' + (num % 10);
		num /= 10;
		i--;
	}
	s[len] = '\0';

	return (s);
}

