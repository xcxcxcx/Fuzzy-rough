#ifndef Split_h
#define Split_h

#include "Sample.h"

/*
str:将要分割的字符串
pattern:按pattern类型分割，比如","
输出:将str按pattern分割之后保存在vector中返回
*/
std::vector<string> Split(string str, string pattern);

#endif#
