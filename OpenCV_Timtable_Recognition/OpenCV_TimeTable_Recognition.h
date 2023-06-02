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
    Timetable(string path); //�̹��� ��θ� �Է¹޴� ������
    void getContours(Mat imgThresh, Mat img);   //���� �ð�ǥ �ڽ��� �ν�
    void getBoxSize(Mat img);   //�ð�ǥ ��ĭ�� ������ �ν�
    void getDay(Point tl);      //�νĵ� �ð�ǥ�ڽ��� �����ν�
    void getTime(Point tl, int height);     //�νĵ� �ð�ǥ�ڽ��� �ð��ν�
    void setTable(int day, int credit, int time);   //�νĵ� �ð�ǥ�� ǥ�� ���


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