#include<iostream>

const size_t INIT_CAPACITY = 4;

template <class K, class V>
class Dictionary
{
private:
	struct Pair
	{
		K key;
		V value;
	};

	Pair** pairs;
	size_t size = 0;
	size_t capacity = INIT_CAPACITY;

	void copy(const Dictionary& other);
	void free();
	void move(Dictionary&& other);

	bool find(K key, size_t& index) const;

public:

	Dictionary();
	Dictionary(const Dictionary& other);
	Dictionary(Dictionary&& other);
	Dictionary& operator=(const Dictionary& other);
	Dictionary& operator=(Dictionary&& other);
	~Dictionary();

	void resize(size_t capacity);
	const V& get(const K& key, const V& deffValue) const;
	bool update(const K& key, const V& value);
	bool add(const K& key, const V& value);
	bool remove(const K& key);
	bool contains(const K& key) const;
	bool operator[](const K& key) const;


};

template<class K, class V>
void Dictionary<K, V>::copy(const Dictionary& other)
{
	size = other.size;
	capacity = other.capacity;

	pairs = new Pair* [capacity];

	for (size_t i = 0; i < size; i++)
	{
		pairs[i] = new Pair(*other.pairs[i]);
	}
}

template<class K, class V>
void Dictionary<K, V>::free()
{
	for (size_t i = 0; i < size; i++)
	{
		delete pairs[i];
	}

	delete[] pairs;
}

template<class K, class V>
void Dictionary<K, V>::move(Dictionary&& other)
{
	size = other.size;
	capacity = other.capacity;
	pairs = other.pairs;
	other.pairs = nullptr;
	other.size = 0;
}

template<class K, class V>
bool Dictionary<K, V>::find(K key, size_t& index) const
{

	int low = 0;
	int high = size - 1;
	int mid = (high + low) / 2;

	while (low <= high)
	{
		K currKey = pairs[mid]->key;

		if (currKey == key)
		{
			index = mid;
			return true;
		}

		if (currKey < key)
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}

		mid = (high + low) / 2;
	}


	return false;
}



template<class K, class V>
Dictionary<K, V>::Dictionary()
{
	pairs = new Pair* [capacity];
}

template<class K, class V>
Dictionary<K, V>::Dictionary(const Dictionary& other)
{
	copy(other);
}

template<class K, class V>
Dictionary<K, V>::Dictionary(Dictionary&& other)
{
	move(std::move(other));
}

template<class K, class V>
Dictionary<K, V>& Dictionary<K, V>::operator=(const Dictionary& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

template<class K, class V>
Dictionary<K, V>& Dictionary<K, V>::operator=(Dictionary&& other)
{
	if (this != &other)
	{
		free();
		move(std::move(other));
	}

	return *this;
}

template<class K, class V>
Dictionary<K, V>::~Dictionary()
{
	free();
}

template<class K, class V>
void Dictionary<K, V>::resize(size_t capacity)
{
	if (capacity < size)
		throw "Capacity too small";

	this->capacity = capacity;

	Pair** newPairs = new Pair* [capacity];

	for (size_t i = 0; i < size; i++)
	{
		newPairs[i] = pairs[i];
	}

	delete[] pairs;

	pairs = newPairs;
}

template<class K, class V>
const V& Dictionary<K, V>::get(const K& key, const V& deffValue) const
{
	size_t index;

	if (find(key, index))
	{
		return pairs[index]->value;
	}

	return deffValue;
}

template<class K, class V>
bool Dictionary<K, V>::update(const K& key, const V& value)
{
	size_t index;

	if (find(key, index))
	{
		pairs[index]->value = value;
		return true;
	}

	return false;
}

template<class K, class V>
bool Dictionary<K, V>::add(const K& key, const V& value)
{
	size_t index;

	if (find(key, index))
		return false;

	if (size == capacity)
		resize(capacity * 2);

	index = size;

	while (index > 0 && pairs[index - 1]->key > key)
	{
		pairs[index] = pairs[index - 1];
		index--;
	}

	pairs[index] = new Pair({ key, value });
	size++;

	return true;
}

template<class K, class V>
bool Dictionary<K, V>::remove(const K& key)
{
	size_t index;

	if (!find(key, index))
		return false;

	size--;

	delete pairs[index];

	for (size_t i = index; i < size; i++)
	{
		pairs[i] = pairs[i + 1];
	}

	return true;
}

template<class K, class V>
bool Dictionary<K, V>::contains(const K& key) const
{
	size_t index;
	return find(key, index);
}

template<class K, class V>
bool Dictionary<K, V>::operator[](const K& key) const
{
	return contains(key);
}
