#include "cpf.hpp"
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char **argv) {
  auto cpf = std::make_unique<CPF>();

  if (argc > 1) {

    std::vector<std::string> args;

    for(int i = 1; i < argc; i++){
      args.push_back(argv[i]);
    }

    if (args[0] == "--format" || args[0] == "-f") {
      cpf->show();
    }
    else if(args[0] == "--check" || args[0] == "-c"){
      
      if(args.size() <= 1){
        std::cerr << "\033[31;1m\u2716 Parâmetro Inválido \033[m" << '\n';
        return EXIT_FAILURE;
      }

      if(cpf->check(&(args[1]))){
        std::cout << "\033[32;1m\u2714 CPF válido! \033[m" << '\n';
      } else{
        std::cerr << "\033[31;1m\u2716 CPF Inválido \033[m" << '\n';
        return EXIT_FAILURE;
      }
    }
    else {
      std::cerr << "\033[31;1m\u2716Parâmetro Inválido\033[m" << '\n';
      return EXIT_FAILURE;
    }

  } else {
    std::cout << cpf->get_m_numbs() << '\n';
  }
}
