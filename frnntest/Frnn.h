#ifndef Frnn_h
#define Frnn_h

#include "Sample.h"

/*
newx��������Ķ���
traindata��ѵ����
maxval�������洢�����������������Է���
fea������ֵ
k�����ڸ���
��������������Է��ౣ����maxval��
*/

void Frnn(Sample &newx, std::vector<Sample> &traindata, string &maxval, int k);

#endif#