//计算fuzzy rough的上近似
#include"Upper_approximations.h"
#include <algorithm>
#include<iostream>

void Upper_approximations(Sample &newx, std::vector<Sample> &nearestsample, int k)
{
	std::vector<double> t_norm(k);

	for (int i = 0; i < k; i++)
	{
		//计算t蕴含算子，t(x,y) = min(x,y)
		t_norm[i] = min(nearestsample[i].similarity, nearestsample[i].membership);
		/*cout << "T算子:" ;
		cout << "min(" << nearestsample[i].similarity << "," << nearestsample[i].membership << ")=" << t_norm[i] << endl;*/
	}
		//取计算后的上确界
		double max = t_norm[0];
		for (int i = 0; i < k; i++)
		{
			if (t_norm[i] >= max)
			{
				max = t_norm[i];
			}
		}
		/*cout << "上近似" << max << endl;*/
		//赋值给待分类对象的上近似
		newx.Upper_approximations = max;
	
}