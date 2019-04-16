//����fuzzy rough���Ͻ���
#include"Upper_approximations.h"
#include <algorithm>
#include<iostream>

void Upper_approximations(Sample &newx, std::vector<Sample> &nearestsample, int k)
{
	std::vector<double> t_norm(k);

	for (int i = 0; i < k; i++)
	{
		//����t�̺����ӣ�t(x,y) = min(x,y)
		t_norm[i] = min(nearestsample[i].similarity, nearestsample[i].membership);
		/*cout << "T����:" ;
		cout << "min(" << nearestsample[i].similarity << "," << nearestsample[i].membership << ")=" << t_norm[i] << endl;*/
	}
		//ȡ��������ȷ��
		double max = t_norm[0];
		for (int i = 0; i < k; i++)
		{
			if (t_norm[i] >= max)
			{
				max = t_norm[i];
			}
		}
		/*cout << "�Ͻ���" << max << endl;*/
		//��ֵ�������������Ͻ���
		newx.Upper_approximations = max;
	
}