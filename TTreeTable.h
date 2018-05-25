#pragma once
#include"Stack.h"
#include"TTable.h"
#define NULL 0 
template <class TKey,class TValue>
struct TNode
{
	int bal;
	TRecord<TKey, TValue> record;
	TNode *pLeft, *pRight;
};

template <class TKey, class TValue>
class TTreeTable:public TTable <TKey, TValue>
{
protected:
	TNode<TKey, TValue> *pRoot;
	TNode<TKey, TValue> *pCurr;
	TStack<TNode<TKey, TValue>*> st;
	TNode <TKey, TValue> **pRes;
	int pos;
public:
	TTreeTable()
	{
		pRoot = pCurr = NULL;
	}
	bool Find(TKey key)
	{
		pRes = &pRoot;
		while (pRes != NULL)
		{
			eff++;
			if ((*pRes)->record.Key == key)
				return true;
			if ((*pRes)->record.Key < key)
				pRes = &(*pRes)->pRight;
			else
				pRes = &(*pRes)->pLeft;
		}
		return false;
	}

	bool Insert(TRecord<TKey,TValue> rec)
	{
		if (!Find(rec.Key)) {
			*pRes = new TNode<TKey, TValue>();
			(*pRes)->record = rec;
			DataCount++;
			return true;
		}
		//else (*pRes)->record.periodicity++;
		return false;
	}

	void Delete(TKey _key) {
		if (!Find(_key)) return;
		TNode<TKey, TValue> *tmp = *pRes;
		if (!tmp->pLeft)
			*pRes = tmp->pRight;
		else if (!tmp->pRight)
			*pRes = tmp->pLeft;

		else {
			TNode<TKey, TValue> *find = tmp->pLeft;
			TNode<TKey, TValue> **iter;
			iter = &(*pRes)->pLeft;
			while (find->pRight) {
				eff++;
				iter = &(*iter)->pRight;
				find = find->pRight;
			}
			tmp->record = find->record;
			tmp = find;
			*iter = find->pLeft;
		}
		DataCount--;
		delete tmp;
	}

	virtual void clear() {
		if (!DataCount) return;
		TStack<TNode<TKey, TValue>*> st;
		st.clear();
		for (Reset(); !IsEnd(); GoNext())
			st.push(pCurr);
		while (!st.isEmpty())
			delete st.pop();
		DataCount = 0;
//		eff = 0;
		pCurr = pRoot = nullptr;
	}
	void Reset()
	{
		st.clear();
		pCurr = pRoot;
		pos = 0;
		while (pCurr->pLeft != NULL)
		{
			st.push(pCurr);
			pCurr = pCurr->pLeft;
		}
		st.push(pCurr);
	}
	void GoNext()
	{
		st.pop();
		pos++;
		if (pCurr->pRight != NULL)
		{
			pCurr = pCurr->pRight;
			while (pCurr->pLeft != NULL)
			{
				st.push(pCurr);
				pCurr = pCurr->pLeft;
			}
			st.push(pCurr);
		}
		else if (!st.isEmpty())
			pCurr = st.top();
	}
	bool IsEnd()
	{
		return (pos == DataCount);
	}

	bool IsFull()  {
		return false;
	}

	TRecord<TKey, TValue> GetCurr() { return pCurr->record; };
	void SetCurrVal(TValue TV) { pCurr->record.Value = TV; }
	void IncrCurrVal(){pCurr->record.Value++; }

};