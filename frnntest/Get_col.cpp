#include"Get_col.h"
#include<iostream>
#include<stdlib.h>
using namespace std;

int Get_col(const char *filename)
{
	char a[10000];
	FILE *file = fopen(filename, "r");       //���ļ�
	if (!file)
	{
		cout << "�Ҳ���ָ�����ļ�" << endl;
		return -1;
	}

	fgets(a, 10000, file);
	int col = 0;
	for (int i = 0; i<10000; i++)
	{
		if (a[i] == ',')					//��������
		{
			col += 1;						//����+1
		}
		if (a[i] == NULL)					//��Ϊ�գ����ǵ���һ�е�ĩβ������=���ŵĸ���+1��
		{
			col += 1;						//����+1
			break;							//����ѭ��
		}
	}
	return col;								//��������
}