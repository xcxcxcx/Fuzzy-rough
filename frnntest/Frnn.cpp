#include"Frnn.h"
#include"Get_Label.h"
#include"Similarity.h"
#include"Cal_membership.h"
#include"Lower_approximations.h"
#include"Upper_approximations.h"
#include"Sample.h"
#include"Cmp.h"
#include"Split.h"
#include <iostream>
#include <algorithm>
#include <time.h> 

void Frnn(Sample &newx, std::vector<Sample> &traindata, string &maxval, int k)
{
	
	std::map<string, int> label_class;
	

	//label集合
	Get_Label(traindata, label_class);
	//计算相似度
	Similarity(traindata,newx);

	//按相似度排序
	sort(traindata.begin(), traindata.end(), Cmp);

	// kNN: 将前K个最相似样本存进vector<Sample> nearestsample	
	std::vector<Sample> nearestsample(k);
	for (int p = 0; p < k; p++)
	{
		nearestsample[p] = traindata[p];         
	}


	/*std::vector<double> l_norm(k);*/
	/*std::vector<double> t_norm(k);*/
	double T = 0;
	double pre;
	string temp;
	for (map<string, int>::iterator i = label_class.begin(); i != label_class.end(); i++)
	//	for (map<string, int>::reverse_iterator i = label_class.rbegin(); i != label_class.rend(); i++)
	{
		//将当前label赋值给temp
		temp = i->first;   
		//cout << "label is" << temp << endl;
		//计算隶属度
		Cal_membership(nearestsample, temp);

		//下近似
		Lower_approximations(newx, nearestsample, k);
		/*cout << "the lower is " << newx.lower_approximations << endl;*/

		//上近似
		Upper_approximations(newx, nearestsample, k);
		/*cout << "the upper is " << newx.upper_approximations << endl;*/
		//计算上下近似平均值
		pre = (newx.Lower_approximations + newx.Upper_approximations) / 2;
		/*cout << "the average value is ：" << pre << endl;*/
		if (pre >= T)
		{
			T = pre;
			maxval = i->first;
		//	cout << "the present label is " << maxval << endl;
		}
	}
}