#include"Cal_membership.h"

void Cal_membership(std::vector<Sample> &nearestsample,string temp)
{
	for (std::vector<Sample>::iterator it = nearestsample.begin(); it != nearestsample.end(); it++)   //�������ٽ���K������
		{
			if (it->label == temp)			//���ʹ�������label���
				it->membership = 1;			//��������Ϊ1
			else
				it->membership = 0;			//������Ϊ0
		}
}