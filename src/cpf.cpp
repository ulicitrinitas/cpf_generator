#include "cpf.hpp"

#include <cstdint>
#include <cstdlib>
#include <sodium/core.h>
#include <sodium/randombytes.h>

CPF::CPF(std::string nums)
{
    this->m_numbs = nums;
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

