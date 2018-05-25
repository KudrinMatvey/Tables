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
	TTreeTable<int, int> treetab;
	TSortTable<int, int> sorttab(count);
	TScanTable<int, int> scantab(count);
	TArrayHash<char*, char*> hashtab(count);

	ifstream ifs("TableInfo.txt");
}