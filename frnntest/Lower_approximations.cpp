//����fuzzy rough���½���
#include<time.h>
#include"Lower_approximations.h"
#include <algorithm>
#include<iostream>

void Lower_approximations(Sample &newx, std::vector<Sample> &nearestsample,int k)
{
	std::vector<double> l_norm(k);
	
	for (int i = 0; i < k; i++)
	{
		//����l�̺����ӣ�l(x,y) = max(1-x,y)
		l_norm[i] = max(1 - nearestsample[i].similarity, nearestsample[i].membership);//
	/*	cout << "l����:" ;
		cout << "max(1-" << nearestsample[i].similarity << "," << nearestsample[i].membership << ")=" << l_norm[i] << endl;*/
	}
	
	
		//ȡ��������ȷ��
		double min = l_norm[0];
		for (int i = 0; i < k; i++)
		{
			if (l_norm[i] <= min)
			{
				min = l_norm[i];
			}
		}
		/*cout << "�½���" << min << endl;*/
		//��ֵ�������������½���
		newx.Lower_approximations = min;
	
}