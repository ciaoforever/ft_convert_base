#include <stdlib.h>
#include <stdio.h>

int	ft_strlen(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

int check(char *base, int len)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == 43 || base[0] == 45)
		return (0);
	if (len >= 2)
	{	
		while (i <= len - 1)
		{	
			j = i + 1;
			while (j <= len)
			{	
				if (base[i] != base[j] && base[j] != 43 && base[j] != 45)
					j++;
				else
					return (0);
			}
			i++;
		}
		return (1);
	}
	return (0);
}
int check2(char a,char *base)
{
    int i;
    i = 0;
    while (base[i])
    {
        if (base[i] != a)
            i++;
        else
            return (i);
    }
    return (-1);
}

int	ft_atoi(char *str,char *base, char *new)
{
	int	i;
    int j;
	int	sign;
    int flag;
    int tmp;

    tmp = 0;
	sign = 0;
	i = 0;
    j = 0;
    flag = 0;

	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	while (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			sign++;
		i++;
	}
	while (str[i])
	{
        tmp = check2(str[i], base);
        if (tmp != -1)
        {
            new[j] = base[tmp];
            flag = 1;
            i++;
            j++;
        }
        else if(tmp == -1 || flag == 1)
            break;
        else
            i++;
	}
    new[j] = 0;
    printf("%s", new);

	//if (sign % 2)
	return (0);
}



char    *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
    char *new;

    if (check(base_from, ft_strlen(base_from)) && check(base_to, ft_strlen(base_to)))
    {
        new = malloc(ft_strlen(nbr));
        *new = 0;
        ft_atoi(nbr, base_from, new);
        return (new);
    }
    else
        return (NULL);
}
