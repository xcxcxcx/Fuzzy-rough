#ifndef Sample_h
#define Sample_h

#include<vector>
#include<string>
#include<map>
using namespace std;

class Sample
{
public:
	// 数据集对象信息
	std::vector<double> X;//特征，条件属性  vectCondAttrs
	string label;//类别，决策属性  strOrignalDecAttr

	double similarity;//相似度  
	double membership;//隶属度
	double lower_approximations;//下近似
	double upper_approximations;//上近似
	string result; //分类结果，训练后的决策属性  strPredictDecAttr
};

#endif
