/*
** EPITECH PROJECT, 2017
** my_strcapitalize.c
** File description:
** CPool_Day06_2017_Task09
*/

void	letter(char *str, int len_cap, int low_str)
{
	while (str[low_str] != '\0') {
		if (str[low_str] >= 'a' && str[low_str] <= 'z')
			str[low_str] = str[low_str] - 32;
		low_str = low_str + 1;
	}
	while (str[len_cap] != '\0') {
		if (str[len_cap] >= 'A' && str[len_cap] <= 'Z') {
			len_cap++;
			while (str[len_cap] > 64 && str[len_cap] < 91) {
				str[len_cap] = str[len_cap] + 32;
				len_cap++;
			}
		}
		len_cap++;
	}
}

char	*my_strcapitalize(char *str)
{
	int	len_cap = 0;
	int	number = 0;
	int	low_str = 0;

	letter(str, len_cap, low_str);
	while (str && str[number] != '\0') {
		while (str[number] > 47 && str[number] < 56) {
			number ++;
			while (str[number] > 64 && str[number] < 91) {
				str[number] = str[number] + 32;
				number++;
			}
		}
		number ++;
	}
	return (str);
}