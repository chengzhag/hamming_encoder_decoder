#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

#define charTrue '1'
#define charFalse '0'

void hammingEncode(string& input, string& output)
{
	output.clear();
	vector<int> verifyIndexes;
	vector<int> dataIndexes;

	//����У��λ����
	int dataLength = input.size();
	int verifyLength = 0;
	while (dataLength + verifyLength + 1 > pow(2, verifyLength))
	{
		verifyLength++;
	}
	int outputLength = verifyLength + dataLength;

	//����У��λ���
	int verifyIndex = 0;
	while (verifyIndex < outputLength)
	{
		verifyIndexes.push_back(verifyIndex);
		verifyIndex = (verifyIndex + 1) * 2 - 1;
	}

	//��������λ���
	int dataIndex = 2;
	int dataIndexSearch = 0;
	while (dataIndex < outputLength)
	{
		while (verifyIndexes[dataIndexSearch] < dataIndex && dataIndexSearch < verifyIndexes.size() - 1)
		{
			dataIndexSearch++;
		}
		if (verifyIndexes[dataIndexSearch] != dataIndex)
		{
			dataIndexes.push_back(dataIndex);
		}
		dataIndex++;
	}

	////��ʾУ�������λλ��
	//for (int i = 0; i < verifyIndexes.size(); i++)
	//{
	//	cout << verifyIndexes[i] << '\t';
	//}
	//cout << endl;
	//for (int i = 0; i < dataIndexes.size(); i++)
	//{
	//	cout << dataIndexes[i] << '\t';
	//}
	//cout << endl;

	//����У��λ���λ
	vector<vector<int> > relaVerifyIndexes;
	for (int i = 0 ; i < dataLength; i++)
	{
		vector<int> relaVerifyIndex;
		int dataIndex = dataIndexes[i] + 1;
		//������λ���2�����������
		int dividedPow = 0;
		while (pow(2, dividedPow) < dataIndex)
		{
			dividedPow++;
		}
		dividedPow -= 1;
		dividedPow = pow(2, dividedPow);
		relaVerifyIndex.push_back(dividedPow - 1);
		dataIndex -= dividedPow;
		while (dataIndex > 0)
		{
			while (dataIndex - dividedPow < 0)
			{
				dividedPow = dividedPow / 2;
			}
			dataIndex -= dividedPow;
			relaVerifyIndex.push_back(dividedPow - 1);
		}
		relaVerifyIndexes.push_back(relaVerifyIndex);
	}

	//��data-verify��ϵת��Ϊbool����
	//��ʼ��bool����
	vector<vector<bool> > relaDataVerify;//Data-�У�Verify-��
	vector<bool> colVerifyFalse;//Verify���ȵ�false����
	for (int j = 0; j < verifyLength; j++)
	{
		colVerifyFalse.push_back(false);
	}
	for (int i = 0; i < dataLength; i++)
	{
		relaDataVerify.push_back(colVerifyFalse);
	}
	//����true
	for (int i = 0; i < relaVerifyIndexes.size(); i++)
	{
		for (int j = 0; j < relaVerifyIndexes[i].size(); j++)
		{
			for (int k = 0; k < verifyIndexes.size(); k++)
			{
				if (relaVerifyIndexes[i][j] == verifyIndexes[k])
				{
					relaDataVerify[i][k] = true;
				}
			}
			//cout << relaVerifyIndexes[i][j] << '\t';
		}
		//cout << endl;
	}

	////��ʾ��������
	//cout << endl;
	//for (int i = 0; i < dataLength; i++)
	//{
	//	for (int j = 0; j < verifyLength; j++)
	//	{
	//		cout << relaDataVerify[i][j] << '\t';
	//	}
	//	cout << endl;
	//}

	//���
	dataIndex = 0;
	verifyIndex = 0;
	for (int i = 0; i < outputLength; i++)
	{
		if (dataIndexes[dataIndex] == i)
		{
			output.push_back(input[dataIndex]);
			dataIndex++;
		}
		else if (verifyIndexes[verifyIndex] == i)
		{
			vector<bool> relaDataBit;
			for (int j = 0; j < dataLength; j++)
			{
				if (relaDataVerify[j][verifyIndex] == true)
				{
					if (input[j] == '1')
					{
						relaDataBit.push_back(true);
					}
					else
					{
						relaDataBit.push_back(false);
					}
				}
			}
			bool verifyBit = relaDataBit[0];
			for (int i = 1; i < relaDataBit.size(); i++)
			{
				verifyBit ^= relaDataBit[i];
			}
			if (verifyBit)
			{
				output.push_back('1');
			}
			else
			{
				output.push_back('0');
			}
			verifyIndex++;
		}
	}

	//cout << output << endl;
}

void hammingDecode(string& input, string& output)
{
	output.clear();
	vector<int> verifyIndexes;
	vector<int> dataIndexes;

	//����У��λ����
	int inputLength = input.size();
	int verifyLength = ceil(log(inputLength+1)/log(2));
	int dataLength = inputLength - verifyLength;

	//����У��λ���
	int verifyIndex = 0;
	while (verifyIndex < inputLength)
	{
		verifyIndexes.push_back(verifyIndex);
		verifyIndex = (verifyIndex + 1) * 2 - 1;
	}

	//��������λ���
	int dataIndex = 2;
	int dataIndexSearch = 0;
	while (dataIndex < inputLength)
	{
		while (verifyIndexes[dataIndexSearch] < dataIndex && dataIndexSearch < verifyIndexes.size() - 1)
		{
			dataIndexSearch++;
		}
		if (verifyIndexes[dataIndexSearch] != dataIndex)
		{
			dataIndexes.push_back(dataIndex);
		}
		dataIndex++;
	}

	////��ʾУ�������λλ��
	//for (int i = 0; i < verifyIndexes.size(); i++)
	//{
	//	cout << verifyIndexes[i] << '\t';
	//}
	//cout << endl;
	//for (int i = 0; i < dataIndexes.size(); i++)
	//{
	//	cout << dataIndexes[i] << '\t';
	//}
	//cout << endl;

	//����У��λ���λ
	vector<vector<int> > relaVerifyIndexes;
	for (int i = 0; i < dataLength; i++)
	{
		vector<int> relaVerifyIndex;
		int dataIndex = dataIndexes[i] + 1;
		//������λ���2�����������
		int dividedPow = 0;
		while (pow(2, dividedPow) < dataIndex)
		{
			dividedPow++;
		}
		dividedPow -= 1;
		dividedPow = pow(2, dividedPow);
		relaVerifyIndex.push_back(dividedPow - 1);
		dataIndex -= dividedPow;
		while (dataIndex > 0)
		{
			while (dataIndex - dividedPow < 0)
			{
				dividedPow = dividedPow / 2;
			}
			dataIndex -= dividedPow;
			relaVerifyIndex.push_back(dividedPow - 1);
		}
		relaVerifyIndexes.push_back(relaVerifyIndex);
	}

	//��data-verify��ϵת��Ϊbool����
	//��ʼ��bool����
	vector<vector<bool> > relaDataVerify;//Data-�У�Verify-��
	vector<bool> colVerifyFalse;//Verify���ȵ�false����
	for (int j = 0; j < verifyLength; j++)
	{
		colVerifyFalse.push_back(false);
	}
	for (int i = 0; i < dataLength; i++)
	{
		relaDataVerify.push_back(colVerifyFalse);
	}
	//����true
	for (int i = 0; i < relaVerifyIndexes.size(); i++)
	{
		for (int j = 0; j < relaVerifyIndexes[i].size(); j++)
		{
			for (int k = 0; k < verifyIndexes.size(); k++)
			{
				if (relaVerifyIndexes[i][j] == verifyIndexes[k])
				{
					relaDataVerify[i][k] = true;
				}
			}
			//cout << relaVerifyIndexes[i][j] << '\t';
		}
		//cout << endl;
	}

	//�������λ
	int errorIndex = 0;
	for (int i = 0; i < verifyLength; i++)
	{
		vector<bool> relaDataBit;
		for (int j = 0; j < dataLength; j++)
		{
			if (relaDataVerify[j][i] == true)
			{
				if (input[dataIndexes[j]] == '1')
				{
					relaDataBit.push_back(true);
				}
				else
				{
					relaDataBit.push_back(false);
				}
			}
		}
		bool verifyBit;
		if (input[verifyIndexes[i]]=='1')
		{
			verifyBit = true;
		}
		else
		{
			verifyBit = false;
		}
		for (int i = 0; i < relaDataBit.size(); i++)
		{
			verifyBit ^= relaDataBit[i];
		}
		if (verifyBit)
		{
			errorIndex+= verifyIndexes[i]+1;
		}
	}
	errorIndex--;
	if (errorIndex >= 0)
	{
		if (input[errorIndex] == '1')
		{
			input[errorIndex]='0';
		}
		else
		{
			input[errorIndex] = '1';
		}
	}

	for (int i = 0; i < dataLength; i++)
	{
		output.push_back(input[dataIndexes[i]]);
	}
	//cout << errorIndex << endl;
}

int main()
{
	/*string encoderInput("1001000");
	string encoderOutput;
	cout << "��������У�" << encoderInput << endl;
	hammingEncode(encoderInput, encoderOutput);
	cout << "���������У�" << encoderOutput << endl;

	for (int i = 0; i < encoderOutput.size(); i++)
	{
		string decoderInput(encoderOutput);
		if (decoderInput[i] == '1')
		{
			decoderInput[i] = '0';
		}
		else
		{
			decoderInput[i] = '1';
		}
		cout << "����һλ������У�" << decoderInput << endl;
		string decoderOutput;
		hammingDecode(decoderInput, decoderOutput);
		cout << "������������У�" << decoderOutput << endl;
	}*/

	////���������
	//string encoderInput;
	//ifstream  inFile;
	//ofstream outFile;
	//inFile.open("������01��.txt");
	//if (!inFile)
	//{
	//	cerr << "��'������01��.txt'�ļ�����" << endl;
	//	return 1;
	//}
	//outFile.open("������01����+�������룩.txt");
	//if (!outFile)
	//{
	//	cerr << "��'������01����+�������룩.txt'�ļ�����" << endl;
	//	return 1;
	//}
	//while (!inFile.eof())
	//{
	//	if (inFile >> encoderInput)
	//	{
	//		string encoderOutput;
	//		hammingEncode(encoderInput, encoderOutput);
	//		outFile << encoderOutput<<endl;
	//	}
	//}


	//����������
	string encoderInput;
	ifstream  inFile;
	ofstream outFile;
	inFile.open("���գ�01����+�������룩.txt");
	if (!inFile)
	{
		cerr << "��'���գ�01����+�������룩.txt'�ļ�����" << endl;
		return 1;
	}
	outFile.open("���գ�01��.txt");
	if (!outFile)
	{
		cerr << "������'���գ�01��.txt'�ļ�����" << endl;
		return 1;
	}
	while (!inFile.eof())
	{
		if (inFile >> encoderInput)
		{
			string encoderOutput;
			hammingDecode(encoderInput, encoderOutput);
			outFile << encoderOutput << endl;
		}
	}



	return 0;
}
