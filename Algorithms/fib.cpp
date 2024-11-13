#include <iostream>
#include <map>
#include <string>

int fib(int n, std::map<int, int> memo = {})
{
	auto found = memo.find(n);
	if(found != std::end(memo)) { return found->second; }
	if(n < 3) return 1;
	memo[n] = fib(n - 1, memo) + fib(n - 2, memo);
	return memo[n];
}

int badFib(int n)
{
	if(n < 3) return 1;
	return badFib(n - 1) + badFib(n - 2);
}

int main()
{
	std::cout << fib(40) << '\n';
}
