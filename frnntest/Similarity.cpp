#include"Similarity.h"
#include<iostream>
using namespace std;

void Similarity(std::vector<Sample> &traindata,Sample &newx)
{
	int m = traindata.size();
	int n = traindata[0].X.size();
	std::vector<double> molecular(n);   //����R���㹫ʽ�з����ķ���
	std::vector<double> denominator(n);   //����R���㹫ʽ�з����ķ�ĸ
	std::vector<double> singlesimilarty(n);   //���浥�����Ե����ƶ�
	std::vector<double> vecMaxAttrs(n);  //�����������Ե����ֵ
	std::vector<double> vecMinAttrs(n);   //�����������Ե���Сֵ

	for (int i = 0; i < m; i++)			// ����ѵ����,�����ݣ�����
	{
		for (int j = 0; j < n; j++)		// ����ѵ����,�����ݣ�����
		{
			if(i == 0)
				vecMinAttrs[j] = vecMaxAttrs[j] = traindata[0].X[j];  // ʹ�õ�һ��������Ϊ�����С�ĳ�ʼֵ
			else if (traindata[i].X[j] >= vecMaxAttrs[j])
				vecMaxAttrs[j] = traindata[i].X[j];		//������ѵ�����У�ÿ���������ֵ����vecMaxAttrs[]����
			else if (traindata[i].X[j] <= vecMinAttrs[j])
				vecMinAttrs[j] = traindata[i].X[j];		//������ѵ�����У�ÿ��������Сֵ����vecMinAttrs[]����
		}
	}

	for (int i = 0; i < m; i++)
	{
		// ���㵥�����Ե����ƶ�
		for (int j = 0; j < n; j++)
		{
			// ��ǰ���Զ��������ֵ��vecMaxAttrs[j]��vecMinAttrs[j]���бȽϣ�����R���㹫ʽ
			if (newx.X[j] > vecMaxAttrs[j])
				vecMaxAttrs[j] = newx.X[j];
			else if(newx.X[j] < vecMinAttrs[j])
				vecMinAttrs[j] = newx.X[j];
			
			molecular[j] = fabs(newx.X[j] - traindata[i].X[j]);         //�����������ѵ�����������ͬ��������ľ���ֵ
			denominator[j] = fabs(vecMaxAttrs[j] - vecMinAttrs[j]);		//�������ֵ��������Сֵ�Ĳ�
			if (denominator[j] == 0)
				singlesimilarty[j] = 1;  
			else
			{
				singlesimilarty[j] = 1 - (molecular[j] / denominator[j]);	//��ĳ�����Ե����ƶ�
			}
			
		}																//��ʽ��Ra(x,y) = 1 - (|a(x) - a(y)| / (|a_max - a_min|))

		//�����������ƶȣ����е����������ƶ�����С���ƶ�
		double dMinSim = singlesimilarty[0];
		for (int i = 0; i < n; i++)
		{
			/*std::cout<<i<<" ���� " << singlesimilarty[i] << endl;*/
			if (singlesimilarty[i] <= dMinSim)
			{
				dMinSim = singlesimilarty[i];
			}
		}
		traindata[i].Similarity = dMinSim;								//���������ƶ���С�ĸ�ֵ���������ƶ�
		/*cout << "the Similarity value is" << min << endl;;*/
	}
}