/*
** EPITECH PROJECT, 2019
** add mul
** File description:
** ex02
*/

void add_mul_4param(int first, int second, int *sum, int *product)
{
    *sum = first + second;
    *product = first * second;
}

void add_mul_2param(int *first, int *second)
{
    int sum;
    int product;

    sum = *first + *second;
    product = *first * *second;
    *first = sum;
    *second = product;
}
