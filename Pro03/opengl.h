#ifndef __OPENGL__
#define __OPENGL__

class Point

请输入顶点数：



{
public:
    Point(){}
    double getX() const
    {
        return this->__x;
    }
    void setX(double x)
    {
        this->x = x;
    }

    double getY() const
    {
        return this->__Y;
    }
    void setY(double Y)
    {
        this->y = y;
    }

private:
    double __x;
    double __y;
}


#endif