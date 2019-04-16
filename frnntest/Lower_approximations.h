﻿#ifndef Lower_approximations_h
#define Lower_approximations_h

#include "Sample.h"

/*
newx：待分类对象
nearestsample：k个近邻训练集
k：近邻样本的个数
输出：计算出当前样本的下近似
*/

void Lower_approximations(Sample &newx, std::vector<Sample> &nearestsample, int k);

#endif#
