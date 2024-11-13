#include <iostream>
#include <map>
#include <string>

inline void NEWLINE(){std::cout << "\n";}

template <typename T>
void ask(T& var,const char * toEnter)
{
    std::cout << toEnter << ": ";
    std::cin >> var;
    NEWLINE();
}

int main()
{
    std::map<int,std::string> data;
    std::string name = {};
    int age = {};
    std::string stop = {};

    while(stop != "y")
    {
        ask(name,"Enter your name");
        ask(age,"Enter your age");
        data.emplace(std::make_pair(age,name));
        ask(stop,"Do you want to stop y/n");
    }

    for(auto elem : data)
    {
        std::cout << elem.second << " is " << elem.first  << " years old" << '\n';
    }
}
