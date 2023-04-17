//
// Created by 86150 on 2023/3/24.
//

#include "Point.h"
#include <iostream>
using namespace std;
int val = 315;
int Point::count = 0;	//使用类名初始化静态数据成员

Point::Point(const Point &p) : x(p.x), y(p.y) {	//复制构造函数体
    count++;
}

void Point::showCount() {
    cout << "  Object count = " << count << endl;
}
