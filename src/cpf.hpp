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
        CPF();

        std::string get_m_numbs();

        int gen_first_digit();
        int gen_second_digit();

        std::string format();

        void show();

        bool check(std::string*);

    private:
        std::string m_numbs;
};



