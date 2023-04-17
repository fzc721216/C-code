//
// Created by 86150 on 2023/3/24.
//

#ifndef UNTITLED1_POINT_H
#define UNTITLED1_POINT_H


class Point {	//类的定义
public:	//外部接口
    Point(int x = 0, int y = 0) : x(x), y(y)  { count++; }
    Point(const Point &p);
    ~Point() { count--; }
    int getX() const { return x; }
    int getY() const { return y; }
    static void showCount();	//静态函数成员
private:	//私有数据成员
    int x, y;
    static int count;	//静态数据成员
};
inline int test(){
    return 315;
}

#endif //UNTITLED1_POINT_H
