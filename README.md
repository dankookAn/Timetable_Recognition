# Timetable_Recognition
 **-프로젝트 배경-**
  + 대학생들이 스터디나, 팀플 과제를 진행할때 처음단계로 시간을 조율하게됩니다.
보통 이렇게 자신의 시간표 사진을 올리면서 시간을 정하는경우가 많은데 인원이 적으면 다른 사람 시간표와 비교해가며 시간을조율할수있지만 
사람이 많아진다면 일일히 비교하기도 힘들어지고 그렇다고 모든 사람의 시간표를 텍스트로 입력해서 확인하자니 상당히 번거러운 작업이 됩니다.
그래서 저는 이러한 어려움을 해소시켜주고자 시간표 이미지만 입력하면 여러사람의 공통으로 비어있는 시간대를 알려주는 프로그램을 개발하게되었습니다.


 **-시스템 구조 및 설계-**
 + 사용자가 시간표를 입력하면 openCV를 통해 시간표를 데이터화 시켜줍니다.
이후 이 데이터들을 모아 시간조회 알고리즘을 통해 사용자에게 공통적으로 비어있는 시간대를 출력해줍니다.


**-중심이 되는 알고리즘-**
+ 데이터화 알고리즘
  + 기본적으로 시간표는 사각형 형태의 박스가 배치되어있기 때문에  opencv가 사각형을 인식하여 이 사각형의 좌표를
구하게 됩고, 해당 좌표가 어디에 위치해 있냐에 따라서 요일과 시간이 구해지게 됩니다.
예를 들어 여기 목요일 문화철학 같은 과목의 x좌표가 '230~270'면 목요일이고 y좌표가 '20~40'사이면 9시 수업 이런식으로
작동하게됩니다 그런데 이때 시간과 요일을 분리해주는 기준 좌표가 고정이면 사용자가 입력한 이미지의 크기가 다 다를경우, 값이 제대로 안구해 질수있습니다.
```c++
void Timetable::getContours(Mat imgThresh, Mat img) {
   
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgThresh, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    
    for (int i = 0; i < contours.size(); i++) {

        int area = contourArea(contours[i]);
        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
        

        if (area > 5000 && area < 50000) {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);          
            boundRect[i] = boundingRect(conPoly[i]);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 0, 255), 2);

            getDay(boundRect[i].tl());
            getTime(boundRect[i].tl(), boundRect[i].height);
  
            setTable(day, credit, time);
        }
    }
}

```


+ 시간조회 알고리즘
  + 이미지가 제대로 인식되었는지 사용자가 확인하기 쉽도록 2차원 배열로 출력시켜줍니다
  30분단위로 끝나는 수업도 있기 때문에 위아래 두칸이 1시간 간격이고 왼쪽부터 월요일, 화요일 이런식으로 진행됩니다.
비어있는 시간은0 채워져있는 시간은 1로 표시하게 했습니다.
이렇게 여러개의 2차원 배열을 3차원 벡터에 대입해주고 3중 for문으로 공통적으로 0의 값을 찾아 인덱스를 반환하게 됩니다.

```c++
vector<pair<int, int>> FindZero::findZero(vector<vector<vector<int>>>& arrays) {
    vector<pair<int, int>> zeroIndex;
    int numHei = arrays.size();
    int numRows = arrays[0].size();
    int numCols = arrays[0][0].size();
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
```
