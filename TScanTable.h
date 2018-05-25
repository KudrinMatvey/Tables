#pragma once
#include"TArrayTable.h"

template<class TKey,class TValue>
class TScanTable :public TArrayTable<TKey, TValue>
{
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
			DataCount--;
		}
	}
};