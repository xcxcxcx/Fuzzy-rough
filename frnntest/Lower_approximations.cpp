//计算fuzzy rough的下近似
#include<time.h>
#include"Lower_approximations.h"
#include <algorithm>
#include<iostream>

void Lower_approximations(Sample &newx, std::vector<Sample> &nearestsample,int k)
{
	std::vector<double> l_norm(k);
	
	for (int i = 0; i < k; i++)
	{
		//计算l蕴含算子，l(x,y) = max(1-x,y)
		l_norm[i] = max(1 - nearestsample[i].similarity, nearestsample[i].membership);//
	/*	cout << "l算子:" ;
		cout << "max(1-" << nearestsample[i].similarity << "," << nearestsample[i].membership << ")=" << l_norm[i] << endl;*/
	}
	
	
		//取计算后的下确界
		double min = l_norm[0];
		for (int i = 0; i < k; i++)
		{
			if (l_norm[i] <= min)
			{
				min = l_norm[i];
			}
		}
		/*cout << "下近似" << min << endl;*/
		//赋值给待分类对象的下近似
		newx.Lower_approximations = min;
	
}