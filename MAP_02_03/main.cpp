#include <iostream>
#include <thread>
#include <mutex>

#include "data.h"
#include "swap.h"

int main()
{
    Data* p_d1 = new Data();
    Data* p_d2 = new Data();

    p_d1->set_value(5.2);
    p_d2->set_value(-9.25);

    std::cout << "d1.value = " << p_d1->get_value() << std::endl;
    std::cout << "d2.value = " << p_d2->get_value() << std::endl;

    myswap::swap(*p_d1, *p_d2);

    std::cout << "Swaped\n";

    std::cout << "d1.value = " << p_d1->get_value() << std::endl;
    std::cout << "d2.value = " << p_d2->get_value() << std::endl;

    delete p_d1;
    delete p_d2;

    return 0;
}
