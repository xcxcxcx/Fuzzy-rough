#ifndef File_search_h
#define File_search_h
#include<vector>
#include<string>
using namespace std;

/*
path：文件夹路径
fileIn：用来保存当前文件夹中的数据集
输出：将当前文件夹中的数据集保存在fileIn中
*/

void File_search(string path, std::vector<string> &fileIn);

#endif#