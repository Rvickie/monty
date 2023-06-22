#include "monty.h"
/**
 * _strcmp - Function that differentiates two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: 0 if s1 and s2 are equals
 * another value if they are different
 */
int _strcmp(char *s1, char *s2)
{
	int k;

	for (k = 0; s1[k] == s2[k] && s1[k]; k++)
		;
	if (s1[k] > s2[k])
		return (1);
	if (s1[k] < s2[k])
		return (-1);
	return (0);
}

/**
 * _sch - function that checks if a char is inside a string
 * @s: string to review
 * @c: char to find
 * Return: 1 if success 0 if not
 */
int _sch(char *s, char c)
{
	int cont = 0;

	while (s[cont] != '\0')
	{
		if (s[cont] == c)
		{
			break;
		}
		cont++;
	}
	if (s[cont] == c)
		return (1);
	else
		return (0);
}

/**
 * _strtoky - function that breaks a string into tokens
 * depending of the delimit
 * @s: string to cut in parts
 * @d: delimiters
 * Return: first partition
 */
char *_strtoky(char *s, char *d)
{
	static char *ultimo;
	int k = 0, j = 0;

	if (!s)
		s = ultimo;
	while (s[k] != '\0')
	{
		if (_sch(d, s[k]) == 0 && s[k + 1] == '\0')
		{
			ultimo = s + k + 1;
			*ultimo = '\0';
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[k]) == 0 && _sch(d, s[k + 1]) == 0)
			k++;
		else if (_sch(d, s[k]) == 0 && _sch(d, s[k + 1]) == 1)
		{
			ultimo = s + k + 1;
			*ultimo = '\0';
			ultimo++;
			s = s + j;
			return (s);
		}
		else if (_sch(d, s[k]) == 1)
		{
			j++;
			k++;
		}
	}
	return (NULL);
}
