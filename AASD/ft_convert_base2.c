#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		len += 1;
	}
	return (len);
}
char *ft_putnbr_base(int nbr, char *base, char *dest)
{
	int		i;
	int		mod[999];
	int		check;
	int		set_char;

	i = 0;
	set_char = 0;
	while (nbr != 0)
	{
		mod[i] = nbr % ft_strlen(base);
		nbr = nbr / ft_strlen(base);
		i ++;
	}
	dest = malloc(i * sizeof(char));
	while (i >= 0)
	{
		dest[set_char] = base[mod[i]];
		set_char ++;
		i --;
	}
	return (dest);
}

int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	res = nb;
	while (power > 0)
	{
		return (res * ft_recursive_power(nb, power - 1));
	}
	return (0);
}

#include <stdio.h>
int ft_convert_to_dec(char *nbr, char *base_from)
{
	int	j;
	int len;
	int	dec;
	int	power;

	len = ft_strlen(nbr) - 1;
	power = 0;
	dec = 0;
	while (len >= 0)
	{
		j = 0;
		while(base_from[j])
		{
			if (nbr[len] == base_from[j])
				break;
			j ++;
		}
		printf("%d,   %d,   %d\n", ft_strlen(base_from), power, j);
		dec += ft_recursive_power(ft_strlen(base_from), power) * j;
		len --;
		power ++;
	}
	return (dec);
}


int main()
{
	char 	nbr[] = "001101";
	char 	base_from[] = "01";
	char	base_to[] = "0123456789ABCDEFG";
	int		dec = ft_convert_to_dec(nbr, base_from);
	char	*new_value;
	printf("%d\n", dec);
	printf("%s\n", ft_putnbr_base(dec, base_to, new_value));
}
