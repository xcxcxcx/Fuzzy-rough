#ifndef Load_data_h
#define Load_data_h

#include "Sample.h"

/*
traindata：训练集
testdata：测试集
filepath：数据集的绝对路径
fold：选取第几为测试集
输出：将数据集分为训练集和测试集
*/

void Load_data(std::vector<Sample> &traindata, std::vector<Sample> &testdata, const char *filepath, int fold);

#endif#
