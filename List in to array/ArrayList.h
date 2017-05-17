#pragma once
#include "List.h"
#include "Exception.h"

template<class E>
class ArrayList :
	public List<E>
{
private:
	int *links;
	E      *data;
	size_t start, end;
	size_t sizeArr, count;

public:

	ArrayList(int size)
	{
		if (size < 0)
			throw SIZE_EXCEPTION;
		sizeArr = size;
		links = new int[size];
		data = new E[size];
		for (size_t i = 0; i < this->sizeArr; i++)
			links[i] = -1;
		count = end = start = 0;
	}

	virtual ~ArrayList()
	{
		delete[] links;
		delete[] data;
	}
	virtual void add(E e);
	virtual void add(E e, bool inStart);
	virtual void clear();
	virtual bool contains(E e);
	virtual E get(size_t index);
	virtual int indexOf(E e);
	virtual bool isEmpty();
	virtual void remove(size_t index);
	virtual void set(size_t index, E e);
	virtual size_t size();
	virtual E* toArray();


	void firstDelete()
	{
		remove(0);
	}
	void lastDelete()
	{
		remove(count - 1);
	}

};


template<class E>
void ArrayList<E>::add(E e)
{
	add(e, false);
}

template<class E>
void ArrayList<E>::add(E e, bool inStart)
{
	if (count == sizeArr)
		throw OVERFLOW_EXCEPTION;
	size_t index = -1;
	if (count == 0)
		index = start = end = 0;
	else
	{
		for (size_t i = 0; i < sizeArr; i++)
		{
			if (links[i] == -1)
			{
				if (inStart)
				{
					links[i] = start;
					start = i;
				}
				else {
					links[end] = i;
					end = i;
				}
				index = i;
				break;
			}
		}
	}
	data[index] = e;
	links[end] = start;
	++count;
}

template<class E>
void ArrayList<E>::clear()
{
	if (count == 0)
		return;
	bool stop = false;
	for (size_t i = start; !stop; i = links[i])
	{
		if (i == end)
			stop = true;

		links[i] = -1;
	}
	count = 0;
	end = start = -1;
}

template<class E>
bool ArrayList<E>::contains(E e)
{
	bool ret = false;
	bool stop = false;
	for (size_t i = start; !stop; i = links[i])
	{
		if (i == end)
			stop = true;
		if (data[i] == e)
		{
			ret = true;
			break;
		}

	}

	return ret;
}

template<class E>
E ArrayList<E>::get(size_t index)
{
	if (index >= count)
		throw INDEX_ERROR_EXCEPTION;
	bool stop = false;
	for (size_t i = start, counter=0; !stop; i = links[i],counter++)
	{
		if (i == end)
			stop = true;
		if (counter == index)
			return data[i];

	}

	return E();
}

template<class E>
int ArrayList<E>::indexOf(E e)
{
	bool stop = false;
	int counter = 0;
	for (size_t i = start; !stop; i = links[i], counter++)
	{
		if (i == end)
			stop = true;
		if (data[i] == e)
			return counter;
	}
	return -1;
}

template<class E>
inline bool ArrayList<E>::isEmpty()
{
	return (count==0);
}

template<class E>
void ArrayList<E>::remove(size_t index)
{
	if (index >= count)
		throw INDEX_ERROR_EXCEPTION;
	size_t prev = start;
	bool stop = false;
	int counter = 0;
	for (size_t i = start; !stop; i = links[i], counter++)
	{
		if (i == end)
			stop = true;
		if (counter == index)
		{
			if (i == start)
				start = links[i];
			if (i == end)
				end = links[prev];
			if (i != end && i != start)
				links[prev] = links[i];

			links[i] = -1;
			break;
		}
		prev = i;
	}
	--count;
}

template<class E>
void ArrayList<E>::set(size_t index, E e)
{
	if (index >= count)
		throw INDEX_ERROR_EXCEPTION;
	size_t *prev = &start;
	bool stop = false;
	int counter = 0;
	for (size_t i = start; !stop; i = links[i], counter++)
	{
		if (i == end)
			stop = true;
		if (counter == index)
		{
			data[i] = e;
			break;
		}
	}
}

template<class E>
inline size_t ArrayList<E>::size()
{
	return count;
}

template<class E>
inline E * ArrayList<E>::toArray()
{
	E *tmp = new E[count];
	bool stop = false;
	int counter = 0;
	for (size_t i = start; !stop; i = links[i], counter++)
	{
		if (i == end)
			stop = true;
		tmp[counter] = data[i];
	}
	return tmp;
}
