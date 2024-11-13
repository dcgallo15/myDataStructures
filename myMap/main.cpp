#include <iostream>
#include <map>
#include <string>

#include "mapClass.cpp"

int main()
{
	myMap<int, std::string> map2 = {{5, "HelloWorld"}, {4, "NotHelloWorld"}};
	map2.emplace(std::make_pair(5, "HelloWorldAgain"));
	map2.emplace(std::make_pair(6, "HelloWorldAgain"));
	map2.erase(6);
	std::cout << "Amount of 5's: " << map2.count(5) << '\n';
	for(auto elem : map2) std::cout << "Key: " << elem.first << " Value: " << elem.second << '\n';

	myPair<int, std::string> pair{5, "HelloWorld"};
	std::cout << "First: " << pair.first << " Second: " << pair.second << '\n';
}
