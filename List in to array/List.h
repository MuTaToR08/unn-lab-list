#pragma once


template <class E>
class List
{
	virtual void add(E e) = 0;
	virtual void clear() = 0;
	virtual bool contains(E e) = 0;
	virtual E get(size_t index) = 0;
	virtual int indexOf(E e) = 0;
	virtual bool isEmpty() = 0;
	virtual void remove(size_t index) = 0;
	virtual void set(size_t index, E e) = 0;
	virtual size_t size() = 0;
	virtual E* toArray() = 0;

};