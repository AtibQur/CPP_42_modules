#pragma once

#include <iostream>

struct Data
{
    std::string val;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);
