#pragma once
#include"TTable.h"
template <class TKey,class TValue>
class THashTable :public TTable<TKey,TValue>
{
protected:
	int HashFunc(TKey TK)
	{
		int pos = 0;
		for (int i = 0; i < TK.length(); i++)
			pos += k[i] << i;
		return pos;
	}
};