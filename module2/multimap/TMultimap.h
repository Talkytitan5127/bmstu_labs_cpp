#include <iostream>
#include <vector>
#include <map>

template<class Key, class T>
class TMultimap
{
	using key_type = Key;
	using mapped_type = T;
	using value_type = std::pair<key_type, mapped_type>;
	using reference = value_type&;
	using const_reference = const value_type&;
	using iterator = value_type*;
	using const_iterator = const value_type*;
	using size_type = size_t;

	struct Tree
	{
		key_type KeyName;
		std::vector<mapped_type> Data;
		Tree* pLeft;
		Tree* pRight;
		Tree* pRoot;
		int IndDat;
		iterator ptr;
	};

	typedef Tree* pTree;
	using vec_type = std::vector<pTree>;

	pTree Root = nullptr;
	vec_type MasPtr;
	size_type Count;

	pTree FindElem(const value_type& rhs)
	{
		pTree tmp = Root;
		while (true)
		{
			if (tmp)
			{
				if (tmp->pRoot)
				{
					if (tmp->KeyName < rhs.first && tmp->pRoot->KeyName > rhs.first)
						return nullptr;
				}
				if (tmp->KeyName == rhs.first)
					return tmp;
				else
				{
					if (rhs.first < tmp->KeyName)
						tmp = tmp->pLeft;
					else
						tmp = tmp->pRight;
				}
			}
			else
				return nullptr;
		}
	}
	pTree FindKey(const key_type& rhs)
	{
		pTree tmp = Root;
		while (true)
		{
			if (tmp)
			{
				if (tmp->KeyName == rhs)
					return tmp;
				else
				{
					if (rhs < tmp->KeyName)
						tmp = tmp->pLeft;
					else
						tmp = tmp->pRight;
				}
			}
			else
			{
				return nullptr;
			}
		}
	}
	void Sort()
	{
		for (int i = 0; i < MasPtr.size(); i++)
		{
			pTree pMin = MasPtr[i];
			int ind = i;
			for (int j = i + 1; j < MasPtr.size(); j++)
			{
				if (MasPtr[j]->KeyName < pMin->KeyName)
				{
					ind = j;
					pMin = MasPtr[j];
				}
			}
			if (ind != i)
				std::swap(MasPtr[i], MasPtr[ind]);
		}
	}
	void InsertElem(const value_type& rhs)
	{
		pTree tmp = new Tree;
		pTree parent = nullptr;
		tmp->KeyName = rhs.first;
		tmp->Data.push_back(rhs.second);
		tmp->pLeft = nullptr;
		tmp->pRight = nullptr;
		tmp->pRoot = nullptr;
		tmp->ptr = nullptr;
		tmp->IndDat = 0;
		if (Root == nullptr)
		{
			Root = tmp;
			MasPtr.push_back(tmp);
		}
		else
		{
			pTree fr = FindElem(rhs);
			if (fr != nullptr)
			{
				fr->Data.push_back(rhs.second);
				delete tmp;
				return;
			}
			pTree p = Root;
			while (p)
			{
				parent = p;
				if (rhs.first < p->KeyName)
				{
					p = p->pLeft;
				}
				else
				{
					p = p->pRight;
				}
			}
			if (parent != nullptr) {
				if (rhs.first < parent->KeyName)
				{
					parent->pLeft = tmp;
					tmp->pRoot = parent;
				}
				else
				{
					parent->pRight = tmp;
					tmp->pRoot = parent;
				}
			}
			MasPtr.push_back(tmp);
		}
	}
	void Copy(pTree tmp)
	{
		if (tmp == nullptr)
			return;
		value_type rhs;
		for (int i = 0; i < tmp->Data.size(); i++)
		{
			rhs = std::make_pair(tmp->KeyName, tmp->Data[i]);
			InsertElem(rhs);
		}
		Copy(tmp->pLeft);
		Copy(tmp->pRight);
	}
	void PT(pTree rhs)
	{
		if (!rhs)
			return;
		PT(rhs->pLeft);

		for (auto it = rhs->Data.begin(); it != rhs->Data.end(); it++)
		{
		std:cout << "Key = " << rhs->KeyName << " => " << "Data = " << *it << '\n';
		}
		PT(rhs->pRight);
	}
	void Remove(const key_type& rhs)
	{
		bool found = false;
		if (Root == nullptr)
		{
			std::cout << " This Tree is empty! " << '\n';
			return;
		}
		pTree curr;
		pTree parent = nullptr;
		curr = Root;
		while (curr != nullptr)
		{
			if (curr->KeyName == rhs)
			{
				found = true;
				break;
			}
			else
			{
				parent = curr;
				if (rhs > curr->KeyName)
					curr = curr->pRight;
				else
					curr = curr->pLeft;
			}
		}
		if (!found)
		{
			std::cout << " Data not found! " << '\n';
			return;
		}
		for (int i = 0; i < MasPtr.size(); i++)
		{
			if (MasPtr[i]->KeyName == rhs)
			{
				auto it = MasPtr.begin() + i;
				MasPtr.erase(it);
				break;
			}
		}
		if ((curr->pLeft == nullptr && curr->pRight != nullptr) || (curr->pLeft != nullptr && curr->pRight == nullptr))
		{
			if (curr->pLeft == nullptr && curr->pRight != nullptr)
			{
				if (parent != nullptr)
				{
					if (parent->pLeft == curr)
					{
						parent->pLeft = curr->pRight;
						if (curr->ptr != nullptr)
							delete curr->ptr;
						delete curr;
					}
					else
					{
						parent->pRight = curr->pRight;
						if (curr->ptr != nullptr)
							delete curr->ptr;
						delete curr;
					}
				}
				else
				{
					Root = curr->pRight;
					if (curr->ptr != nullptr)
						delete curr->ptr;
					delete curr;
				}
			}
			else
			{
				if (parent != nullptr)
				{
					if (parent->pLeft == curr)
					{
						parent->pLeft = curr->pLeft;
						if (curr->ptr != nullptr)
							delete curr->ptr;
						delete curr;
					}
					else
					{
						parent->pRight = curr->pLeft;
						if (curr->ptr != nullptr)
							delete curr->ptr;
						delete curr;
					}
				}
				else
				{
					Root = curr->pLeft;
					if (curr->ptr != nullptr)
						delete curr->ptr;
					delete curr;
				}
			}
			return;
		}
		if (curr->pLeft == nullptr && curr->pRight == nullptr)
		{
			if (parent != nullptr)
			{
				if (parent->pLeft == curr)
					parent->pLeft = nullptr;
				else
					parent->pRight = nullptr;
			}
			if (curr->ptr != nullptr)
				delete curr->ptr;
			delete curr;
			return;
		}
		if (curr->pLeft != nullptr && curr->pRight != nullptr)
		{
			pTree chkr;
			chkr = curr->pRight;
			if ((chkr->pLeft == nullptr) && (chkr->pRight == nullptr))
			{
				curr = chkr;
				if (chkr->ptr != nullptr)
					delete chkr->ptr;
				delete chkr;
				curr->pRight = nullptr;
			}
			else
			{
				if ((curr->pRight)->pLeft != nullptr)
				{
					pTree lcurr;
					pTree lcurrp;
					lcurrp = curr->pRight;
					lcurr = (curr->pRight)->pLeft;
					while (lcurr->pLeft != nullptr)
					{
						lcurrp = lcurr;
						lcurr = lcurr->pLeft;
					}
					curr->KeyName = lcurr->KeyName;
					curr->Data = lcurr->Data;
					if (lcurr->ptr != nullptr)
						delete lcurr->ptr;
					delete lcurr;
					lcurrp->pLeft = nullptr;
				}
				else
				{
					pTree tmp;
					tmp = curr->pRight;
					curr->KeyName = tmp->KeyName;
					curr->Data = curr->Data;
					curr->pRight = tmp->pRight;
					if (tmp->ptr != nullptr)
						delete tmp->ptr;
					delete tmp;
				}
			}
			return;
		}
	}
	void DeleteTree()
	{
		while (!MasPtr.empty())
		{
			int ind = MasPtr.size() - 1;
			Remove(MasPtr[ind]->KeyName);
		}
	}

public:
	class MapIterator
	{
		iterator Value;
		vec_type Mas;
	public:
		MapIterator()
			:Value(nullptr)
		{}
		/*MapIterator(vec_type M, MapIterator&& it)
			:Mas(M),
			Value(it.Value) 
		{}*/
		~MapIterator() = default;
		MapIterator(vec_type M, pTree rhs)
			:Mas(M)
		{
			if (rhs != nullptr) {
				delete rhs->ptr;
				rhs->ptr = new value_type;
				rhs->ptr->first = rhs->KeyName;
				rhs->ptr->second = rhs->Data[rhs->IndDat];
				Value = rhs->ptr;
			}
			else
			{
				Value = nullptr;
			}
		}
		MapIterator(vec_type M, const MapIterator& it)
			:Mas(M),
			Value(it.Value) 
		{}
		MapIterator(vec_type M, pTree rhs, int Ind)
			:Mas(M),
		{
			if (rhs != nullptr)
			{
				rhs->IndDat = Ind;
				rhs->ptr = new value_type;
				rhs->ptr->first = rhs->KeyName;
				rhs->ptr->second = rhs->Data[rhs->IndDat];
				Value = rhs->ptr;
			}
			else
			{
				Value = nullptr;
			}

		}
		bool operator!=(const MapIterator& it)
		{
			return !(*this == it);
		}
		bool operator==(const MapIterator& it)
		{
			if (Value == nullptr)
			{
				if (it.Value == nullptr)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				if (it.Value == nullptr)
				{
					return false;
				}
				else
				{
					if (it.Value == Value)
						return true;
					else
						return false;
				}
			}
		}
		MapIterator& operator=(const MapIterator& it)
		{
			Mas = it.Mas;
			if (Value != nullptr)
			{
				int i = 0;
				for (i; i < Mas.size(); i++)
				{
					if (Value->first == Mas[i]->KeyName)
						break;
				}
				delete Mas[i]->ptr;
				Mas[i]->ptr = nullptr;
			}
			if (it.Value != nullptr)
			{
				Value = it.Value;
			}
			else
				Value = nullptr;
			return *this;
		}

		value_type& operator*()
		{
			return *Value;
		}

		iterator& operator->()
		{
			return Value;
		}

		MapIterator& operator++()
		{
			int IndKey = 0;
			for (IndKey; IndKey < Mas.size(); IndKey++)
			{
				if (Value->first == Mas[IndKey]->KeyName)
					break;
			}
			Mas[IndKey]->IndDat++;
			if (Mas[IndKey]->Data.size() <= Mas[IndKey]->IndDat)
			{
				Mas[IndKey]->IndDat--;
				IndKey++;
				if (Mas.size() <= IndKey)
				{
					Value = nullptr;
				}
				else
				{
					if (Value != nullptr)
						delete Mas[IndKey]->ptr;
					Mas[IndKey]->ptr = new value_type;
					Mas[IndKey]->ptr->first = Mas[IndKey]->KeyName;
					Mas[IndKey]->ptr->second = Mas[IndKey]->Data[Mas[IndKey]->IndDat];
					Value = Mas[IndKey]->ptr;
				}
			}
			else
			{
				if (Value != nullptr)
					delete Mas[IndKey]->ptr;
				Mas[IndKey]->ptr = new value_type;
				Mas[IndKey]->ptr->first = Mas[IndKey]->KeyName;
				Mas[IndKey]->ptr->second = Mas[IndKey]->Data[Mas[IndKey]->IndDat];
				Value = Mas[IndKey]->ptr;
			}
			return *this;
		}
		MapIterator& operator++(int)
		{
			int IndKey = 0;
			for (IndKey; IndKey < Mas.size(); IndKey++)
			{
				if (Value->first == Mas[IndKey]->KeyName)
					break;
			}
			Mas[IndKey]->IndDat++;
			if (Mas[IndKey]->Data.size() <= Mas[IndKey]->IndDat)
			{
				Mas[IndKey]->IndDat--;
				IndKey++;
				if (Mas.size() <= IndKey)
				{
					Value = nullptr;
				}
				else
				{
					if (Value != nullptr)
						delete Mas[IndKey]->ptr;
					Mas[IndKey]->ptr = new value_type;
					Mas[IndKey]->ptr->first = Mas[IndKey]->KeyName;
					Mas[IndKey]->ptr->second = Mas[IndKey]->Data[Mas[IndKey]->IndDat];
					Value = Mas[IndKey]->ptr;
				}
			}
			else
			{
				if (Value != nullptr)
					delete Mas[IndKey]->ptr;
				Mas[IndKey]->ptr = new value_type;
				Mas[IndKey]->ptr->first = Mas[IndKey]->KeyName;
				Mas[IndKey]->ptr->second = Mas[IndKey]->Data[Mas[IndKey]->IndDat];
				Value = Mas[IndKey]->ptr;
			}
			return *this;
		}
		MapIterator operator--()
		{
			if (Value != nullptr)
			{
				
				int IndKey = 0;
				for (IndKey; IndKey < Mas.size(); IndKey++)
				{
					if (Value->first == Mas[IndKey])
						break;
				}
				Mas[IndKey]->IndDat--;
				if (Mas[IndKey]->IndDat < 0)
				{
					Mas[IndKey]->IndDat = 0;
					IndKey--;
					if (IndKey < 0)
					{
						Value = nullptr;
					}
					else
					{
						if (Mas[IndKey]->ptr != nullptr)
							delete Mas[IndKey]->ptr;
						Mas[IndKey]->ptr = new value_type;
						Mas[IndKey]->ptr->first = Mas[IndKey]->KeyName;
						Mas[IndKey]->ptr->second = Mas[IndKey]->Data[Mas[IndKey]->IndDat];
						Value = Mas[IndKey]->ptr;
					}
				}
				else
				{
					if (Value != nullptr)
						delete Mas[IndKey]->ptr;
					Mas[IndKey]->ptr = new value_type;
					Mas[IndKey]->ptr->first = Mas[IndKey]->KeyName;
					Mas[IndKey]->ptr->second = Mas[IndKey]->Data[Mas[IndKey]->IndDat];
					Value = Mas[IndKey]->ptr;
				}
			}
			else
			{
				int ind = Mas.size() - 1;
				Mas[ind]->ptr = new value_type;
				Mas[ind]->ptr->first = Mas[ind]->KeyName;
				Mas[ind]->ptr->second = Mas[ind]->Data[Mas[ind]->IndDat];
				Value = Mas[ind]->ptr;
			}
			return *this;
		}
		MapIterator operator--(int)
		{
			if (Value != nullptr)
			{

				int IndKey = 0;
				for (IndKey; IndKey < Mas.size(); IndKey++)
				{
					if (Value->first == Mas[IndKey])
						break;
				}
				Mas[IndKey]->IndDat--;
				if (Mas[IndKey]->IndDat < 0)
				{
					Mas[IndKey]->IndDat = 0;
					IndKey--;
					if (IndKey < 0)
					{
						Value = nullptr;
					}
					else
					{
						if (Mas[IndKey]->ptr != nullptr)
							delete Mas[IndKey]->ptr;
						Mas[IndKey]->ptr = new value_type;
						Mas[IndKey]->ptr->first = Mas[IndKey]->KeyName;
						Mas[IndKey]->ptr->second = Mas[IndKey]->Data[Mas[IndKey]->IndDat];
						Value = Mas[IndKey]->ptr;
					}
				}
				else
				{
					if (Value != nullptr)
						delete Mas[IndKey]->ptr;
					Mas[IndKey]->ptr = new value_type;
					Mas[IndKey]->ptr->first = Mas[IndKey]->KeyName;
					Mas[IndKey]->ptr->second = Mas[IndKey]->Data[Mas[IndKey]->IndDat];
					Value = Mas[IndKey]->ptr;
				}
			}
			else
			{
				int ind = Mas.size() - 1;
				Mas[ind]->ptr = new value_type;
				Mas[ind]->ptr->first = Mas[ind]->KeyName;
				Mas[ind]->ptr->second = Mas[ind]->Data[Mas[ind]->IndDat];
				Value = Mas[ind]->ptr;
			}
			return *this;
		}
	};
public:
	// empty constructor
	TMultimap()
		:Root(),
		Count(0) {}
	// destructor
	~TMultimap()
	{
		DeleteTree();
	}
	//initializer constructor 
	TMultimap(const std::initializer_list<value_type> init)
	{
		for (auto &v : init)
		{
			InsertElem(v);
		}
		Count = init.size();
		Sort();
	}
	// iterator constructor
	TMultimap(MapIterator beg, MapIterator end)
	{
		int k = 0;
		for (beg; beg != end; beg++)
		{
			InsertElem(*beg);
			k++;
		}
		Count = k;
		Sort();
	}
	// copy constructor
	TMultimap(TMultimap& map)
	{
		Count = map.Count;
		Copy(map.Root);
		Sort();
	}

	// copy operator = 
	TMultimap& operator=(TMultimap& map)
	{
		if (Root != nullptr)
			DeleteTree();
		Copy(map.Root);
		Sort();
		Count = map.Count;
		return *this;
	}
	// initializer operator =
	TMultimap& operator=(std::initializer_list<value_type> init)
	{
		if (Root != nullptr)
			DeleteTree();
		for (auto &v : init)
		{
			InsertElem(v);
		}
		Count = init.size();
		Sort();
		return *this;
	}

	//function insert single parametr
	MapIterator insert(const value_type& rhs)
	{
		InsertElem(rhs);
		Count++;
		Sort();
		int i = 0;
		for (i; i < MasPtr.size(); i++)
		{
			if (MasPtr[i]->KeyName == rhs.first)
				break;
		}
		int j = 0;
		for (j; j < MasPtr[i]->Data.size(); j++)
		{
			if (MasPtr[i]->Data[j] == rhs.second)
				break;
		}
		MasPtr[i]->IndDat = j;
		MapIterator NewVal(MasPtr, MasPtr[i]);
		return NewVal;
	}

	//function Insert with pos iterator
	MapIterator insert(MapIterator It, const value_type& rhs)
	{
		InsertElem(rhs);
		Count++;
		Sort();
		int i = 0;
		for (i; i < MasPtr.size(); i++)
		{
			if (MasPtr[i]->KeyName == rhs.first)
				break;
		}
		int j = 0;
		for (j; j < MasPtr[i]->Data.size(); j++)
		{
			if (MasPtr[i]->Data[j] == rhs.second)
				break;
		}
		MasPtr[i]->IndDat = j;
		MapIterator NewVal(MasPtr[i]);
		return NewVal;
	}

	//function Insert initializer list
	MapIterator insert(std::initializer_list<value_type> init)
	{
		Count += init.size();
		for (auto &v : init)
		{
			InsertElem(v);
		}
		Sort();
		int ik = 0;
		int id = 0;
		auto it = init.end();
		it--;
		int i = 0;
		for (i; i < MasPtr.size(); i++)
		{
			if (MasPtr[i]->KeyName == it->first)
				break;
		}
		int j = 0;
		for (j; j < MasPtr[i]->Data.size(); j++)
		{
			if (MasPtr[i]->Data[j] == it->second)
				break;
		}
		MasPtr[i]->IndDat = j;
		MapIterator NewVal(MasPtr, MasPtr[i]);
		return NewVal;
	}

	//function Insert iterator's
	MapIterator insert(MapIterator beg, MapIterator en)
	{
		for (beg; beg != en; beg++)
		{
			InsertElem(*beg);
			Count++;
		}
		Sort();
		beg--;
		MapIterator NewVal(MasPtr, beg);
		return NewVal;
	}

	//function erasing by key
	void erase(const key_type& rhs)
	{
		for (int i = 0; i < MasPtr.size(); i++)
		{
			if (MasPtr[i]->KeyName == rhs)
			{
				Count -= MasPtr[i]->Data.size();
				break;
			}
		}
		Remove(rhs);
	}

	//function erasing by iterator
	void erase(MapIterator& it)
	{
		if (it == end())
			return;
		Count--;
		int i = 0;
		int j = 0;
		bool onelen = false;
		bool fl = false;
		for (i; i < MasPtr.size(); i++)
		{
			if (MasPtr[i]->KeyName == (*it).first)
			{
				j = 0;
				for (j; j < MasPtr[i]->Data.size(); j++)
				{
					if (MasPtr[i]->Data[j] == (*it).second)
					{
						MasPtr[i]->Data.erase(MasPtr[i]->Data.begin() + j);
						fl = true;
						if (MasPtr[i]->Data.size() == 0)
						{
							onelen = true;
						}
						break;
					}
				}
			}
			if (fl)
				break;
		}
		if (!onelen)
		{
			MasPtr[i]->IndDat = j - 1;
			MapIterator p(MasPtr, MasPtr[i]);
			it = p;
		}
		else
		{
			MapIterator r(MasPtr, MasPtr[i - 1]);
			it = r;
			Remove(MasPtr[i]->KeyName);
		}
	}

	// iterator begin
	MapIterator begin()
	{
		for (int i = 0; i < MasPtr.size(); i++)
		{
			MasPtr[i]->IndDat = 0;
		}
		MapIterator NewVal(MasPtr, MasPtr[0]);
		return NewVal;
	}

	//iterator end
	MapIterator end()
	{
		MapIterator NewVal(MasPtr, nullptr);
		return NewVal;
	}

	//function find
	MapIterator find(const key_type& rhs)
	{
		pTree el = FindKey(rhs);
		MapIterator p(MasPtr, el);
		return p;
	}

	//function Empty
	bool empty()
	{
		return (Count == 0);
	}

	//function size
	size_type size()
	{
		return Count;
	}

	//function print
	void Print()
	{
		PT(Root);
	}

	//function clear
	void clear()
	{
		DeleteTree();
		Count = 0;
	}

	//function Count
	size_t count(const key_type& rhs)
	{
		pTree tmp = FindKey(rhs);
		if (tmp == nullptr)
			return 0;
		else
			return tmp->Data.size();
	}

	//function swap
	void swap(TMultimap& map)
	{
		std::swap(MasPtr, map.MasPtr);
		std::swap(Count, map.Count);
		std::swap(Root, map.Root);
	}

	//function lower_bound
	MapIterator lower_bound(const key_type& rhs)
	{
		for (int k = 0; i < MasPtr.size(); i++)
		{
			MasPtr[i]->IndDat = 0;
		}
		int i = 0;
		for (i; i < MasPtr.size(); i++)
		{
			if (MasPtr[i]->KeyName == rhs)
				break;
		}
		if (i == MasPtr.size())
		{
			MapIterator NewVal(MasPtr, nullptr);
		}
		MapIterator p(MasPtr, MasPtr[i], 0);
		return p;
	}

	//function upper_bound
	MapIterator upper_bound(const key_type& rhs)
	{
		int i = 0;
		for (i; i < MasPtr.size(); i++)
		{
			if (MasPtr[i]->KeyName == rhs)
				break;
		}
		if (i == MasPtr.size())
		{
			MapIterator NewVal(MasPtr, nullptr);
		}
		MapIterator p(MasPtr, MasPtr[i], MasPtr[i]->Data.size() - 1);
		p++;
		return p;
	}

	//function equal_range
	std::pair<MapIterator, MapIterator> equal_range(const key_type& rhs)
	{
		MapIterator lp = Lower_bound(rhs);
		MapIterator up = Upper_bound(rhs);
		std::pair<MapIterator, MapIterator> NewVal = std::make_pair(lp, up);
		return NewVal;
	}
};
