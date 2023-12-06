#include <thread>
#include <mutex>

#include "variants.h"
#include "settings.h"
#include "data.h"
#include "swap.h"

void myswap::swap(Data& obj_1, Data& obj_2)
{
    switch (settings::solution_variant)
    {

    // 1 вариант
    case variants::lock:
    {
        std::lock(obj_1.mut, obj_2.mut);
        std::lock_guard<std::mutex> lk1(obj_1.mut, std::adopt_lock);
        std::lock_guard<std::mutex> lk2(obj_2.mut, std::adopt_lock);

        Data tmp = std::move(obj_1);
        obj_1 = std::move(obj_2);
        obj_2 = std::move(tmp);
    }
        break;

    // 2 вариант
    case variants::scoped_lock:
    {
        std::scoped_lock sc_lk(obj_1.mut, obj_2.mut);

        Data tmp = std::move(obj_1);
        obj_1 = std::move(obj_2);
        obj_2 = std::move(tmp);
    }
        break;

    // 3 вариант
    case variants::unique_lock:
    {
        std::unique_lock<std::mutex> uq_lk1(obj_1.mut,  std::defer_lock);
        std::unique_lock<std::mutex> uq_lk2(obj_2.mut,  std::defer_lock);
        std::lock(uq_lk1, uq_lk2);

        Data tmp = std::move(obj_1);
        obj_1 = std::move(obj_2);
        obj_2 = std::move(tmp);
    }
        break;

    default:
        break;
    }

}
