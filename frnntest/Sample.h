#ifndef Sample_h
#define Sample_h

#include<vector>
#include<string>
#include<map>
using namespace std;

class Sample
{
public:
	// ���ݼ�������Ϣ
	std::vector<double> X;//��������������  vectCondAttrs
	string label;//��𣬾�������  strOrignalDecAttr

	double similarity;//���ƶ�  
	double membership;//������
	double lower_approximations;//�½���
	double upper_approximations;//�Ͻ���
	string result; //��������ѵ����ľ�������  strPredictDecAttr
};

#endif
