#include<iostream>
#include<string>
#include<cmath>

struct Point 
{

    double x;
    double y;

};

void move_by(Point* p, double dx, double dy)
{

    p -> x += dx;   
    p -> y += dy;

}

double dist(const Point* a , const Point* b)
{

    return std::sqrt((b -> x - a -> x) * (b -> x - a -> x) + (b -> y - a -> y) * (b -> y - a -> y));

}

void move_by(Point& p, double dx, double dy) {
    p.x += dx;
    p.y += dy;
}

double dist(const Point& a, const Point& b) {
    return std::sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
}

int main()
{

    Point p1 = {1.0, 2.0};
    Point p2 = {4.0, 5.0};
    
    move_by(&p1, 1.0, 1.0);
    double pointeri = dist(&p1, &p2);
    std::cout << pointeri << "\n";

    move_by(p1, 1.0, 1.0);
    double refer = dist(p1, p2);
    std::cout << refer << "\n";

    Point tocke[5] = {
        {3.0, 4.0},
        {1.5, 2.0},
        {5.0, 12.0},
        {0.2, 0.3},
        {2.0, 3.0}
    };
    Point ishodiste = {0.0, 0.0};
        int najbliza = 0;

        double min = dist(tocke[0], ishodiste);

    for(int i = 1;i < 5; i++)
    {

        double sad = dist(tocke[i],ishodiste);
        if(sad < min)
        {

            min = sad;
            najbliza = i;

        }

    }

    std::cout << tocke[najbliza].x << ", " << tocke[najbliza].y << " udaljenost: " << min;
}