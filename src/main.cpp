#include "cpf.hpp"

int main(int argc, char **argv) {
  auto cpf = std::make_unique<CPF>();

  if (argc > 1) {

    std::string args = argv[1];

    if (args == "--format" || "-f") {
      cpf->show();
    }

  } else {
    std::cout << cpf->get_m_numbs() << '\n';
  }
}
