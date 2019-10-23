#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <ctype.h>
#include <stdarg.h>
#include "libft.h"

void print_results(char *str, int err, int t);
void print_str(char *str, int size);
int	test_atoi(int c);
int	test_calloc(int c);
int	test_strdup(int c);
int test_isalpha(int c);
int test_isdigit(int c);
int test_isalnum(int c);
int test_isascii(int c);
int test_isprint(int c);
int test_strlen(int c);
int test_toupper(int c);
int test_tolower(int c);
int test_strchr(int c);
int test_strrchr(int c);
int test_strncmp(int c);
int test_strlcpy(int c);
int test_strlcat(int c);

int main(void)
{
	int error = 0;

	system("clear");
	printf("Ce programme va tester toutes les fonctions de la libft :\n\n");
	error += test_atoi(19);
	error += test_calloc(6);
	error += test_strdup(4);
	error += test_isalpha(128);
	error += test_isdigit(128);
	error += test_isalnum(128);
	error += test_isascii(128);
	error += test_isprint(128);
	error += test_strlen(4);
	error += test_toupper(128);
	error += test_tolower(128);
	error += test_strchr(5);
	error += test_strrchr(5);
	error += test_strncmp(6);
	error += test_strlcpy(4);
	error += test_strlcat(4);
	if (error == 0)
		printf("Total OK\n");
	else
		printf("Total KO : %d erreurs\n", error);
	return 0;
}

void print_results(char *str, int err, int t)
{
	if (err == 0)
		printf("%s : OK\n", str);
	else
		printf("%s : KO (%d erreurs)\n", str, err);
	printf("%d tests effectues\n\n\n", t);
}

int test_atoi(int c)
{
	char **test;
	int i = 0;
	int ret = 0;
	if (!(test = malloc(sizeof(sizeof(char) * 50) * c)))
		return (-1);
	test[0] = "0123";
	test[1] = "86";
	test[2] = "-250";
	test[3] = "2147483647";
	test[4] = "2147483648";
	test[5] = "-2147483648";
	test[6] = "-2147483649";
	test[7] = "salut !";
	test[8] = "-18a56";
	test[9] = "8964u165";
	test[10] = "0";
	test[11] = "";
	test[12] = "684.156";
	test[13] = "\n123";
	test[14] = "\t123";
	test[15] = "\v123";
	test[16] = "\r123";
	test[17] = "\f123";
	test[18] = " 123";
	printf("ft_atoi :\n");
	while (i < c)
	{
		printf("Chaine testee : \"%s\"\n", test[i]);
		printf("Retour atoi    : %d\nRetour ft_atoi : %d\n", atoi(test[i]), ft_atoi(test[i]));
		if (atoi(test[i]) == ft_atoi(test[i]))
			printf("OK\n");
		else
		{
			ret++;
			printf("KO\n");
		}
		printf("\n");
		i++;
	}
	print_results("ft_atoi", ret, c);
	free(test);
	return (ret);
}

int	test_calloc(int c)
{
	int ret = 0;
	int i = 0;
	int *nb;
	int *size;
	void *test;
	void *ft_test;

	if (!(nb = malloc(sizeof(int) * c)))
		ret = -1;
	if (!(size = malloc(sizeof(int) * c)))
		ret = -1;
	nb[0] = 1;
	size[0] = 1;
	nb[1] = 4500;
	size[1] = 8;
	nb[2] = 0;
	size[2] = 0;
	nb[3] = 1;
	size[3] = 0;
	nb[4] = 0;
	size[4] = 1;
	nb[5] = 2;
	size[5] = 8620;
	printf("ft_calloc :\n");
	while (i < c)
	{
		if (!(test = calloc(nb[i], size[i])))
			ret = -1;
		if (!(ft_test = ft_calloc(nb[i], size[i])))
			ret = -1;
		printf("Test calloc avec un tableau de %d elements de %d octets :\n", nb[i], size[i]);
		printf("Retour calloc    : %s\nRetour ft_calloc : %s\n", test, ft_test);
		if (sizeof(test) == sizeof(ft_test))
			printf("OK\n");
		else
		{
			ret++;
			printf("KO\n");
		}
		printf("\n");
		i++;
	}
	free(nb);
	free(size);
	free(test);
	free(ft_test);
	print_results("ft_calloc", ret, c);
	return (ret);
}

int	test_strdup(int c)
{
	int ret = 0;
	int i = 0;
	int j = 0;
	int k = 0;
	char *str;
	char *ft_str;
	char **test;

	if (!(test = malloc(sizeof(char) * 50 * c)))
		return (-1);
	if (!(str = malloc(sizeof(char) * 50)))
		return (-1);
	if (!(ft_str = malloc(sizeof(char) * 50)))
		return (-1);
	test[0] = "Test";
	test[1] = "Ceci est un test tres tres tres long pour voir si tout fonctionne";
	test[2] = "";
	test[3] = "test\0test";
	printf("ft_strdup :\n");
	while (i < c)
	{
		printf("%p\n%p\n%p\n", &test, &str, &ft_str);
		printf("Chaine testee : \"%s\"\n", test[i]);
		str = strdup(test[i]);
		ft_str = ft_strdup(test[i]);
		printf("strdup        : %s\n", str);
		printf("ft_strdup     : %s\n", ft_str);
		while (test[k])
			k++;
		while (j < k)
		{
			if (str[j] != ft_str[j])
				break;
			j++;
		}
		if (j == k)
			printf("OK\n");
		else
		{
			ret++;
			printf("KO\n");
		}
		printf("\n");
		i++;
	}
	free(test);
	free(str);
	free(ft_str);
	print_results("ft_strdup", ret, c);
	return (ret);
}

int test_isalpha(int c)
{
	int ret = 0;
	int i = 0;

	printf("ft_isalpha :\n");
	while (i < c)
	{
		if (isalpha(i) == ft_isalpha(i))
			printf("\"%c\" : (%d|%d) OK\n", i, isalpha(i), ft_isalpha(i));
		else
		{
			printf("\"%c\" : (%d|%d) KO\n", i, isalpha(i), ft_isalpha(i));
			ret++;
		}
		i++;
	}
	print_results("ft_isalpha", ret, c);
	return (ret);
}

int test_isdigit(int c)
{
	int ret = 0;
	int i = 0;

	printf("ft_isdigit :\n");
	while (i < c)
	{
		if (isdigit(i) == ft_isdigit(i))
			printf("\"%c\" : (%d|%d) OK\n", i, isalnum(i), ft_isalnum(i));
		else
		{
			printf("\"%c\" : (%d|%d) KO\n", i, isalnum(i), ft_isalnum(i));
			ret++;
		}
		i++;
	}
	print_results("ft_isdigit", ret, c);
	return (ret);
}

int test_isalnum(int c)
{
	int ret = 0;
	int i = 0;

	printf("ft_isalnum :\n");
	while (i < c)
	{
		if (isalnum(i) == ft_isalnum(i))
			printf("\"%c\" : (%d|%d) OK\n", i, isalnum(i), ft_isalnum(i));
		else
		{
			printf("\"%c\" : (%d|%d) KO\n", i, isalnum(i), ft_isalnum(i));
			ret++;
		}
		i++;
	}
	print_results("ft_isalnum", ret, c);
	return (ret);
}

int test_isascii(int c)
{
	int ret = 0;
	int i = 0;

	printf("ft_isascii :\n");
	while (i < c)
	{
		if (isascii(i) == ft_isascii(i))
			printf("\"%c\" : (%d|%d) OK\n", i, isascii(i), ft_isascii(i));
		else
		{
			printf("\"%c\" : (%d|%d) KO\n", i, isascii(i), ft_isascii(i));
			ret++;
		}
		i++;
	}
	print_results("ft_isascii", ret, c);
	return (ret);
}

int test_isprint(int c)
{
	int ret = 0;
	int i = 0;

	printf("ft_isprint :\n");
	while (i < c)
	{
		if (isprint(i) == ft_isprint(i))
			printf("\"%c\" : (%d|%d) OK\n", i, isprint(i), ft_isprint(i));
		else
		{
			printf("\"%c\" : (%d|%d) KO\n", i, isprint(i), ft_isprint(i));
			ret++;
		}
		i++;
	}
	print_results("ft_isprint", ret, c);
	return (ret);
}

int test_strlen(int c)
{
	int ret = 0;
	int i = 0;
	char **test;

	if (!(test = malloc(sizeof(int) * 50 * c)))
		ret = -1;
	test[0] = "Ceci est un test";
	test[1] = "Ceci \t est un test\0 lel";
	test[2] = "";
	test[3] = " ";
	printf("ft_strlen :\n");
	while (i < c)
	{
		if ((strlen(test[i]) == ft_strlen(test[i])))
			printf("Chaine : %s\n(%lu|%d)  : OK\n", test[i], strlen(test[i]), ft_strlen(test[i]));
		else
		{
			printf("Chaine : %s\n(%lu|%d)  : KO\n", test[i], strlen(test[i]), ft_strlen(test[i]));
			ret++;
		}
		i++;
		printf("\n");
	}
	free(test);
	print_results("ft_strlen", ret, c);
	return (ret);
}

int test_toupper(int c)
{
	int ret = 0;
	int i = 0;
	printf("ft_toupper :\n");
	while (i < c)
	{
		if(toupper(i) == ft_toupper(i))
			printf("Caractere teste : %c | OK\ntoupper         : %c\nft_toupper      : %c\n", toupper(i), ft_toupper(i), i);
		else
		{
			printf("Caractere teste : %c | KO\ntoupper         : %c\nft_toupper      : %c\n", toupper(i), ft_toupper(i), i);
			ret++;
		}
		i++;
	}
	printf("\n");
	print_results("ft_toupper", ret, c);
	return (ret);
}

int test_tolower(int c)
{
	int ret = 0;
	int i = 0;
	printf("ft_tolower :\n");
	while (i < c)
	{
		if(tolower(i) == ft_tolower(i))
			printf("Caractere teste : %c | OK\ntolower         : %c\nft_tolower      : %c\n", tolower(i), ft_tolower(i), i);
		else
		{
			printf("Caractere teste : %c | KO\ntolower         : %c\nft_tolower      : %c\n", tolower(i), ft_tolower(i), i);
			ret++;
		}
		i++;
	}
	printf("\n");
	print_results("ft_tolower", ret, c);
	return (ret);
}

int test_strchr(int c)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	char k = 0;
	char *str;
	char *ft_str;
	char **test;
	int *occ;

	if (!(str = malloc(sizeof(char) * 50)))
		return (-1);
	if (!(ft_str = malloc(sizeof(char) * 50)))
		return (-1);
	if (!(test = malloc(sizeof(char*) * 50 * c)))
		return (-1);
	if (!(occ = malloc(sizeof(int) * c)))
		return (-1);
	test[0] = "Ceci est une chaine de test";
	occ[0] = 't';
	test[1] = "Ceci est une chaine de test";
	occ[1] = 'e';
	test[2] = "blablabla :D";
	occ[2] = ':';
	test[3] = "Salut";
	occ[3] = 't';
	test[4] = "Ceci est une chaine de test";
	occ[4] = 'C';
	printf("ft_strchr :\n");
	while (i < c)
	{
		printf("Chaine testee      : %s\nOccurence cherchee : %c\n", test[i], occ[i]);
		str = strchr(test[i], occ[i]);
		ft_str = ft_strchr(test[i], occ[i]);
		while (j < 50)
		{
			if (str + j == ft_str + j)
				k = 1;
			else
			{
				k = 0;
				break;
			}
			j++;
		}
		printf("Retour strchr      : %s\nRetour ft_strchr   : %s\n", str, ft_str);
		if (k == 1)
			printf("OK\n");
		else
		{
			printf("KO\n");
			ret++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	print_results("ft_strchr", ret, c);
	free(test);
	free(occ);
	return (ret);
}

int test_strrchr(int c)
{
	int i = 0;
	int j = 0;
	int ret = 0;
	char k = 0;
	char *str;
	char *ft_str;
	char **test;
	int *occ;

	if (!(str = malloc(sizeof(char) * 50)))
		return (-1);
	if (!(ft_str = malloc(sizeof(char) * 50)))
		return (-1);
	if (!(test = malloc(sizeof(char) * 50 * c)))
		return (-1);
	if (!(occ = malloc(sizeof(int) * c)))
		return (-1);
	test[0] = "Ceci est une chaine de test";
	occ[0] = 't';
	test[1] = "Ceci est une chaine de test";
	occ[1] = 'e';
	test[2] = "blablabla :D";
	occ[2] = 'l';
	test[3] = "Salut salut !";
	occ[3] = 't';
	test[4] = "Ceci est une chaine de test";
	occ[4] = 'i';
	printf("ft_strrchr :\n");
	while (i < c)
	{
		printf("Chaine testee      : %s\nOccurence cherchee : %c\n", test[i], occ[i]);
		str = strrchr(test[i], occ[i]);
		ft_str = ft_strrchr(test[i], occ[i]);
		while (j < 50)
		{
			if (str + j == ft_str + j)
				k = 1;
			else
			{
				k = 0;
				break;
			}
			j++;
		}
		printf("Retour strrchr      : %s\nRetour ft_strrchr   : %s\n", str, ft_str);
		if (k == 1)
			printf("OK\n");
		else
		{
			printf("KO\n");
			ret++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	print_results("ft_strrchr", ret, c);
	free(test);
	free(occ);
	return (ret);
}

int test_strncmp(int c)
{
	int ret = 0;
	int i = 0;
	int *index;
	char **s1;
	char **s2;

	if (!(s1 = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(s2 = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(index = malloc(sizeof(int) * c)))
		return (-1);
	s1[0] = "Ceci est un test";
	s2[0] = "Ceci n'est pas un test";
	index[0] = 15;
	s1[1] = "Ceci est un test";
	s2[1] = "Ceci est pas un test";
	index[1] = 15;
	s1[2] = "Ceci est un test";
	s2[2] = "Ceci est un test";
	index[2] = 30;
	s1[3] = "0123468 ";
	s2[3] = " 0123468";
	index[3] = 8;
	s1[4] = "\t\ntest";
	s2[4] = "\n\ttest";
	index[4] = 6;
	s1[5] = "test\0test";
	s2[5] = "test\0tset";
	index[5] = 9;
	printf("ft_strncmp :\n");
	while (i < c)
	{
		printf("Chaine 1          : \"%s\"\nChaine 2          : \"%s\"\nIndice n          : %d\n", s1[i], s2[i], index[i]);
		printf("Retour strncmp    : %d\nRetour ft_strncmp : %d\n", strncmp(s1[i], s2[i], index[i]), ft_strncmp(s1[i], s2[i], index[i]));
		if (strncmp(s1[i], s2[i], index[i]) == ft_strncmp(s1[i], s2[i], index[i]))
			printf("OK\n");
		else
		{
			printf("KO\n");
			ret++;
		}
		printf("\n");
		i++;
	}
	print_results("ft_strcnmp", ret, c);
	free(s1);
	free(s2);
	return (ret);
}
#define STRLCPY_TEST_COUNT 4
int test_strlcpy(int c)
{
	int ret = 0;
	int i = 0;
	int res = 0;
	int ft_res = 0;
	char **dst;
	char **src;
	char **ft_dst;
	char **ft_src;
	int *size;

	if (!(dst = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(src = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(ft_dst = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(ft_src = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(size = malloc(sizeof(int) * c)))
		return (-1);
	char *dst_str[STRLCPY_TEST_COUNT] = {"Destination", "Source", "", "Destination"};
	char *src_str[STRLCPY_TEST_COUNT] = {"Source", "Destination", "Source", ""};
	while (i < c)
	{
		if (!(dst[i] = malloc((strlen(dst_str[i]) + 1) * sizeof(char))))
			return (-1);
		memcpy(dst[i],dst_str[i], strlen(dst_str[i]) + 1);
		src[i] = src_str[i];
		if (!(ft_dst[i] = malloc((strlen(dst_str[i]) + 1) * sizeof(char))))
			return (-1);
		memcpy(ft_dst[i],dst_str[i], strlen(dst_str[i]) + 1);
		ft_src[i] = src_str[i];
		i++;
	}
	size[0] = 10;
	size[1] = 20;
	size[2] = 15;
	size[3] = 15;
	printf("ft_strlcpy :\n");
	i = 0;
	while (i < c)
	{
		printf("Destination : \"%s\"\nSource      : \"%s\"\n\n", dst[i], src[i]);
		res = strlcpy(dst[i], src[i], size[i]);
		printf("strlcpy     : %d\nDestination : \"%s\"\n\n", res, dst[i]);
		ft_res = ft_strlcpy(ft_dst[i], ft_src[i], size[i]);
		printf("ft_strlcpy  : %d\nDestination : \"%s\"\n\n", ft_res, ft_dst[i]);
		if (res == ft_res && !(strcmp(dst[i], ft_dst[i])))
			printf("OK\n");
		else
		{
			printf("KO\n");
			ret++;
		}
		printf("--------------------------------\n");
		i++;
	}
	free(dst);
	free(src);
	free(ft_dst);
	free(ft_src);
	free(size);
	print_results("ft_strlcpy", ret, c);
	return (ret);
}

void print_str(char *str, int size)
{
	printf("\"");
	for (int i = 0; i < size; ++i)
		printf("%c", str[i]);
	printf("\"\n");
}

#define STRLCAT_TEST_COUNT 4
int test_strlcat(int c)
{
	int ret = 0;
	int i = 0;
	int res = 0;
	int ft_res = 0;
	char **dst;
	char **src;
	char **ft_dst;
	char **ft_src;
	int *size;

	if (!(dst = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(src = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(ft_dst = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(ft_src = malloc(sizeof(char*) * c)))
		return (-1);
	if (!(size = malloc(sizeof(int) * c)))
		return (-1);
	char *dst_str[STRLCAT_TEST_COUNT] = {"Destination", "Source", "", "Destination"};
	char *src_str[STRLCAT_TEST_COUNT] = {"Source", "Destination", "Source", ""};
	while (i < c)
	{
		if (!(dst[i] = malloc((strlen(dst_str[i]) + 1) * sizeof(char))))
			return (-1);
		if (!(ft_dst[i] = malloc((strlen(dst_str[i]) + 1) * sizeof(char))))
			return (-1);
		memcpy(dst[i],dst_str[i], strlen(dst_str[i]) + 1);
		memcpy(ft_dst[i],dst_str[i], strlen(dst_str[i]) + 1);
		ft_src[i] = src_str[i];
		src[i] = src_str[i];
		i++;
	}
	size[0] = 10;
	size[1] = 12;
	size[2] = 4;
	size[3] = 3;
	printf("ft_strlcat :\n");
	i = 0;
	while (i < c)
	{
		printf("Destination : \"%s\"\nDestination : \"%s\"\nSource      : \"%s\"\n\n", dst[i], ft_dst[i], src[i]);
		res = strlcat(dst[i], src[i], size[i]);
		printf("strlcat     : %d\nDestination : \"%s\"\n\n", res, dst[i]);
		ft_res = ft_strlcat(ft_dst[i], ft_src[i], size[i]);
		printf("ft_strlcat  : %d\nDestination : \"%s\"\n\n", ft_res, ft_dst[i]);
		if (res == ft_res && !(strcmp(dst[i], ft_dst[i])))
			printf("OK\n");
		else
		{
			printf("KO\n");
			ret++;
		}
		printf("--------------------------------\n");
		i++;
	}
	free(dst);
	free(src);
	free(ft_dst);
	free(ft_src);
	free(size);
	print_results("ft_strlcat", ret, c);
	return (ret);
}