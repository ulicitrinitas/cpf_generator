#include "cpf.hpp"

#include <cstdint>
#include <cstdlib>
#include <sodium/core.h>
#include <sodium/randombytes.h>
#include <string>

CPF::CPF()
{
    for(int i = 0; i < 9; i++){
        this->m_numbs += std::to_string(rand_gen(10)); 
    }
}

std::string CPF::get_m_numbs()
{
    return this->m_numbs;
}

int rand_gen(int seed)
{
    const int buff_size = 64;

    if(sodium_init() == -1){
        std::cout << "Erro!\n" << "Falha ao gerar números" << '\n';
        exit(EXIT_FAILURE);
    }

    char buffer[buff_size];

    randombytes_buf(buffer, buff_size);

    uint32_t n = randombytes_uniform(seed);

    return n;

}

