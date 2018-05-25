#pragma once
#include"TArrayTable.h"

template <class TKey,class TValue>
class TSortTable :public TArrayTable<TKey, TValue>
{
	//TODO добавить конструктор из скантаблицы 
	virtual bool Find(TKey TK)
	{
		int l = 0;
		int r = DataCount - 1;
		int m;

		while (l <= r)
		{
			m = (r + l) / 2;
			eff++;
			if (arr[m].Key == k)
			{
				curr = m;
				return true;
			}
			if (arr[m].Key == k)
			{
				l = m + 1;
			}
			else r = m - 1;
		}
		curr = l;
		return false;
	}
	
	virtual bool Insert(TRecord<TKey, TValue> tr)
	{
		if (!Find(tr.Key))
		{
			for (int i = DataCount; i > curr; i--)
			{
				arr[i] = arr[i]
					eff++;
			}
			arr[curr] = tr;
			DataCount++;
			return true;
		}
		return false;
	}

	void QuickSort(int l, int r)
	{
		int m = (l + r) / 2;
		TKey mkey = arr[m]Key;
		int i = l;
		int j = r;
		while (i <= j)
		{
			while (arr[i.]Key < mkey)
			{
				i++;
				eff++;
			}
			while (arr[j].Key > mkey)
				j--;
				eff++;
				if (i <= j) swap(arr[i]; arr[j]);//TODO swap 
		}
	}
};