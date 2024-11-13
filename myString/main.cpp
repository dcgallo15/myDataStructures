#include <iostream>
#include<cstring>

/*What is finished:
    constructor
    copy constructor
    destructor
    [] operator
    Size method
    replace method
    pop method
    upper method
    lower method
    startsWith,endsWith
    islower,isupper
    count method
    includes method
    find method
    reverse
*/

/*What needs finishing:
    need to fix endsWith
    copy constructor rework
    dynamically allocated (with a maxsize)
    remove
    append
    centre,left,right
    optimisation
*/

class String
{
private:
    typedef unsigned int uint;
    char* buffer;
    uint size;
	void swap(char& val1, char& val2)
	{
		char temp = val1;
		val1 = val2;
		val2 = temp;
	}
public:
    String(const char* string)  // constructor
    {
        size = std::strlen(string);
        buffer = new char[size + 1];
        std::memcpy(buffer, string, size);
        buffer[size] = 0;
    }
    String(const String& other) // copy constructor NEED TO REWORK
        : size(other.size)
    {
        buffer = new char[size + 1];
        std::memcpy(buffer, other.buffer, size);
        buffer[std::strlen(other.buffer)] = 0;
    }
    ~String() // destructor
    {
        delete[] buffer;
    }
    char& operator [](uint index)
    {
        if (index > size or index < 0) { return buffer[size-1]; }   
        return buffer[index];
    }
    uint Size()
    {
        return size;
    }
    void replace(uint index, char whatToReplceWith)
    {
        if (index  > size or index < 0) { index = size -1; }
        buffer[index] = whatToReplceWith;
    }
    void pop(uint popAmount = 1)
    {
        if (popAmount > size or popAmount < 0) { popAmount = 1; }
        buffer[size - popAmount] = 0;
        size = size-popAmount;
    }
    void reverse() 
    {
		for (uint start = 0,end = size-1; start < end; start++,end--)
			swap(buffer[start], buffer[end]);
    }
    void upper() 
    {
        for (uint x = 0; x < size; x++) 
        {
            if (uint(buffer[x]) > 96 and uint(buffer[x]) < 123) 
            {
                buffer[x] = char(uint(buffer[x]) - 32);
            }
        }
    }
    void upper(uint index)  // overloaded upper
    {
        if (index > size or index < 0) { index = 0; }
		if (uint(buffer[index]) > 96 and uint(buffer[index]) < 123)
		{
			buffer[index] = char(uint(buffer[index]) - 32);
		}
    }
    void lower() 
    {
        for (uint x = 0; x < size; x++) 
        {
			if (uint(buffer[x]) > 64 and uint(buffer[x]) < 91)
			{
				buffer[x] = char(uint(buffer[x]) + 32);
			}
        }
    }
    void lower(uint index)  // overloaded lower
    {
		if (index > size or index < 0) { index = 0; }
        if (uint(buffer[index]) > 64 and uint(buffer[index]) < 91)
		{
			buffer[index] = char(uint(buffer[index]) + 32);
		}
    }
    bool startsWith(const char* t) 
    {
        for (uint i = 0; i < strlen(t); i++) 
        {
            if (buffer[i] != t[i]) { return false; }
        }
        return true;
    }
	bool endsWith(const char* t)    // is kinda backwards need to fix
	{
		for (uint i = 0; i < strlen(t); i++)
		{
			if (buffer[size-i-1] != t[i]) { return false; }
		}
		return true;
	}
    bool isUpper() 
    {
        for (uint x = 0; x < size; x++) 
        {
            if (uint(buffer[x]) < 65 or uint(buffer[x]) > 90) { return false; }
        }
        return true;
    }
    bool isUpper(uint index)    // overloaded isUpper
    { 
        if (index > size or index < 0) { index = 0; }
        if (uint(buffer[index]) < 65 or uint(buffer[index]) > 90) { return false; } 
        else { return true; }
    }   
    bool isLower() 
    {
		for (uint x = 0; x < size; x++)
		{
			if (uint(buffer[x]) < 97 or uint(buffer[x]) > 122) { return false; }
		}
		return true;
    }
	bool isLower(uint index)    // overloaded isUpper
	{
		if (index > size or index < 0) { index = 0; }
		if (uint(buffer[index]) < 97 or uint(buffer[index]) > 122) { return false; }
		else { return true; }
	}
    bool includes(char t) 
    {
        for (uint x = 0; x < size; x++) 
        {
            if (buffer[x] == t) { return true; }
        }
        return false;
    }
    uint count(char t)
    {
        uint amount = 0;
        for (uint x = 0; x < size; x++)
        {
            if (buffer[x] == t) { amount++; }
        }
        return amount;
    }
    uint find(char t) 
    {
		for (uint x = 0; x < size; x++)
		{
			if (buffer[x] == t) { return x; }
		}
		return -1;
    }
    friend std::ostream& operator<<(std::ostream& stream, const String& string);    // makes it so I can use buffer variable 
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
