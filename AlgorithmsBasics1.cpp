#include <iostream>
#include <vector>
#include <iterator>
#include <ctime>
#include <algorithm>
#include <functional> 
#include "Player.h"


#pragma region "HelperFunctionsDeclarations"
void AddNumbers( std::vector<int>& numbers, int nr, int min, int max );
void AddPlayers( std::vector<Player>& players, int nr, int minScore, int maxScore );
void AddCharacters( std::string& text, int nr, char min, char max );
void PrintNumbers( const std::vector<int>& numbers );
void PrintPlayers( const std::vector<Player>& players );
void PrintSpace(int number);
void PrintComma(const Player& player);
void PrintEven(int number);
#pragma endregion "HelperFunctionsDeclarations"

#pragma region "TestFunctionsDeclarations"
void TestFor_Each( );
void TestAllAnyNone( );
void TestCount( );
void TestCount_if( );
void TestEqual( );
void TestLexicographical_compare( );
void TestFind( );
void TestFind_if( );
void TestFind_end( );
void TestAdjacent_find( );
void TestSearch( );
void TestMinMax( );

#pragma endregion "TestFunctionsDeclarations"

int main( )
{
	srand( unsigned int( time( nullptr ) ) );

	//TestFor_Each( );
	//TestAllAnyNone( );
	//TestEqual( );
	//TestLexicographical_compare( );
	//TestCount( );
	//TestCount_if( );
	//TestFind( );
	//TestFind_if( );
	//TestFind_end( );
	//TestAdjacent_find( );
	//TestSearch( );
	TestMinMax( );

	std::cout << "\nPress ENTER to quit\n";
	std::cin.get( );
	return 0;
}

#pragma region "HelperFunctionsDefinitions"
void AddNumbers( std::vector<int>& numbers, int nr, int min, int max )
{
	for ( int n = 0; n < nr; ++n )
	{
		numbers.push_back( rand( ) % ( max - min + 1 ) + min );
	}
}

void AddPlayers( std::vector<Player>& players, int nr, int minScore, int maxScore )
{
	std::cout << "Enter " << nr << " player names\n";
	std::istream_iterator<std::string> intInputIt{ std::cin };
	for ( int i{ 1 }; i < nr; ++i )
	{
		players.push_back( Player( *intInputIt, rand( ) % ( maxScore - minScore + 1 ) + minScore ) ); // use * to get element from the stream
		++intInputIt; // Move to next element
	}
	players.push_back( Player( *intInputIt, rand( ) % ( maxScore - minScore + 1 ) + minScore ) ); // last one

	std::cin.ignore( 10, '\n' );
}

void AddCharacters( std::string& text, int nr, char min, char max )
{
	for ( int n = 0; n < nr; ++n )
	{
		text.push_back( rand( ) % ( max - min + 1 ) + min );
	}
}

void PrintNumbers( const std::vector<int>& numbers )
{
	for ( int number : numbers )
	{
		std::cout << number << " ";
	}
}

void PrintPlayers( const std::vector<Player>& players )
{
	for ( const Player& p : players )
	{
		std::cout << p << "\n";
	}
}

void PrintSpace(int number)
{
	std::cout << number << ' ';
}

void PrintComma(const Player& player)
{
	std::cout << player << ',';
}

void PrintEven(int number)
{
	if (number % 2 == 0)
	{
		PrintSpace(number);
	}
}

#pragma endregion "HelperFunctions"

#pragma region "TestFunctionsDefinitions"

void TestFor_Each( )
{
	std::cout << "\n--> Test for_each\n";

	std::vector<int> numbers{};
	AddNumbers( numbers, 10, 20, 30 );
	// TODO: Print the numbers using for_each and with a space as delimiter
	std::cout << "Print numbers using for_each\n";
	std::for_each(numbers.begin(), numbers.end(), PrintSpace);

	std::cout << '\n';
	std::cout << '\n';

	std::vector<Player> players;
	AddPlayers( players, 4, 10, 60 );
	std::cout << "Print players using for_each\n";
	// TODO: Print the players using for_each and with a comma as a delimiter
	std::for_each(players.begin(), players.end(), PrintComma);

	std::cout << '\n';
	std::cout << '\n';
}

void TestAllAnyNone( )
{
	std::cout << "\n--> Using all_of, any_of, none_of\n";

	std::vector<int> numbers;
	AddNumbers( numbers, 3, 1, 11 );
	PrintNumbers( numbers );

	std::cout << '\n';

	std::cout << std::boolalpha;
	// TODO: Use all_of, any_of, none_of to show whether the elements are even. 
	std::cout << "All even ? " << '\n';
	if (std::all_of(numbers.begin(), numbers.end(), [](int i) {return i % 2 == 0; })) std::cout << "Yes \n";
	else std::cout << "No\n";
	std::cout << "Any even ? "  << '\n';
	if (std::any_of(numbers.begin(), numbers.end(), [](int i) {return i % 2 == 0; })) std::cout << "Yes \n";
	else std::cout << "No\n";
	std::cout << "None even ? "  << "\n";
	if (std::none_of(numbers.begin(), numbers.end(), [](int i) {return i % 2 == 0; })) std::cout << "Yes \n";
	else std::cout << "No\n";

	std::cout << "\n";

	// TODO: Use all_of, any_of, none_of to show whether the elements are prime. 
	std::cout << "All prime ? "  << '\n';
	if (std::all_of(numbers.begin(), numbers.end(), [](int i) {
		for (int j{ i - 1 }; j > 1; --j)
		{
			if (i%j == 0)
			{
				return false;
			}
		}
		return true;
	})) std::cout << "Yes \n";
	else std::cout << "No \n";

	std::cout << "Any prime ? "  << '\n';
	if (std::any_of(numbers.begin(), numbers.end(), [](int i) {
		if (i == 1) return false;
		for (int j{ 2 }; j < sqrt(i); ++j)
		{
			if (i%j == 0) return false;
		}
		return true;
	})) std::cout << "Yes \n";
	else std::cout << "No \n";

	std::cout << "None prime ? "  << '\n';
	if (std::none_of(numbers.begin(), numbers.end(), [](int i) {
		for (int j{ i - 1 }; j > 1; --j)
		{
			if (i%j == 0)
			{
				return false;
			}
		}
		if (i == 1) return false;
		return true;
	})) std::cout << "Yes \n";
	else std::cout << "No \n";
}

void TestEqual( )
{
	std::cout << "\n--> Using equal\n";

	std::string word{ "kayak" };
	std::string sentence{ "Never odd or even" };
	// TODO: Using equal to test whether a word or sentence is palindromic
	if (std::equal(word.begin(), word.end(), word.rbegin())) std::cout << word << " is palindromic\n";
	else std::cout << word << " is not palindromic\n";

	if (std::equal(sentence.begin(), sentence.end(), sentence.rbegin())) std::cout << sentence << " is palindromic\n";
	else std::cout << sentence << " is not palindromic\n";
}

void TestLexicographical_compare( )
{
	std::cout << "\n--> Using lexicographical_compare\n";

	std::string word1{ "Apache" };
	std::string word2{ "adjunct" };
	// TODO: Using lexicographical_compare with 4 parameters: 
	// verify whether 2  words are < or >= each other.
	std::cout << "Without converting to lower case\n";
	if (std::lexicographical_compare(word1.begin(), word1.end(), word2.begin(), word2.end())) std::cout << word1 << " < " << word2 << '\n';
	else std::cout << word1 << " >= " << word2 << '\n';

	// TODO: Do the test again for the same 2 words, 
	// however supply a 5th argument that compares the lower case value of the chars.
	std::cout << "With a comparer function that first converts to lower case\n";
	if (std::lexicographical_compare(word1.begin(), word1.end(), word2.begin(), word2.end(), [](const char& a, const char& b) {
		if (tolower(a) < tolower(b))
		{
			return true;
		}
		return false;
	})) std::cout << word1 << " < " << word2 << '\n';
	else std::cout << word1 << " >= " << word2 << '\n';
}

void TestCount( )
{
	std::cout << "\n--> Using count\n";

	std::vector<int> numbers;
	int min{ 5 };
	int max{ 7 };
	AddNumbers( numbers, 10, min, max );
	PrintNumbers( numbers );
	std::cout << '\n';
	// TODO: Print how many numbers are equal to 5, 6 and 7 using the count algorithm.
	std::cout << std::count(numbers.begin(), numbers.end(), 5) << " numbers have the value 5\n";
	std::cout << std::count(numbers.begin(), numbers.end(), 6) << " numbers have the value 6\n";
	std::cout << std::count(numbers.begin(), numbers.end(), 7) << " numbers have the value 7\n";

	std::string testString;
	AddCharacters( testString, 40, 'a', 'z' );
	std::cout << '\n' << testString << '\n';
	// TODO: Print how many times the letter w is in this testString
	std::cout << "Contains " << std::count(testString.begin(), testString.end(), 'w') << " times the letter w\n";

}

void TestCount_if( )
{
	std::cout << "\n--> Using count_if\n";

	std::vector<int> numbers;
	AddNumbers( numbers, 10, 1, 10 );
	PrintNumbers( numbers );
	std::cout << '\n';
	// TODO: Show how many prime numbers this sequence contains
	std::cout << std::count_if(numbers.begin(), numbers.end(), [](int i) {
		for (int j{ i - 1 }; j > 1; --j)
		{
			if (i % j == 0)
			{
				return false;
			}
		}
		if (i == 1) return false;
		return true;
	}) << '\n';

	std::string testString;
	AddCharacters( testString, 30, 'A', 'Z' );
	AddCharacters( testString, 30, 'a', 'z' );
	std::cout << '\n' << testString << '\n';
	// TODO: Show how many lower case characters the string contains
	std::wcout << std::count_if(testString.begin(), testString.end(), [](char a) {
		if (islower(a))
		{
			return true;
		}
		return false;
	}) << '\n';
}


void TestFind( )
{
	std::cout << "\n--> Using find\n";

	std::vector<int> numbers{ 1, 2, 3, 5, 6, 1, 2, 3, 5, 6, 1, 2, 3, 5, 6 };
	PrintNumbers( numbers );
	std::cout << '\n';

	// TODO: the first occurrence of the values 1 to 5 in a vector of numbers, 
	//  also show the position.
	std::vector<int>::iterator it;

	it = std::find(numbers.begin(), numbers.end(), 1);
	if(it != numbers.end())	std::cout <<"Value 1, first occurence at position "<< (it - numbers.begin()) << '\n';
	else std::cout << "Value 1 is not present\n";

	it = std::find(numbers.begin(), numbers.end(), 2);
	if (it != numbers.end())	std::cout << "Value 2, first occurence at position " << (it - numbers.begin()) << '\n';
	else std::cout << "Value 2 is not present\n";

	it = std::find(numbers.begin(), numbers.end(), 3);
	if (it != numbers.end())	std::cout << "Value 3, first occurence at position " << (it - numbers.begin()) << '\n';
	else std::cout << "Value 3 is not present\n";

	it = std::find(numbers.begin(), numbers.end(), 4);
	if (it != numbers.end())	std::cout << "Value 4, first occurence at position " << (it - numbers.begin()) << '\n';
	else std::cout << "Value 4 is not present\n";

	it = std::find(numbers.begin(), numbers.end(), 5);
	if (it != numbers.end())	std::cout << "Value 5, first occurence at position " << (it - numbers.begin()) << '\n';
	else std::cout << "Value 5 is not present\n";

}

void TestFind_if( )
{
	std::cout << "\n--> Using find_if\n";

	std::vector<int> numbers;
	AddNumbers( numbers, 15, 10, 14 );
	PrintNumbers( numbers );
	std::cout << '\n';
	// TODO: Find the first prime number, also show its position in this sequence
	std::vector<int>::iterator it;
	it = std::find_if(numbers.begin(), numbers.end(), [](int i) {
		for (int j{ i - 1 }; j > 1; --j)
		{
			if (i % j == 0)
			{
				return false;
			}
		}
		if (i == 1)
		{
			return false;
		}
		return true;
	});
	if (it != numbers.end())
	{
		std::cout << "Prime number " << *it << " found at index " << (it - numbers.begin()) << '\n';
	}
	else
	{
		std::cout << "No prime number found...\n";
	}
}

void TestFind_end( )
{
	std::cout << "\n--> Using find_end\n";
	std::string testString{ "abcdef_abcdef_" };
	std::string toFindString1{ "abc" };
	std::string toFindString2{ "cba" };

	// TODO: Find the a sequence in the given string and show the found position.
	//		 once for toFindString1
	//		 once for toFindString2

	std::string::iterator it;
	it = std::find_end(testString.begin(), testString.end(), toFindString1.begin(), toFindString1.end());
	if (it != testString.end()) std::cout << "Last occurence of sequence " << toFindString1 << " found at " << (it - testString.begin()) << '\n';
	else std::cout << "Sequence " << toFindString1 << " not found\n";

	it = std::find_end(testString.begin(), testString.end(), toFindString2.begin(), toFindString2.end());
	if (it != testString.end()) std::cout << "Last occurence of sequence " << toFindString2 << " found at " << (it - testString.begin()) << '\n';
	else std::cout << "Sequence " << toFindString2 << " not found\n";
}

void TestAdjacent_find( )
{
	std::cout << "\n--> Using adjacent_find\n";

	std::vector<int> numbers{ 1, 4, 3, 5, 6, 1, 5, 6 };
	PrintNumbers( numbers );
	std::cout << '\n';

	// TODO: find whether the given sequence of numbers 
	// contains two adjacent prime numbers, also show the position.
	std::vector<int>::iterator it{};
	it = std::adjacent_find(numbers.begin(), numbers.end(), [](int i, int j) {
		for (int k{ i - 1 }; k > 1; --k)
		{
			if (i % k == 0)
			{
				return false;
			}
		}
		if (i == 1)
		{
			return false;
		}
		for (int k{ j - 1 }; k > 1; --k)
		{
			if (j % k == 0)
			{
				return false;
			}
		}
		if (j == 1)
		{
			return false;
		}
		return true;
	});
	if (it != numbers.end()) std::cout << "2 adjecent prime numbers found at " << (it - numbers.begin()) << '\n';
	else std::cout << "No adjecent prime numbers found\n";

	std::string testString{ "cdefghijklmn" };
	//std::string testString{ "srqponm" };
	//std::string testString{ "srqpnom" };
	std::cout << '\n' << testString << '\n';

	// TODO: find whether the given strings are:
	//	- sorted in alpabetical order
	//  - sorted in reverse alpabetical order
	//  not sorted

	std::string::iterator it2{};
	it2 = std::adjacent_find(testString.begin(), testString.end(), std::greater<char>());
	if (it2 == testString.end()) std::cout << "Sorted alphabetically\n";
	else
	{
		it2 = std::adjacent_find(testString.begin(), testString.end(), std::less<char>());
		if (it2 == testString.end()) std::cout << "Sorted reverse alphabetically\n";
		else std::cout << "not sorted\n";
	}


	std::vector<std::string> words{ "apple","orange","pea","pear","tomato" };
	//std::vector<std::string> words{ "apple","pea","orange","pear","tomato" };
	std::cout << '\n';
	for ( const std::string& word : words )
	{
		std::cout << word << " ";
	}
	std::cout << '\n';

	// TODO: find whether the given vector of words is sorted in alpabetical order
	std::vector<std::string>::iterator it3{};
	it3 = std::adjacent_find(words.begin(), words.end(), std::greater<std::string>());
	if (it3 == words.end()) std::cout << "Sorted alphabetically\n";
	else std::cout << "not sorted\n";

}

void TestSearch( )
{
	std::cout << "\n--> Using search\n";

	std::string testString = "In order to understand recursion, one must first understand recursion. (Anonymous)";
	std::string searchString = "recursion";
	std::cout << "Find '" << searchString << "' occurrences \nin the string '";
	std::cout << testString << "'\n";
	// TODO: Find the positions of the given searchString in the given testString

	std::string::iterator it{};
	it = std::search(testString.begin(), testString.end(), searchString.begin(), searchString.end());
	if (it != testString.end()) std::cout << "Found at position " << it - testString.begin() << '\n' << "Found at position " << testString.end() - it + 1 << '\n';
	else std::cout << "Not found\n";
}

void TestMinMax( )
{
	std::vector<int> numbers;
	AddNumbers( numbers, 10, 1, 10 );
	PrintNumbers( numbers );
	std::cout << '\n';

	std::cout << "--> Using max_element\n";
	// TODO: Find the maximum element in the given numbers sequence using operator<
	std::vector<int>::iterator it{};
	it = std::max_element(numbers.begin(), numbers.end());
	std::cout << "Max element is " << *it << '\n';

	std::cout << "--> Using min_element\n";
	// TODO: Find the minimum element in the given numbers sequence using operator<
	std::vector<int>::iterator it2{};
	it2 = std::min_element(numbers.begin(), numbers.end());
	std::cout << "Min element is " << *it2 << '\n';

	// TODO : Give the distance between the min and max element
	std::cout << "Distance between min and max is " << std::distance(it, it2) << '\n';

	std::vector<Player> players{
		Player{ "Annelies", rand( ) },
		Player{ "Jef", rand( ) },
		Player{ "Pieter-Jan", rand( ) },
		Player{ "Claudy", rand( ) } };
	std::cout << '\n';
	PrintPlayers( players );
	std::cout << '\n';

	std::cout << "--> Using max_element\n";
	// TODO: Find the maximum element in the given players 
	// using a binary comparison function that compares the scores using operator<
	std::vector<Player>::iterator it3{};
	it3 = std::max_element(players.begin(), players.end(), [](const Player& player1, const Player& player2) {
		return player1.GetScore() < player2.GetScore();
	});
	std::cout << "The player with the biggest score is " << (*it3).GetName() << '\n';

}
#pragma endregion "TestFunctionsDefinitions"
