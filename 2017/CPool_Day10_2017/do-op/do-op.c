/*
** EPITECH PROJECT, 2017
** do-op
** File description:
** CPool_Day10_Task02
*/

int calcul(char *str1, char *str2, char *ope)
{
	int a = my_getnbr(str1);
	int b = my_getnbr(str2);

	if (ope[0] == '+')	
		return (a + b);
	if (ope[0] == '-')
		return (a - b);
	if (ope[0] == '*' || ope[0] == 'x')
		return (a * b);
	if (ope[0] == '/' && b != 0)
		return (a / b);
	if (ope[0] == '%' && b != 0)
		return (a % b);
	if (ope[0] >= 0 && ope[0] <= 127)
		return (0);
}

int main(int argc , char **argv)
{
	if (argc >= 3) {
		if (argv[2][0] == '/' && my_getnbr(argv[3]) == 0) {
			write (2, "Stop : division by zero",23);
			return (84);
		}
	        if (argv[2][0] == '%' && my_getnbr(argv[3]) == 0) {
			write (2, "Stop : modulo by zero",21);
			return (84);
		}
		my_put_nbr(calcul(argv[1], argv[3], argv[2]));
		my_putchar('\n');
	}
}
