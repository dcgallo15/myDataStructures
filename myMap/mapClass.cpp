#include "pairClass.cpp"
#include <utility> // to access std::pair
// TODO: make own pair class
#include <cstdint>
#include <iostream>

template <typename myMap>
class myMapIterator // TODO: make more operator overloads
{
public:
	using valType = typename myMap::valType;
	using keyType = typename myMap::keyType;

private:
	valType* m_valPtr;
	keyType* m_keyPtr;

public:
	myMapIterator(keyType* keyPtr, valType* valPtr)
	{
		m_keyPtr = keyPtr;
		m_valPtr = valPtr;
	}

	myMapIterator& operator++()
	{
		m_keyPtr++;
		m_valPtr++;
		return *this;
	}

	myMapIterator operator--()
	{
		m_keyPtr--;
		m_valPtr--;
		return *this;
	}

	std::pair<keyType, valType>& operator+(int i) { return std::make_pair(m_keyPtr + i, m_valPtr + i); }

	std::pair<keyType, valType>& operator-(int i) { return std::make_pair(m_keyPtr - i, m_valPtr - i); }

	std::pair<keyType, valType>& operator[](std::uint32_t index)
	{
		return std::make_pair((*(m_keyPtr + index)), (*m_valPtr + index));
	}

	std::pair<keyType, valType> operator*() const { return std::make_pair(*m_keyPtr, *m_valPtr); }

	bool operator==(const myMapIterator& other) const { return m_keyPtr == other.m_keyPtr; }

	bool operator!=(const myMapIterator& other) const { return !(*this == other); }
};

template <typename keyT, typename valT>
class myMap
{
private:
	keyT* key;
	valT* val;
	std::size_t m_size;
	std::uint32_t maxSize;

	void allocNew() // TODO: test
	{
		maxSize = m_size * 2;
		keyT* keyTmp = new keyT[maxSize];
		valT* valTmp = new valT[maxSize];

		for(std::size_t i = 0; i < m_size; i++)
		{
			keyTmp[i] = this->key[i];
			valTmp[i] = this->val[i];
		}

		delete[] val;
		delete[] key;
		val = valTmp;
		key = keyTmp;
	}

public:
	using valType = valT;
	using keyType = keyT;
	using iterator = myMapIterator<myMap<keyT, valT>>;
	using sizeType = std::size_t;

	myMap()
	{
		maxSize = 20;
		key = new keyT[maxSize];
		val = new valT[maxSize];
		m_size = 0;
	}

	myMap(std::initializer_list<std::pair<keyT, valT>> init)
	{
		maxSize = 20;
		m_size = init.size();
		val = new valT[maxSize];
		key = new keyT[maxSize];
		if(init.size() > maxSize) { allocNew(); }
		int i = 0;
		for(auto elem : init)
		{
			key[i] = elem.first;
			val[i] = elem.second;
			++i;
		}
	}

	void operator=(std::initializer_list<std::pair<keyT, valT>> init)
	{
		m_size += init.size();
		if(m_size > maxSize) { allocNew(); }
		int i = 0;
		for(auto elem : init)
		{
			key[i] = elem.first;
			val[i] = elem.second;
			++i;
		}
	}

	void operator=(myMap<keyT, valT>& other)
	{
		std::size_t i = 0;
		for(auto elem : other)
		{
			key[i] = other.first;
			val[i] = other.second;
			i++;
		}
	}

	~myMap()
	{
		delete[] key;
		delete[] val;
	}

	[[nodiscard]] valT& operator[](keyT key)
	{
		for(std::size_t i = 0; i < m_size; i++)
			if(this->key[i] == key) return val[i];
		throw "Element not found!";
	}

	bool operator==(myMap& other) const
	{
		if(other.size() != m_size) return false;

		std::size_t i = 0;
		for(auto elem : other)
		{
			if(elem != std::make_pair(key[i], val[i])) return false;
		}
		return true;
	}

	void emplace(myPair<keyT, valT> input)
	{
		if(m_size + 1 > maxSize) allocNew();
		this->key[m_size] = input.first;
		this->val[m_size] = input.second;
		++m_size;
	}

	void emplace(std::pair<keyT, valT> input)
	{
		if(m_size + 1 > maxSize) allocNew();
		this->key[m_size] = input.first;
		this->val[m_size] = input.second;
		++m_size;
	}

	void erase(keyT toBeErased) // takes in a key and will remove the key and value pair associated
								// with it
	{
		bool found = false;
		uint32_t x = {};

		for(uint32_t i = 0; i < m_size; i++)
		{
			if(key[i] == toBeErased)
			{
				found = true;
				--x;
			}
			else
			{
				key[x] = key[i];
				val[x] = val[i];
			}
			++x;
		}
		if(found) --m_size;
	}

	std::size_t find(keyT k) const
	{
		auto i = sizeType{};
		for(auto elem : *this)
		{
			if(elem.first == k) return i;
			++i;
		}
		return -1;
	}

	uint32_t count(keyT k) const
	{
		auto i = sizeType{};
		uint32_t counter = {};
		for(auto elem : *this)
		{
			if(elem.first == k) { ++counter; }
			++i;
		}
		return counter;
	}

	[[nodiscard]] std::size_t size() const { return this->size; }

	[[nodiscard]] bool empty() const
	{
		if(m_size + 1 > 0) return false;
		return true;
	}

	iterator begin() const { return myMapIterator<myMap<keyT, valT>>(key, val); }

	iterator end() const { return myMapIterator<myMap<keyT, valT>>(key + m_size, val + m_size); }
};
