#include <string.h>
#include "Compare.h"
#include "InternalSorting.h"
using namespace std;

template <class Elem>
void printA(Elem A[], int n){
	for(int i=0; i<n; i++)
		cout << A[i] << " ";
	cout << "\n";
}

int main()
{

#ifdef DIRECT_CONST_CHARS_CONVERSION
	// A double-quotes pair marked string terminates with '\0' by default
	char *a_char[] = {"machine", "intelligence", "system", "automation", "program", "technique", "computer", "data"};
	int n_char = 8;
#else
	// A double-quotes pair marked string terminates with '\0' by default

	const char *c_char[] = {"HuangShang" , "ZhangWuJi", "HongQiGong", "HuangYaoShi", "SaoDiSeng", "WuYaZi",
	"GuoJing", "YangGuo", "RenWoXing", "ChongXuDaoZhang", "XieXun", "LingHuChong", "FangZhengDaShi", "DuGuQiuBai", "DuanYu",
	"QiaoFeng"};
	char *a_char[50];
	int n_char = 16;
	for (int i=0; i<n_char; i++){
		a_char[i] = new char(100);
		strcpy(a_char[i], c_char[i]);
	}
#endif

    cout << "A set of strings: "; printA(a_char, n_char);
	QuickSort<char*,CharsCompare>(a_char, 0, n_char-1);
	cout << "After QuickSort: "; printA(a_char, n_char);

	return 0;
}

