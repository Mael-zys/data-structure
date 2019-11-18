#include <iostream>
#include "ELFHash.h"
#include "Compare.h"
#include <string.h>
#include <vector>
#include <stdio.h>

using namespace std;

#define KEY_LENGTH 200
#define HASH_M2 50

std::vector<std::string> vec;

int ELFHash2(char* key){
	unsigned long h = 0;
	while (*key){
		h = (h<<4) + *key++;
		unsigned long g = h & 0xF0000000L;
		if (g) h ^= g >> 24;
		h &= ~g;
	}
	return h % HASH_M2;
}

int DoubleHashingProbe(unsigned int hashTab[], char keyTab[][KEY_LENGTH], char* key)
{
	int h, h_org = h = ELFHash2(key);
	int h2 = (ELFHash(key)-3) % HASH_M2;
	int i;
	char* k;
	if (!hashTab[h]){
		//cout << "HOME at Hash (" << key << ") = " << h << "  FREE" << endl;
		k = key; i = 0;
		while (*key) keyTab[h][i++] = *key++;
		keyTab[h][i] = '\0';
		hashTab[h] = h+1;
		return h;
	}

	if (CharsCompare::eq(keyTab[h], key)){
		//cout << "Key [" << key << "] encountered again at slot " << h << endl;
		//判断这个key是否已经插入到向量集
		std::vector<std::string>::iterator temp=vec.begin();
        for(;temp!=vec.end();temp++)
        {
            if(*temp==key) return h;
        }
		vec.push_back(key);
		return h;
	}
	//cout << "HOME at Hash (" << key << ") = " << h << "  OCCUPIED => PROBE : " ;
	while (true){
		h += h2; h %= HASH_M2;
		//cout << "[" << h << "] ";
		if (!hashTab[h]){
			//cout << "FREE SLOT PROBED" << endl;
			k = key; i = 0;
			while (*key) keyTab[h][i++] = *key++;
			keyTab[h][i] = '\0';
			hashTab[h] = h+1;
			return h;
		}
		else if (CharsCompare::eq(keyTab[h], key)){
			//cout << "Key [" << key << "] encountered again at slot " << h << endl;
			//判断key是否插入向量集
			std::vector<std::string>::iterator temp1=vec.begin();
            for(;temp1!=vec.end();temp1++)
            {
                 if(*temp1==key) return h;
            }
			vec.push_back(key);
			return h;
		}
		else if (h==h_org){
			//cout << "NO FREE SLOT ANY MORE!" << endl;
			break;
		}
	}

	return 0;
}

int main(){
	char key[KEY_LENGTH];
	char keyTab[HASH_M2][KEY_LENGTH];
    static unsigned int hashTab[HASH_M2];
	int n,i,j,k,l;
	char DNA[KEY_LENGTH];
	cin>>k;
	getchar();
	for(l=0;l<k;l++)
    {
        cin.getline(key,KEY_LENGTH);
        //建立长度为10的substring，并进行哈希查询
        n=strlen(key)-9;
		for(i=0;i<n;i++)
        {
            for(j=0;j<10;j++)
            {
                DNA[j]=key[i+j];
            }
            DNA[i+10]='\0';
            DoubleHashingProbe(hashTab, keyTab, DNA);
        }
        //输出
        cout<<"[";
        if(vec.empty()!=1)//判断是否为空
        {
        std::vector<std::string>::iterator iter=vec.begin();
        cout<<*iter;
        iter++;
        for(;iter!=vec.end();iter++)  cout<<","<<*iter;
        }
        cout<<"]"<<endl;
        vec.clear();//清空这个向量集
        //初始化两个表格
        memset(keyTab,'\0',sizeof(keyTab));
        memset(hashTab,0,sizeof(hashTab));
        //hashTab[HASH_M2]={0};
    }
	return 0;
}





