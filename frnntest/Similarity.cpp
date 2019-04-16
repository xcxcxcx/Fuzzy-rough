#include"Similarity.h"
#include<iostream>
using namespace std;

void Similarity(std::vector<Sample> &traindata,Sample &newx)
{
	int m = traindata.size();
	int n = traindata[0].X.size();
	std::vector<double> molecular(n);   //保存R计算公式中分数的分子
	std::vector<double> denominator(n);   //保存R计算公式中分数的分母
	std::vector<double> singlesimilarty(n);   //保存单个属性的相似度
	std::vector<double> vecMaxAttrs(n);  //保存所有属性的最大值
	std::vector<double> vecMinAttrs(n);   //保存所有属性的最小值

	for (int i = 0; i < m; i++)			// 遍历训练集,行数据，对象
	{
		for (int j = 0; j < n; j++)		// 遍历训练集,列数据，属性
		{
			if(i == 0)
				vecMinAttrs[j] = vecMaxAttrs[j] = traindata[0].X[j];  // 使用第一行数据作为最大最小的初始值
			else if (traindata[i].X[j] >= vecMaxAttrs[j])
				vecMaxAttrs[j] = traindata[i].X[j];		//将整个训练集中，每列属性最大值存在vecMaxAttrs[]当中
			else if (traindata[i].X[j] <= vecMinAttrs[j])
				vecMinAttrs[j] = traindata[i].X[j];		//将整个训练集中，每列属性最小值存在vecMinAttrs[]当中
		}
	}

	for (int i = 0; i < m; i++)
	{
		// 计算单个属性的相似度
		for (int j = 0; j < n; j++)
		{
			// 当前测试对象的属性值与vecMaxAttrs[j]和vecMinAttrs[j]进行比较，修正R计算公式
			if (newx.X[j] > vecMaxAttrs[j])
				vecMaxAttrs[j] = newx.X[j];
			else if(newx.X[j] < vecMinAttrs[j])
				vecMinAttrs[j] = newx.X[j];
			
			molecular[j] = fabs(newx.X[j] - traindata[i].X[j]);         //求待分类对象和训练集对象的相同属性相减的绝对值
			denominator[j] = fabs(vecMaxAttrs[j] - vecMinAttrs[j]);		//属性最大值和属性最小值的差
			if (denominator[j] == 0)
				singlesimilarty[j] = 1;  
			else
			{
				singlesimilarty[j] = 1 - (molecular[j] / denominator[j]);	//求某个属性的相似度
			}
			
		}																//公式：Ra(x,y) = 1 - (|a(x) - a(y)| / (|a_max - a_min|))

		//计算整体相似度：所有单个属性相似度中最小相似度
		double dMinSim = singlesimilarty[0];
		for (int i = 0; i < n; i++)
		{
			/*std::cout<<i<<" 属性 " << singlesimilarty[i] << endl;*/
			if (singlesimilarty[i] <= dMinSim)
			{
				dMinSim = singlesimilarty[i];
			}
		}
		traindata[i].Similarity = dMinSim;								//将属性相似度最小的赋值给样本相似度
		/*cout << "the Similarity value is" << min << endl;;*/
	}
}