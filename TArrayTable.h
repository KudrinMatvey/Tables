#pragma once
#include"TTable.h"
template <class TKey,class TValue>
class TArrayTable :public TTable<TKey, TValue>
{
protected:
	TRecord<Tkey, TValue> *arr;
	int size, curr;

	TArrayTable(int _size = 100)
	{
		size = _size;
		arr = new TRecord<TKey, TValye>[size];
	}
	~TArrayTable() { delete[] arr; }
	//TODO констр коп оп присв

	GetCurr(int cn)
	{
		return(arr[cn]);
	}

	void Reset() { curr = 0; }
	void GoNext() { curr++; }
	bool IsEnd() { return (curr == DataCount); }
};