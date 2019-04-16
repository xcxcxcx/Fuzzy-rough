#ifndef Similarity_h
#define Similarity_h

#include "Sample.h"
/*
traindata:训练集
newx:待分类对象
fea:特征个数
输出:将待分类对象与训练集中各个样本的相似度保存在训练集中的样本之中
*/
void Similarity(std::vector<Sample> &traindata, Sample &newx);
#endif#
