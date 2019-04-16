
#include <iostream>
#include <time.h> 
#include <fstream> 
#include"Get_col.h"
#include"Load_data.h"
#include"Frnn.h"
#include"File_search.h"
#include<windows.h>
using namespace std;


int main()
{
	int kfold = 10;                                      //ͬ����Kֵ��һ���ظ�����kfold��
	
	string maxval;                                        //��������ܵ�label
	int col = 0;											//�������
	std::vector<string> fileIn;								//����ļ����µ��ļ�
	string path = "";			//�ļ���·��
	File_search(path, fileIn);								//���ļ��µ��ļ�ȫ�������fileIn��
	string store = "";		//���ʵ����

	for(int i = 0; i < fileIn.size(); i++)  // ѭ�������ļ��µ����ݼ�
	{ 
		string absolute_path = path + fileIn[i];   //��ĳ�����ݼ��ĵ�ַ
		string store_path = store + fileIn[i];   //��ŵ�ĳ�����ݼ��ĵ�ַ
		//cout << absolute_path << " "<< store_path << endl;
		col = Get_col(absolute_path.c_str());
		int fea = col - 1;

		for (int k = 1; k < 41; k++)
		{
			clock_t start, finish;
			start = clock();
			double accurarytmp = 0;                               //�洢ƽ����ȷ��
			for (int fold = 0; fold < kfold; fold++)
			{
				std::vector<Sample> traindata, testdata;
				Load_data(traindata, testdata, absolute_path.c_str(), fold);      //װ������
				//cout << fold << endl;
				double matched = 0;                                //�������ɹ�������
				double accurary = 0;								//���浥�γɹ���
				int num = testdata.size();
				for (int i = 0; i < num; i++)
				{
					Frnn(testdata[i], traindata, maxval, k);			//�õ��������Ե�label

					testdata[i].result = maxval;						//���������Ե�label��ֵ��result
				//	cout << "the pre is " << maxval << " and the label is " << testdata[i].label << endl;
					if (testdata[i].label == testdata[i].result)		//���result�ͱ�����labelһ������ô����ɹ�
						matched += 1;									//����ɹ����� +1
					//std::cout << "the real is  " << testdata[i].label << " " << "the pre is  " << testdata[i].result << endl;
				}
				accurary = matched / num;									//�ɹ�����/��ǰ��������������= ����ɹ���
				//cout << "--------------------------------------------" << endl;
				//cout << "present is " << fold << endl;
				//cout << "the accurary is " << accurary << endl;
			//	Sleep(500);
				accurarytmp += accurary;									//��kfold�εĳɹ��ʼ�����
				//cout << "the temp is" << accurarytmp << endl;

				//cout << "the trainsize is" << traindata.size() << endl;
				//cout << "the testsize is" << testdata.size() << endl;
				//cout << "--------------------------------------------" << endl;
			}
			accurarytmp = accurarytmp / kfold;								//����ٳ���fold��  ����ƽ���ɹ���
			std::cout << "the totalaccurary is " << accurarytmp << endl;	//��ӡ����
			finish = clock();
			double time = finish - start;
			ofstream outFile;

			outFile.open(store_path, ios::out | ios::app);					//�򿪴洢λ���ļ�
			outFile << k << "," << accurarytmp <<","<<"time"<< "," << time<< endl;						//��kֵ�ͷ���ɹ��ĸ���д��

			outFile.close();												//�ر��ļ�

		}


	}

	return 0;
}