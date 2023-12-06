#include <thread>
#include <mutex>
#include <stdexcept>

#include "data.h"
#include "swap.h"

Data::Data()
{
    value = 0.0;
}

Data::Data(Data&& other)
{
    value = std::move(other.value);
}

Data& Data::operator=(Data&& other)
{
    if (this == &other)
    {
        return *this;
    }

    value = std::move(other.value);

    return *this;
}

void Data::set_value(double new_value)
{
    mut.lock();
    value = new_value;
    mut.unlock();
}

double Data::get_value()
{
    mut.lock();
    double value_copy = value;
    mut.unlock();

    return value_copy;
}
