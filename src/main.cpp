#include <cpf.hpp>

int main(void)
{
    auto cpf = std::make_unique<CPF>();

    std::cout << cpf->get_m_numbs() << '\n';

}
