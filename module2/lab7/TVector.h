#ifndef __TVECTOR_INCLUDED__
#define __TVECTOR_INCLUDED__

#include <iostream>
template<typename T>
class TVector
{
public:
	using value_type = T;
	using size_type = size_t;
	using iterator = value_type *;
	using reference = value_type&;
	using const_reference = const value_type&;

private:
	value_type * Ptr;
	size_type Count;
	size_type InternalCapacity;
public:
	TVector()
		: Ptr(nullptr)
		, Count(0)
		, InternalCapacity(0)
	{ }

	TVector(size_type capacity)
		: Count(0)
		, InternalCapacity(capacity)
	{
		Ptr = new value_type[InternalCapacity];
	}

	~TVector()
	{
		delete[] Ptr;
	}

	bool empty() const throw()
	{
		return size() == 0;
	}

	size_type size() const throw()
	{
		return Count;
	}

	size_type capacity() const throw()
	{
		return InternalCapacity;
	}

	iterator begin() const throw()
	{
		return Ptr;
	}

	iterator end() const throw()
	{
		return Ptr + Count;
	}

	void reserve(size_type size)
	{
		if (size > 1073741823)
			throw std::exception("length error\n");
		if (size > InternalCapacity)
		{
			iterator NewVec = new value_type[size];
			memcpy_s(NewVec, size*sizeof(value_type), Ptr, InternalCapacity*sizeof(value_type));
			delete[] Ptr;
			Ptr = NewVec;
			InternalCapacity = size;
		}
	}

	TVector(const TVector& rhs)
	{
		iterator NewVec = new value_type[rhs.InternalCapacity];
		memcpy_s(NewVec, rhs.InternalCapacity*sizeof(value_type), rhs.Ptr, rhs.InternalCapacity*sizeof(value_type));
		Ptr = NewVec;
		Count = rhs.Count;
		InternalCapacity = rhs.InternalCapacity;

	}

	TVector& operator=(const TVector& rhs)
	{
		if (this == &rhs)
			return *this;
		if (InternalCapacity < rhs.InternalCapacity)
		{
			InternalCapacity = rhs.InternalCapacity;
		}
		iterator NewVec = new value_type[InternalCapacity];
		memcpy_s(NewVec, InternalCapacity*sizeof(value_type), rhs.Ptr, rhs.InternalCapacity*sizeof(value_type));
		Count = rhs.Count;
		if (!Ptr)
		{
			delete[] Ptr;
		}
		Ptr = NewVec;
	}

	void push_back(const value_type& value)
	{
		Count++;
		if (Count > InternalCapacity)
		{
			InternalCapacity = Count;
		}
		iterator NewVec = new value_type[InternalCapacity];
		if (Ptr)
			memcpy(NewVec, Ptr, InternalCapacity*sizeof(value_type));
		NewVec[Count - 1] = value;
		delete[] Ptr;
		Ptr = NewVec;
	}

	reference at(size_type index)
	{
		if (index < 0 || index >= Count)
			throw std::exception("out_of_range\n");
		return Ptr[index];
	}

	value_type at(size_type index) const
	{
		if (index < 0 || index >= Count)
			throw std::exception("out_of_range\n");
		return Ptr[index];
	}

	reference operator[](size_type index)
	{
		if (index < 0 || index >= Count)
			throw std::exception("out_of_range\n");
		return Ptr[index];
	}

	const_reference operator[](size_type index) const
	{
		if (index < 0 || index >= Count)
			throw std::exception("out_of_range\n");
		return Ptr[index];
	}

	reference front()
	{
		if (!Ptr)
			throw std::exception("vector isn't exist\n");
		return Ptr[0];
	}

	const_reference front() const
	{
		if (!Ptr)
			throw std::exception("vector isn't exist\n");
		return Ptr[0];
	}

	reference back()
	{
		if (!Ptr)
			throw std::exception("vector isn't exist\n");
		return Ptr[Count - 1];
	}

	const_reference back() const
	{
		if (!Ptr)
			throw std::exception("vector isn't exist\n");
		return Ptr[Count - 1];
	}

	void clear()
	{
		if (Ptr)
			delete[] Ptr;
		Count = 0;
		InternalCapacity = 0;
	}

	void pop_back()
	{
		if (Count == 0)
			throw std::exception("vector empty before pop\n");
		Count--;
		iterator NewVec = new value_type[InternalCapacity];
		memcpy_s(NewVec, InternalCapacity*sizeof(value_type), Ptr, Count*sizeof(value_type));
		delete[] Ptr;
		Ptr = NewVec;
	}

	void swap(TVector& other) throw()
	{
		std::swap(Ptr, other.Ptr);
		std::swap(Count, other.Count);
		std::swap(InternalCapacity, other.InternalCapacity);
	}

	void resize(size_type count, value_type value = value_type())
	{
		if (count > InternalCapacity)
		{
			InternalCapacity = count;
		}
		iterator NewVec = new value_type[InternalCapacity];
		memcpy_s(NewVec, InternalCapacity*sizeof(value_type), Ptr, count*sizeof(value_type));
		if (Count < count)
		{
			for (int i = Count; i < count; i++)
			{
				NewVec[i] = value;
			}
		}
		Count = count;
		delete[] Ptr;
		Ptr = NewVec;
	}

	iterator insert(iterator pos, const value_type& value)
	{
		if (pos < Ptr || pos > Ptr + Count - 1)
			throw std::exception("offset of range\n");
		Count++;
		if (Count > InternalCapacity)
			InternalCapacity = Count;
		iterator NewVec = new value_type[InternalCapacity];
		iterator begPtr = Ptr;
		int i = 0;
		while (i < Count)
		{
			if (begPtr == pos)
			{
				NewVec[i] = value;
				i++;
				NewVec[i] = *begPtr;
				begPtr++;
				i++;
				continue;
			}
			NewVec[i] = *begPtr;
			i++;
			begPtr++;
		}
		delete[] Ptr;
		Ptr = NewVec;
		return pos;
	}

	void insert(iterator pos, size_type count, const value_type& value)
	{
		if (pos < Ptr || pos > Ptr + Count - 1)
			throw std::exception("offset of range\n");
		for (int i = 0; i < count; i++)
			Count++;
		if (Count > InternalCapacity)
			InternalCapacity = Count;
		iterator NewVec = new value_type[InternalCapacity];
		iterator begPtr = Ptr;
		int i = 0;
		while (i < Count)
		{
			if (begPtr == pos)
			{
				for (int k = 0; k < count; k++)
				{
					NewVec[i] = value;
					i++;
				}
				NewVec[i] = *begPtr;
				i++;
				begPtr++;
				continue;
			}
			NewVec[i] = *begPtr;
			i++;
			begPtr++;
		}
		delete[] Ptr;
		Ptr = NewVec;
	}

	iterator erase(iterator pos)
	{
		if (pos < Ptr || pos > Ptr + Count - 1)
			throw std::exception("offset of range\n");
		Count--;
		iterator NewVec = new value_type[InternalCapacity];
		iterator begPtr = Ptr;
		int i = 0;
		while (i < Count)
		{
			if (begPtr == pos)
			{
				begPtr++;
				continue;
			}
			NewVec[i] = *begPtr;
			i++;
			begPtr++;
		}
		delete[] Ptr;
		Ptr = NewVec;
	}

	iterator erase(iterator first, iterator last)
	{
		if (first < Ptr || first > Ptr + Count - 1)
			throw std::exception("offset of range\n");
		else if (last > Ptr + Count - 1)
			throw std::exception("offset of range\n");
		for (iterator k = first; k != last; k++)
			Count--;
		iterator NewVec = new value_type[InternalCapacity];
		iterator begPtr = Ptr;
		int i = 0;
		while (i < Count)
		{
			if (begPtr == first)
			{
				while (begPtr != last)
					begPtr++;
				continue;
			}
			NewVec[i] = *begPtr;
			i++;
			begPtr++;
		}
		delete[] Ptr;
		Ptr = NewVec;
	}
};


#endif // __TVECTOR_INCLUDED__
