#include <iostream>
#include <array>
#include <algorithm>  // only work with myArray on visual studio

template <typename myArray>
class myArrayIterator
{
public:
  using valueType = typename myArray::valueType;
private:
  valueType* m_ptr;
public:
  myArrayIterator(valueType* ptr)
  {m_ptr = ptr;}

  myArrayIterator& operator ++ ()
  {
    m_ptr++;
    return *this;
  }

  myArrayIterator operator ++ (int)
  {
    myArrayIterator iterator = *this;
    ++(*this);
    return iterator;
  }

  myArrayIterator& operator -- ()
  {
    m_ptr--;
    return *this;
  }

  myArrayIterator operator -- (int)
  {
    myArrayIterator iterator = *this;
    --(*this);
    return iterator;
  }

  valueType& operator[](uint32_t index)
  {
    return *(m_ptr + index);
  }

  valueType* operator ->() const
  {
    return m_ptr;
  }

  valueType& operator*() const
  {
    return *m_ptr;
  }

  valueType operator + (int i)
  {
    return m_ptr + i;
  }

  valueType operator - (int i)
  {
    return m_ptr - i;
  }

  bool operator == (const myArrayIterator& other) const
  {
    return m_ptr == other.m_ptr;
  }

  bool operator != (const myArrayIterator& other) const
  {
    return !(*this == other);
  }

};

template <typename T, size_t m_size>
class myArray
{
    T arr[m_size];
public:

  using valueType = T;
  using iterator = myArrayIterator<myArray<valueType,m_size>>;

    myArray(){}

    myArray(T val)
    {
      for(int i = 0;i<m_size;i++)
      {
        arr[i] = val;
      }
    }

    myArray(std::initializer_list<T> init)
    {
        int i = 0;
        if(init.size() != m_size) throw "initializer_list is wrong size";
        for(auto elem : init)
        {
            arr[i] = elem;
            i++;
        }
    }

    myArray(const T other[m_size])
    {
        arr = other;
    }

    void operator = (std::array<T,m_size> other)
    {   
        for(size_t i= 0;i<other.size();i++)
        {
            arr[i] = other[i];
        }
    }

    void operator = (myArray <T,m_size> other)
    {
        for(size_t i= 0;i<other.size();i++)
        {
            arr[i] = other[i];
        }
    }

    void operator = (std::initializer_list<T> init)
    {
        int i = 0;
        if(init.size() != m_size) throw "initializer_list is wrong size";
        for(auto elem : init)
        {
            arr[i] = elem;
            i++;
        }
    }

    bool operator == (myArray<T,m_size> other) const
    {
      for(size_t i = 0;i<m_size; i++)
      {
        if(other[i] != this->arr[i])
          return false;
      }
      return true;
    }

    T& operator [] (uint32_t index)
    {
        if(index > m_size) throw "index is above size or array!";
        return arr[index];
    }

    [[nodiscard]] const T* get()  const // need to improve !!!
    {
        return arr;
    }

    void set(T t)
    {
        for(int i; i< m_size;i++)
        {
            arr[i] = t;
        }
    }

    [[nodiscard]] constexpr size_t size() const {return m_size;}

    void clear()
    {
      for(size_t i = 0;i<m_size;i++)
      {
        arr[i] = NULL;
      }
    }
  
  iterator begin()
  {
    return iterator(arr);
  }

  iterator end()
  {
    return iterator(arr+m_size);
  }

};

int main()
{
    std::array<int,5> arr2 = {1,2,3,4,5};
    myArray <int,5> arr = {1,2,3,4,5};
    
    //arr = arr2;

    for(auto elem : arr)
    {
        std::cout << elem << '\n';
    }
    return 0;
}