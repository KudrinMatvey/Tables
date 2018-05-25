#pragma once
#include"TTable.h"
template <class TKey,class TValue>
class TArrayTable :public TTable<TKey, TValue>
{
protected:
	TRecord<TKey, TValue> *arr;
	int size, curr;

	TArrayTable(int _size = 100)
	{
		size = _size;
		arr = new TRecord<TKey, TValue>[size];
	}
	
	TArrayTable(TArrayTable<TKey,TValue> &ta)
	{
		size = ta.Size;
		arr = new TRecord<TKey, TValue>[size];
	}

	TArrayTable<TKey, TValue> operator = (const TArrayTable<TKey, TValue> &ta) {};

	~TArrayTable() { delete[] arr; }

	//TODO ������ ��� �� �����

	TRecord<TKey,TValue> GetCurr()
	{
		return(arr[curr]);
	}

	void Reset() { curr = 0; }
	void GoNext() { curr++; }
	bool IsEnd() { return (curr == DataCount); }
};