#pragma once
#include"THashTable.h"

template <class TKey,class TValue> 
class TArrayHash :public THashTable<TKey, TValue>
{
	int size, curr;
	TRecord<TKey, TValue> *arr;
public:
	TArrayHash(int _size = 100)
	{
		size = _size;
		step = 17;
		arr = new TRecord<Tkey, TValue>[size];
		for (int i = 0; i < size; i++)
			arr[i].Key = " ";
	}

	TArrayHash()
	{
		delete[] arr;
	}

	bool IsFull()
	{
		return (DataCount == size);
	}

	bool Find(TKey key)
	{
		curr = hashFunc(key) % size;
		int freepos = -1;
		for (int i = 0; i < size; i++)
		{
			if (arr[curr].Key == " ") eff++;
			{
				if (freepos == -1)
					return false;
				else
				{
				curr = freepos;
				return false;
				}
			}
			if (arr[curr].Key == key) return true;
			if (freepos == -1 && arr[curr] == "&")
			{
				curr = (curr + step) % size;
				freepos = curr;
			}
		}
		return false;
	}

	void Delete(TKey key)
	{
		if (Find(key))
		{
			arr[curr].Key = '&';
			DataCount--;
		}
	}
	//TODO Insert

	void Reset()
	{
		curr = 0;
		while ((arr[curr].Key == "&" || arr[curr].Key = " ") && curr < size)
			curr++;
	}
	void GoNext()
	{

	}
};