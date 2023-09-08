#include "cpf.hpp"
#include <cstdlib>
#include <iostream>

int main(int argc, char **argv) {
  auto cpf = std::make_unique<CPF>();

  if (argc > 1) {

    std::string args = argv[1];

    if (args == "--format" || args == "-f") {
      cpf->show();
    }
    else {
        std::cerr << "Parâmetro Inválido" << '\n';
        return EXIT_FAILURE;
    }

  } else {
    std::cout << cpf->get_m_numbs() << '\n';
  }
}
