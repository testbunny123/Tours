#include <iostream>

#include "board.h"
using namespace std;

#define ROWS 4
#define COLS 10 

int
main()
{
	Board *b = new Board( ROWS, COLS );
	b->recurse( 0, 0, ROWS * COLS - 1 );
	cout << Board::tours;
}
