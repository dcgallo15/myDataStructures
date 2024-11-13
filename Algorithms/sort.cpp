#include <iostream>
#include <vector>

template<typename T>
void swap(T& a,T& b)
{
  T c = a;
  a = b;
  b = c;
}

template<typename T>
void bubbleSort(std::vector<T>& arr)  // O(n^2)
{
  for(int i = 0;i<arr.size()-1;i++)
  {
    for(int j = 0;j<arr.size()-i-1;j++)
    {
      if((int)arr[j] > (int)arr[j+1])
        swap(arr[j],arr[j+1]);
    }
  }
}

std::vector<int> merge(std::vector<int>& left ,std::vector<int>& right)
{
  std::vector<int> res = {};

  while(!left.empty() && !right.empty())
  {
    if(left[0] <= right[0])
    {
      res.push_back(left[0]);
      left.erase(left.begin());
    }
    else
    {
      res.push_back(right[0]);
      right.erase(right.begin());
    }
  }

  while(!left.empty())
  {
    res.push_back(left[0]);
    left.erase(left.begin());
  }
  
  while(!right.empty())
  {
    res.push_back(right[0]);
    right.erase(right.begin());
  }
  return res;
}

std::vector<int> mergeSort(std::vector<int>& arr) // O(n log n)
{
  if (arr.size() <= 1) {return arr;}
  std::vector<int> L = {};
  std::vector<int> R = {};

  for(int i = 0;i<arr.size();++i)
  {
    if(i<(arr.size()/2))
    {
      L.push_back(arr[i]);
    }
    else
    {
      R.push_back(arr[i]);
    }
  }

  L = mergeSort(L);
  R = mergeSort(R);

  return merge(L,R);
}

int main() 
{
  std::vector<int> arr = {2,1,4,3};
  for(auto elem : arr)
    std::cout << elem << '\n';

  std::cout << '\n' << "---------------------------" << '\n' << '\n';

  arr = mergeSort(arr);

  for(auto elem : arr)
    std::cout << elem << '\n';

}