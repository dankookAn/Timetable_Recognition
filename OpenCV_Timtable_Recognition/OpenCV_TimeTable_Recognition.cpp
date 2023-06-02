#include "OpenCV_TimeTable_Recognition.h"
#include "FindZero.h"
#include <stdio.h>
vector<vector<vector<int>>> arrays;

Timetable::Timetable(string path) {
    Mat img = imread(path);
    Mat imgGray, imgThresh;
    resize(img, img, Size(), 0.5, 0.5);
    getBoxSize(img);
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    threshold(imgGray, imgThresh, 50, 255, THRESH_OTSU);
    getContours(imgThresh, img);
    imshow("img", img);

    for (int row = 0; row < 22; ++row) {
        for (int col = 0; col < 5; ++col) {
            cout << array[row][col];
        }
        cout << endl;
    }

    vector<vector<int>> vecArray;
    for (int i = 0; i < 22; i++) {
        vecArray.push_back(std::vector<int>(array[i], array[i] + 5));
    }
    arrays.push_back(vecArray);
}

void Timetable::getBoxSize(Mat img) {
    Mat imgDil,imgCanny;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(2, 2));
    Canny(img, imgCanny, 25, 75);
    
    dilate(imgCanny, imgDil, kernel);
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
    findContours(imgDil, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
    //drawContours(img, contours, -1, Scalar(255, 0, 255), 2);
    for (int i = 0; i < contours.size(); i++) {
        int area = contourArea(contours[i]);
        vector<vector<Point>> conPoly(contours.size());
        vector<Rect> boundRect(contours.size());
        if (area < 5000&&area>1000) {
            
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            boundRect[i] = boundingRect(conPoly[i]);
            if ((boundRect[i].x < 30 && boundRect[i].y < 80) || (boundRect[i].x < 80 && boundRect[i].y < 30)) {
                if (boundRect[i].x < 30 && boundRect[i].y < 80) {
                    timeSize = boundRect[i].height/2;
                    getTimeStartpoint = boundRect[i].tl();
                }
                else {
                    daySize = boundRect[i].width;
                    getDayStartpoint = boundRect[i].tl();
                }
                    
               
            }
        }
    }
}

void Timetable::setTable(int day, int credit, int time) {
    
    for (int i = time; i < time + credit; i++) {
        array[i][day] = { 1 };
    }
}



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

void Timetable::getDay(Point tl) {
    if (getDayStartpoint.x == 0) {
        getDayStartpoint.x = 32;
        daySize = 100;
    }

    int dayStartpoint = getDayStartpoint.x + (daySize / 2);
 
    if (tl.x < dayStartpoint) { day = 0; }
    else if (tl.x < dayStartpoint + daySize) { day = 1; }
    else if (tl.x < dayStartpoint + (daySize * 2)) { day = 2; }
    else if (tl.x < dayStartpoint + (daySize * 3)) { day = 3; }
    else { day = 4; }
}

void Timetable::getTime(Point tl, int height) {
    if (getTimeStartpoint.y == 0) {
        getTimeStartpoint.y = 32;
        timeSize = 105;
    }

    if (height < (timeSize+2)*2) {credit = 2;}
    else if (height < (timeSize + 2) * 3) { credit = 3; }
    else if (height < (timeSize + 2) * 4) { credit = 4; }
    else if (height < (timeSize + 2) * 5) { credit = 5; }
    else { credit = 6; }
    
    int dayTimeStartpoint = getTimeStartpoint.y + (timeSize / 2);
    int i = 1;
    time = 0;
    while (tl.y > dayTimeStartpoint) {
        time = i;
        i++;
        dayTimeStartpoint = dayTimeStartpoint + (timeSize+1);
    }

}


int main()
{
    int numObjects = 0;
    string path;
    cout << "Enter the number of timetable : ";
    cin >> numObjects;
    vector<Timetable> objects;
    objects.reserve(numObjects);  
    vector<Mat> images;
    images.reserve(numObjects);
    for (int i = 1; i <= numObjects; i++) {
        cout << "Enter path (ex :Resources/timetable1.jpg) : ";
        cin >> path;
        objects.emplace_back(path);
        waitKey(0);
    }
    destroyAllWindows();

    FindZero f;
    vector<pair<int, int>> zero = f.findZero(arrays);
    f.transDay(zero);

    system("pause");
    return 0;
}