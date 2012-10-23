class Board
{
	public:
		Board( const int r, const int c );
		void recurse( int, int, int );

		static int tours;
	private:
		const bool valid( int, int );
		const bool isGoal( int, int );
		int _rows;
		int _cols;
		bool **visited;
};
