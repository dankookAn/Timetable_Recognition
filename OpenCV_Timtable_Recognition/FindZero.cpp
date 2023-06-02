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


    cout << "가능한 시간대" << endl;
    for (const auto& index : zero) {
        int firstValue = index.first;
        int secondValue = index.second;
        string ableDay, ableTime;

        if (secondValue == 0) { ableDay = "월요일"; }
        else if (secondValue == 1) { ableDay = "화요일"; }
        else if (secondValue == 2) { ableDay = "수요일"; }
        else if (secondValue == 3) { ableDay = "목요일"; }
        else { ableDay = "금요일"; }

        if (firstValue == 0) { ableTime = "9시"; }
        else if (firstValue == 1) { ableTime = "9시 30분"; }
        else if (firstValue == 2) { ableTime = "10시"; }
        else if (firstValue == 3) { ableTime = "10시 30분"; }
        else if (firstValue == 4) { ableTime = "11시"; }
        else if (firstValue == 5) { ableTime = "11시 30분"; }
        else if (firstValue == 6) { ableTime = "12시"; }
        else if (firstValue == 7) { ableTime = "12시 30분"; }
        else if (firstValue == 8) { ableTime = "13시"; }
        else if (firstValue == 9) { ableTime = "13시 30분"; }
        else if (firstValue == 10) { ableTime = "14시"; }
        else if (firstValue == 11) { ableTime = "14시 30분"; }
        else if (firstValue == 12) { ableTime = "15시"; }
        else if (firstValue == 13) { ableTime = "15시 30분"; }
        else if (firstValue == 14) { ableTime = "16시"; }
        else if (firstValue == 15) { ableTime = "16시 30분"; }
        else if (firstValue == 16) { ableTime = "17시"; }
        else if (firstValue == 17) { ableTime = "17시 30분"; }
        else if (firstValue == 18) { ableTime = "18시"; }
        else if (firstValue == 19) { ableTime = "18시 30분"; }
        else if (firstValue == 20) { ableTime = "19시"; }
        else if (firstValue == 21) { ableTime = "19시 30분"; }
        else { ableTime = "20시 이후"; }
        cout << "(" << ableDay << ", " << ableTime << ")" << endl;
    }

}
