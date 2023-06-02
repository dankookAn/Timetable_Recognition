#pragma once
#include <iostream>
#include <vector>
using namespace std;



class FindZero {
public:
	bool allZeros(const std::vector<int>& vec);	//한벡터의 원소가 모두 0이면 true
	vector<pair<int, int>> findZero(vector<vector<vector<int>>>& arrays);	//3차원의 벡터에서 공통적으로 0의 값을 같는 인덱스
	void transDay(vector<pair<int, int>> zero);	//짝지어진 벡터를 요일과 시간으로 변경
};