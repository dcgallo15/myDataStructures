#include <iostream>
#include <vector>

template <typename T>
void swap(T& a, T& b) {
    T c = a;
    a = b;
    b = c;
}

template<typename T>
void reverse(std::vector<T>& vec) {
    for(int i = 0;i < vec.size(); ++i) {
        

    }
}

template<typename T>
void printVec(std::vector<T> vec) {
    for(int i =  0;i<vec.size();++i) {
        std::cout << vec[i] << '\n';
    }
}

int main() {
    std::vector<int> vec = {1,2,3,4,5};
    printVec(vec);
}