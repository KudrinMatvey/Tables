#pragma once
#include"TArrayTable.h"

template<class TKey,class TValue>
class TScanTable :public TArrayTable<TKey, TValue>
{public:
	TScanTable(int _size = 1) : TArrayTable<TKey, TValue>(_size) {}
	virtual bool Find(TKey l)
	{
		for (int i = 0; i < DataCount; i++)
		{
			if (arr[i].Key == l)
			{
				curr = i;
				return true;
			}
			eff++;
		}
	curr = DataCount;
	return false;
	}
	
	virtual bool Insert(TRecord<TKey, TValue> tr)
	{
		if(!IsFull())
			if (!Find(tr.Key))
			{
				arr[curr] = tr;
				DataCount++;
				return true;
			}
		return false;
	}

	virtual void Delete(TKey tk)
	{
		if (Find(tk))
		{
			arr[curr] = arr[DataCount - 1];
			eff++;
			DataCount--;
		}
	}
	bool IsFull()
	{
		return size == DataCount;
	}
	void SetCurrVal(TValue TV)
	{
	}
};