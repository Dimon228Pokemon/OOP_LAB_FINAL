
#include <iostream>
#include "Figure.h"
#include "Array.h"

int main()
{
    setlocale(LC_ALL, "ru");
    Triangle<double> f3;
    std::cout << "f3=" << f3 << std::endl;
    f3.setPoints({ {1,2},{3,2},{4,5} });
    std::cout << "f3=" << f3 << std::endl;
    Hexagon<double> f6;
    f6.setPoints({ {61,2},{36,24},{47,75},{36,24},{47,75},{36,24} });
    std::cout << "f6=" << f6 << std::endl;
    std::cout << "================================== " << std::endl;
    std::cout << "вывод в поток" << std::endl;
    std::cout << f3 << std::endl;
    //std::cout << "================================== " << std::endl;
    //std::cout << "чтение из потока" << std::endl;
    //std::cin >> f3;
    //std::cout << f3 << std::endl;
    std::cout << "================================== " << std::endl;
    std::cout << "вывод площади" << std::endl;
    std::cout << "S f3 = " << f3.getSquare() << std::endl;
    std::cout << "S(f3) = " << static_cast<double>(f3) << std::endl;
    std::cout << "================================== " << std::endl;
    std::cout << "координаты центра" << std::endl;
    std::cout << "Center = (" << f3.getCenter().first << ", " << f3.getCenter().second << ")" << std::endl;
    std::cout << "================================== " << std::endl;
    std::cout << "сравнение" << std::endl;
    Triangle<double> f31;
    f31.setPoints({ {31,32},{13,12},{24,25} });
    std::cout << "f3 = " << f3 << std::endl;
    std::cout << "f31 = " << f31 << std::endl;
    std::cout << " (f3 == f31) = " << (f3 == f31) << std::endl;
    std::cout << "--------------------- " << std::endl;
    f3.setPoints({ { 100,0 }, { 21,1 }, { 2,5 } });
    f31.setPoints({ { 100,0 }, { 21,1 }, { 2,5 } });
    std::cout << "f3 = " << f3 << std::endl;
    std::cout << "f31 = " << f31 << std::endl;
    std::cout << " (f3 == f31) = " << (f3 == f31) << std::endl;
    std::cout << "================================== " << std::endl;
    std::cout << "копирование" << std::endl;
    f31.setPoints({ { 5,5 }, { 21,35 }, { 27,75 } });
    std::cout << "f31 = " << f31 << std::endl;
    std::cout << "f3 = " << f3 << std::endl;
    std::cout << "f31 = f3 " << std::endl;
    f31 = f3;
    std::cout << "f31 = " << f31 << std::endl;

    std::cout << "================================== " << std::endl;
    std::cout << "Array<Figure>" << std::endl;
    Array<Figure<double>> fig;
    fig.add(new Triangle<double>);
    std::cout << "size = " << fig.size() << std::endl;
    std::cout << *fig.ptr_arr[0] << std::endl;
    fig.get(0)->setPoints({ { 100,0 }, { 21,1 }, { 2,5 } });
    std::cout << *fig.ptr_arr[0] << std::endl;
    fig.add(new Triangle<double>);
    fig.get(1)->setPoints({ { 30,0 }, { 210,1 }, { 2,5 } });
    fig.add(new Triangle<double>);
    fig.get(2)->setPoints({ { 40,0 }, { 210,1 }, { 2,5 } });
    //std::cin>>*fig.get(2);
    fig.add(new Triangle<double>);
    fig.get(3)->setPoints({ { 50,0 }, { 210,1 }, { 2,5 } });
    fig.add(new Hexagon<double>);
    fig.get(4)->setPoints({ { 50,0 }, { 210,1 }, { 2,5 }, { 50,0 }, { 210,1 }, { 2,5 } });
    fig.add(new Octagon<double>);
    fig.get(5)->setPoints({ { 50,0 }, { 210,1 }, { 2,5 }, { 50,0 }, { 210,1 }, { 2,5 }, { 210,1 }, { 2,5 } });
    fig.showAll();
    fig.dell(2);
    fig.showAll();
}

