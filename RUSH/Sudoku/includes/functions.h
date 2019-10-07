#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <unistd.h>
#include <time.h>

void ft_putchar(char c);
void ft_putstr(char *str);
void ft_putnbr(int nbr);
int (*fill_grid(char **argv))[9];
void display_grid(int (*grid)[9]);

int posValid(int (*grid)[9], int pos);
int absentLine(int (*grid)[9], int line, int nbr);
int absentColumn(int (*grid)[9], int column, int nbr);
int absentBlock(int (*grid)[9], int line, int column, int nbr);

#endif
