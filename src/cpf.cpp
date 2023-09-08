#include "cpf.hpp"

#include <cstdint>
#include <cstdlib>
#include <sodium/core.h>
#include <sodium/randombytes.h>
#include <string>

CPF::CPF() {
  for (int i = 0; i < 9; i++) {
    this->m_numbs += std::to_string(rand_gen(10));
  }

  this->m_numbs += std::to_string(this->gen_first_digit());
  this->m_numbs += std::to_string(this->gen_second_digit());
}

int CPF::gen_first_digit() {
  int d1;

  for (size_t i = 0, k = 0; i < this->m_numbs.size(); i++, k--) {
    d1 += std::stoi(this->m_numbs.substr(i, 1)) * k;
  }

  return (d1 % 11 < 2) ? 0 : 11 - (d1 % 11);
}

int CPF::gen_second_digit() {
  int d1;

  for (size_t i = 0, k = 0; i < this->m_numbs.size() - 1; i++, k--) {
    d1 += std::stoi(this->m_numbs.substr(i + 1, 1)) * k;
  }

  return (d1 % 11 < 2) ? 0 : 11 - (d1 % 11);
}

std::string CPF::get_m_numbs() { return this->m_numbs; }

int rand_gen(int seed) {
  const int buff_size = 64;

  if (sodium_init() == -1) {
    std::cout << "Erro!\n"
              << "Falha ao gerar números" << '\n';
    exit(EXIT_FAILURE);
  }

  char buffer[buff_size];

  randombytes_buf(buffer, buff_size);

  uint32_t n = randombytes_uniform(seed);

  return n;
}
