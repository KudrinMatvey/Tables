#include<string.h>
#include<string>
#include"TArrayTable.h"
#include"TScanTable.h"
#include"TSortTable.h"
//#include"TTable.h"
#include"TArrayHash.h"
#include"TTreeTable.h"
#include <fstream>

int main()
{
	int count = 1000;
	char buffer[50];
	TTreeTable<char*, int> treetab;
	TSortTable<char*, int> sorttab(count);
	TScanTable<char*, int> scantab(count);
	TArrayHash<char*, int> hashtab(count);
	char* randomStr(int size);

	//ifstream ifs("TableInfo.txt");
	char* str;
	str = "Hello it is me";
	TRecord<char*, int> tr1;
	tr1.Key = str;
	tr1.Value = 1;

	if (!sorttab.Insert(tr1))
		sorttab.SetCurrVal(2);
	if (!sorttab.Insert(tr1))
		sorttab.IncrCurrVal();
	

	if (!scantab.Insert(tr1))
		scantab.IncrCurrVal();
	if (!scantab.Insert(tr1))
		scantab.IncrCurrVal();
	int k = scantab.GetCurr().Value;

	if (!hashtab.Insert(tr1))
		hashtab.IncrCurrVal();
	if (!hashtab.Insert(tr1))
		hashtab.IncrCurrVal();
	hashtab.Find(str);
	int i = hashtab.GetCurr().Value;

	//if (!treetab.Insert(tr1))
	//	treetab.IncrCurrVal();
	//if (!treetab.Insert(tr1))
	//	treetab.IncrCurrVal();
	//int z = treetab.GetCurr().Value;
	const int masSize = 5;
	char* arr[masSize];
	TRecord<char*, int> randTr[masSize];


	for (int i = 0; i < masSize; i++)
	{
		arr[i] = randomStr(5);

		randTr[i].Key = arr[i];
		randTr[i].Value = 1;
		
		if (!sorttab.Insert(randTr[i]))
			sorttab.IncrCurrVal();

		if (!scantab.Insert(randTr[i]))
			scantab.IncrCurrVal();

		if (!hashtab.Insert(randTr[i]))
			hashtab.IncrCurrVal();

	}
	return 0;

}
char* randomStr(int size = 5)
{
	char *tmp;
	tmp = new char[size];
	for (int i = 0; i < size; i++)
		tmp[i] = (char)(rand() % 26 + 'a');
	return tmp;
}