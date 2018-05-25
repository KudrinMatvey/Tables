#pragma once
#include"THashTable.h"

template <class TKey,TValue> 
class TArrayHash :public THashTable<TKey, TValue>
{
public:
	TArrayHash(int _size = 100)
	{
		size = _size;
		step = 17;
		arr = new TRecord<Tkey, TValue>[size];

	}
};