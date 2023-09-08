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
  int d1 = 0;

  for (size_t i = 0, k = 10; i < this->m_numbs.size(); i++, k--) {
    d1 += std::stoi(this->m_numbs.substr(i, 1)) * k;
  }

  return (d1 % 11 < 2) ? 0 : 11 - (d1 % 11);
}

int CPF::gen_second_digit() {
  int d2 = 0;

  for (size_t i = 0, k = 10; i < this->m_numbs.size() - 1; i++, k--) {
    d2 += std::stoi(this->m_numbs.substr(i + 1, 1)) * k;
  }

  return (d2 % 11 < 2) ? 0 : 11 - (d2 % 11);
}

std::string CPF::get_m_numbs() { return this->m_numbs; }

std::string CPF::format()
{
  std::string fmt = this->m_numbs;

  fmt.insert(fmt.size() - 8, 1, '.');
  fmt.insert(fmt.size() - 5, 1, '.');
  fmt.insert(fmt.size() - 2, 1, '-');

  return fmt;

}

void CPF::show()
{
  std::cout << this->format() << std::endl;
}

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
