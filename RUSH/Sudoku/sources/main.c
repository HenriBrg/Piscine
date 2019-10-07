#include "functions.h"

int main(int argc, char **argv)
{
	int (*sudoku)[9];

	if (argc != 10)
		return (1);

	sudoku = fill_grid(argv);

	
	display_grid(sudoku);

	posValid(sudoku, 0); /* On commence à la position 0 */

	display_grid(sudoku);
	return (0);
}
