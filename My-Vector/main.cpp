#include "class.cpp"

/*Print Function*/
template<class U>
void print(std::initializer_list<U> list, std::string escapeChar = "\n")
{
	for (auto elem : list)
		std::cout << elem << escapeChar;
}

int main()
{
	/*Example Code*/
	vec <char> vector;
	vector({ 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' });
	print({ vector.Size() });
	vector.reverse();
	vector.printVector();
	print({ "\n" });
}