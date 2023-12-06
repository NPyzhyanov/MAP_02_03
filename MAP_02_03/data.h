#ifndef DATA_H
#define DATA_H

class Data
{
public:
    Data();
    Data(const Data& other) = delete;
    Data(Data&& other);
    Data& operator=(const Data& other) = delete;
    Data& operator=(Data&& other);

    void set_value(double new_value);
    double get_value();

    std::mutex mut;

private:
    double value;

};

#endif // DATA_H
