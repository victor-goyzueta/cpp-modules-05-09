#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <iostream>
# include <ctime>
# include <cstdlib>
# include <sstream>
# include <algorithm>

class PmergeMe
{
	private:
		PmergeMe( const PmergeMe& copy );
		PmergeMe& operator=( const PmergeMe& other );
		
		static std::vector<int>	parseInput(char **argv );

		static void	sortVector( std::vector<int>& vec );
		static void	sortDeque( std::deque<int>& deq );
		
		static void	print( const std::vector<int>& seq, const std::string& msg );
		
	
	public:
		PmergeMe();
		~PmergeMe();
		
		static void	process( char **argv );
};

#endif
