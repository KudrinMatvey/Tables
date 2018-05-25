#pragma once


template <class TKey,class TValue>
struct TRecord
{
	TKey Key;
	TValue Value;
};

template <Class TKey, class TValue>
class TTable
{
protected:
	int DataCount;//количество данных
	int eff;//эффективность

public:
	TTable() { int DataCount = 0, eff = 0; }
	
	bool IsEmpty{ return(!DataCount); }
	virtual bool IsFull() = 0;
	virtual bool Find(TKey TK) = 0;
	virtual bool Insert(TRecord<Tkey, TValue>) = 0;
	virtual void Delete(TKey TK) = 0;
	virtual void GoNext() = 0;
	virtual bool IsEnd() = 0;
	virtual void Reset() = 0;
	virtual TRecord<TKey, TValue> GetCurr() = 0;
	virtual void SetCurrVal(TValue TV) = 0;


	void Print()
	{
		TRecord<TKey, Tvalue> tmp;
		for(Reset();!IsEnd();GoNext)
		{
			tmp = GetCurr();
			cout << tmp.Value << endl;
		}
	}
};

