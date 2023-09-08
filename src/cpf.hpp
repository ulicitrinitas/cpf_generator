#pragma once

#include <iostream>
#include <iomanip>
#include <memory>

#include <ctime>
#include <cmath>

#include <sodium.h>
#include <pthread.h>
#include <string>

int rand_gen(int);
class CPF{
    public:
        CPF(std::string);
    private:
        std::string m_numbs;
};



