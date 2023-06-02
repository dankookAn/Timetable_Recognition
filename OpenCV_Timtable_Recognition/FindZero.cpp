#include"FindZero.h"


bool FindZero::allZeros(const std::vector<int>& vec) {

    for (const auto& element : vec) {
        if (element != 0) {
            return false;
        }
    }
    return true;
}

vector<pair<int, int>> FindZero::findZero(vector<vector<vector<int>>>& arrays) {
    vector<pair<int, int>> zeroIndex;
    int numHei = arrays.size();
    int numRows = arrays[0].size();
    int numCols = arrays[0][0].size();

    //cout << numRows << numCols << numHei << endl;
    vector<int> vec;



    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            for (const auto& temp : arrays) {
                vec.push_back(temp[i][j]);
            }
            bool a = allZeros(vec);
            if (a) { zeroIndex.push_back(make_pair(i, j)); }
            vec.clear();

        }
    }

    return zeroIndex;

}


void FindZero::transDay(vector<pair<int, int>> zero) {


    cout << "������ �ð���" << endl;
    for (const auto& index : zero) {
        int firstValue = index.first;
        int secondValue = index.second;
        string ableDay, ableTime;

        if (secondValue == 0) { ableDay = "������"; }
        else if (secondValue == 1) { ableDay = "ȭ����"; }
        else if (secondValue == 2) { ableDay = "������"; }
        else if (secondValue == 3) { ableDay = "�����"; }
        else { ableDay = "�ݿ���"; }

        if (firstValue == 0) { ableTime = "9��"; }
        else if (firstValue == 1) { ableTime = "9�� 30��"; }
        else if (firstValue == 2) { ableTime = "10��"; }
        else if (firstValue == 3) { ableTime = "10�� 30��"; }
        else if (firstValue == 4) { ableTime = "11��"; }
        else if (firstValue == 5) { ableTime = "11�� 30��"; }
        else if (firstValue == 6) { ableTime = "12��"; }
        else if (firstValue == 7) { ableTime = "12�� 30��"; }
        else if (firstValue == 8) { ableTime = "13��"; }
        else if (firstValue == 9) { ableTime = "13�� 30��"; }
        else if (firstValue == 10) { ableTime = "14��"; }
        else if (firstValue == 11) { ableTime = "14�� 30��"; }
        else if (firstValue == 12) { ableTime = "15��"; }
        else if (firstValue == 13) { ableTime = "15�� 30��"; }
        else if (firstValue == 14) { ableTime = "16��"; }
        else if (firstValue == 15) { ableTime = "16�� 30��"; }
        else if (firstValue == 16) { ableTime = "17��"; }
        else if (firstValue == 17) { ableTime = "17�� 30��"; }
        else if (firstValue == 18) { ableTime = "18��"; }
        else if (firstValue == 19) { ableTime = "18�� 30��"; }
        else if (firstValue == 20) { ableTime = "19��"; }
        else if (firstValue == 21) { ableTime = "19�� 30��"; }
        else { ableTime = "20�� ����"; }
        cout << "(" << ableDay << ", " << ableTime << ")" << endl;
    }

}
