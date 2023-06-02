#pragma once
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

class Timetable {
public:
    Timetable() {};
    Timetable(string path); //이미지 경로를 입력받는 생성자
    void getContours(Mat imgThresh, Mat img);   //실제 시간표 박스를 인식
    void getBoxSize(Mat img);   //시간표 한칸의 사이즈 인식
    void getDay(Point tl);      //인식된 시간표박스의 요일인식
    void getTime(Point tl, int height);     //인식된 시간표박스의 시간인식
    void setTable(int day, int credit, int time);   //인식된 시간표를 표로 출력


private:
    int day;
    int credit;
    int time;
    int daySize;
    int timeSize;
    Point getDayStartpoint;
    Point getTimeStartpoint;
    int array[22][5] = {};
    
};