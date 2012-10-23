#include "board.h"

int Board::tours;

Board::Board( const int r, const int c )
{
	tours = 0;
	_rows = r;
	_cols = c;

	visited = new bool*[ c ];
	for ( int i = 0; i < r; i++ )
	{
		visited[ i ] = new bool[ c ];
		for ( int j = 0; j < c; j++ )
			visited[ i ][ j ] = false;
	}
}

const
bool 
Board::valid( int x, int y )
{
	return ( x >= 0 && x < _rows && y >= 0 && y < _cols );
}

const
bool
Board::isGoal( int x, int y )
{
	return ( x == _rows - 1 && y == 0 );
}

void
Board::recurse( int x, int y, int remains )
{
	visited[ x ][ y ] = true;

	if ( isGoal( x, y ) )
	{
		visited[ x ][ y ] = false;

		if ( remains == 0 )
			Board::tours++;
		return;
	}

	if ( valid( x - 1, y ) && !visited[ x - 1 ][ y ] )
		recurse( x - 1, y, remains - 1 );

	if ( valid( x + 1, y ) && !visited[ x + 1][ y ] )
		recurse( x + 1, y, remains - 1 );

	if ( valid( x, y - 1 ) && !visited[ x ][ y - 1] )
		recurse( x, y - 1, remains - 1 );

	if ( valid( x, y + 1 ) && !visited[ x ][ y + 1 ] )
		recurse( x, y + 1, remains - 1 );

	visited[ x ][ y ] = false;
}
