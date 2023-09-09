#include "cpf.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  auto cpf = std::make_unique<CPF>();

  if (argc > 1) {

    std::vector<std::string> args;

    for(int i = 0; i < argc; i++){
      args[i-1] = argv[i];
    }

    if (args[1] == "--format" || args[1] == "-f") {
      cpf->show();
    }
    else if(args[1] == "--check" || args[1] == "-c"){
      
    }
    else {
        std::cerr << "Parâmetro Inválido" << '\n';
        return EXIT_FAILURE;
    }

  } else {
    std::cout << cpf->get_m_numbs() << '\n';
  }
}
