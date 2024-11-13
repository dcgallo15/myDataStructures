#include <iostream>
#include <cstring>

class myString
{
private:
  char* buffer;
  uint32_t m_size;
public:
  myString(const char* string)  // constructor
  {
      m_size = strlen(string);
      buffer = new char[m_size + 1];
      std::memcpy(buffer, string, m_size);
      buffer[m_size] = 0;
  }

  uint32_t size() const
  {
    return m_size;
  }

  myString(const myString& other)
  {
    this-> m_size = other.size();
    buffer = new char[m_size + 1];
    std::memcpy(buffer, other.buffer, m_size);
    buffer[std::strlen(other.buffer)] = 0;

    // std::cout << "Copied!" << '\n';
  }

  ~myString(){delete[] buffer;}

  char& operator [](uint32_t index)
  {
    if(index > m_size-1) throw "Index out of bounds!";
    return buffer[index];
  }

  void operator = (const char* string)
  {
    m_size = strlen(string);
    buffer = new char[m_size + 1];
    std::memcpy(buffer, string, m_size);
    buffer[m_size] = 0;
  }

  void operator = (myString& other)
  {
    this-> m_size = other.size();
    buffer = new char[m_size + 1];
    std::memcpy(buffer, other.buffer, m_size);
    buffer[std::strlen(other.buffer)] = 0;
  }

  [[nodiscard]] myString operator + (myString& other) const
  {
    myString ret("");
    ret.m_size = other.size() + this->m_size;
    ret.buffer = new char[ret.m_size + 1];

    for(int i = 0;i<this->m_size;i++)
    {
      ret.buffer[i] = this->buffer[i];
    }
    for(int i = this->m_size;i<ret.m_size;i++)
    {
      ret.buffer[i] = other.buffer[i-this->m_size];
    }

    buffer[ret.m_size] = 0;
    return ret;
  }

  friend std::ostream& operator << (std::ostream& stream,const myString& str);

};

std::ostream& operator << (std::ostream& stream,const myString& str)
{
  stream << str.buffer;
  return stream;
}

int main() {
  myString hi = "Hello";
  myString world(" World");

  myString hiWorld = hi + world;

  std::cout << hiWorld << '\n';
}