#pragma once
#include <iostream>
#include <vector>
using namespace std;



class FindZero {
public:
	bool allZeros(const std::vector<int>& vec);	//�Ѻ����� ���Ұ� ��� 0�̸� true
	vector<pair<int, int>> findZero(vector<vector<vector<int>>>& arrays);	//3������ ���Ϳ��� ���������� 0�� ���� ���� �ε���
	void transDay(vector<pair<int, int>> zero);	//¦������ ���͸� ���ϰ� �ð����� ����
};