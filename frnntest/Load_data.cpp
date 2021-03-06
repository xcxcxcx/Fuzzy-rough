#include"Load_data.h"
#include"split.h"
#include<time.h>
#include<fstream>
#include<iostream>


void Load_data(std::vector<Sample> &traindata, std::vector<Sample> &testdata, const char *filename, int fold)
{
	srand((unsigned)time(NULL));
	int row = 0;
	Sample sample;
	string pattern = ",";
	fstream fin(filename);
	bool isInited = false;
	char* readline = (char*)malloc(2000);
	while (!fin.eof())
	{
		//一行一行读数据
		fin.getline(readline, 2000, '\n');
		string a = readline;
		//	cout << readline << endl;;
		//将一行数据按逗号分隔符分割成几块，存储在vector<string> splited中
		vector<string> splited = split(a, pattern); 
		//判断是不是空行，如果是空行则跳过本次循环
		if (splited.size() == 0) continue;
		//调整samle的大小，以适应不同的samle.X个数
		if (sample.X.size() != splited.size() - 1)
		{
			int size = splited.size() - 1 - sample.X.size();		//若分割的条件属性大于sample.X的个数
			if (size>0)
			{
				for (int i = 0; i<abs(size); i++)
					sample.X.push_back(0);							//将sample.X个数增多
			}
			else
			{
				for (int i = 0; i<abs(size); i++)
					sample.X.pop_back();							//将sample.X个数减少
			}
		}

		//这个循环出过的问题,当result.size()==0的时候。就会去访问samle.X[-1]所以说就翻车车了
		for (unsigned int i = 0; i<(splited.size() - 1); i++)
		{
			sample.X[i] = atof(splited[i].c_str());
			//	cout << sample.X[i] << endl;
		}
		//取label
		sample.label = *(splited.end() - 1);
	
		if (row % 10 == fold)
			//将数据中的某个对象根据fold进行判断放入测试集
			testdata.push_back(sample);
		else
			traindata.push_back(sample);
		row++;

		//int randnum = rand() % 9 + 1;
		//if (randnum == 9)
		//	//将一行的数据放入trainDatas
		//	testdata.push_back(sample);
		//else
		//	traindata.push_back(sample);
		//	cout << "sample.X的长度：" << sample.X.size() << "  " << sample.label << endl;
	}
	free(readline);
}