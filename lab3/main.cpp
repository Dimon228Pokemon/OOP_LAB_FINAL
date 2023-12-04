#include <iostream>
#include "F3.h"
#include "F6.h"
#include "F8.h"
#include <string>
#include "ArrayFigure.h"

int main()
{

    setlocale(LC_ALL,"ru");
    F3 f3(0.0, 0.0, 1.0, 0.0, 0.0, 2.0);

    //std::cin >> f3;
    std::cout <<"f3="<< f3 << std::endl;

    std::cout << "S(f3) = " << f3.getSquare() << std::endl;
    std::cout << "S(f3) = " << static_cast<double>(f3) << std::endl;

    std::cout << "(x0,y0) = " << f3.getCentr() << std::endl;

    F3 f3_1(5.0, 5.0, 0.0, 7.0, 0.0, 9.0);
    std::cout << "f3_1=" << f3_1 << std::endl;


    std::cout << "Copy"  << std::endl;
    F3 f3_2(f3);
    std::cout << "f3_2=" << f3_2 << std::endl;
    std::cout << "f3=" << f3 << std::endl<< std::endl;
    f3_2 = f3_1;
    std::cout << "f3_2=" << f3_2 << std::endl;
    std::cout << "f3_1=" << f3_1 << std::endl<< std::endl;

    std::cout<<"(f3 == f3_1) = "<<(f3==f3_1) << std::endl;
    std::cout<<"(f3_2 == f3_1) = "<<(f3_2==f3_1) << std::endl;

    std::cout << "Move" << std::endl;
    f3_2 = std::move(f3);
    //f3_2 = static_cast<F3&&>(f3);
    std::cout << "f3_2=" << f3_2 << std::endl;
    std::cout << "f3=" << f3 << std::endl<< std::endl;

    F3 f3_3(static_cast<F3&&>(f3_1));
    //F3 f3_3(std::move(f3_1));
    std::cout << "f3_3=" << f3_3 << std::endl;
    std::cout << "f3_1=" << f3_1 << std::endl << std::endl;

    ArrayFigure arrF;

    arrF.add(new F3(0, 0, 3, 3, 4, 2));
    arrF.add(new F6(0.0, 0.0, 1.0, 0.0, 1.5, 0.866, 1.0, 1.732, 0.0, 1.732, -0.5, 0.866));
    arrF.add(new F8 (-1.0, 0.0, -0.707, 0.707, 0.0, 1.0,
     0.707, 0.707, 1.0, 0.0, 0.707, -0.707, 0.0, -1.0, -0.707, -0.707));


    arrF.showAll();

    F6* f6;
    f6= new F6();
    delete f6;
}


