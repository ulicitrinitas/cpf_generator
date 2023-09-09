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
      if(cpf->check(&(args[2]))){
        std::cout << "\033[32;1m\u2714 CPF válido!\033[m" << '\n';
      }
      else{
        std::cerr << "\033[31;1m\u2716 CPF Inválido ou Parâmetro Inválido" << '\n';
        return EXIT_FAILURE;
      }
    }
    else {
        std::cerr << "\033[31;1m\u2716 Parâmetro Inválido" << '\n';
        return EXIT_FAILURE;
    }

  } else {
    std::cout << cpf->get_m_numbs() << '\n';
  }
}
