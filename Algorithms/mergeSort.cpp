#include <iostream>
#include <vector>

template <typename T>
void mergeSort(std::vector<T>& left, std::vector<T>& right, std::vector<T>& bar) {
	std::size_t j{0}, i{0}, k{0};

	while(j < left.size() && k < right.size()) {

		if(left[j] < right[k]) {
			bar[i] = left[j];
			++j;
		} else {
			bar[i] = right[k];
			++k;
		}
		++i;
	}
	while(j < left.size()) {
		bar[i] = left[j];
		++j;
		++i;
	}
	while(k < right.size()) {
		bar[i] = right[k];
		++k;
		++i;
	}
}

template <typename T>
void sort(std::vector<T>& bar) {
	if(bar.size() <= 1) { return; }

	std::size_t mid = bar.size() / 2;
	std::vector<T> left;
	std::vector<T> right;

	for(std::size_t i = 0; i < mid; ++i) { left.push_back(bar[i]); }
	for(std::size_t i = 0; i < mid; ++i) { right.push_back(bar[mid + i]); }

	sort(left);
	sort(right);
	mergeSort(left, right, bar);
}

int main() {
	std::vector<int> vec = {2, 3, 4, 1};
	sort(vec); // O(n*log(n))
	for(auto elem : vec) { std::cout << elem << '\n'; }
}

