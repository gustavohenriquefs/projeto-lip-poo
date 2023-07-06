#ifndef UTILS_FUNCS_H
#define UTILS_FUNCS_H

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
#include "../enums/erro.cpp"

using namespace std;

std::string obterMensagemErro(Erro cod) {
  switch (cod)
  {
    case Erro::EntradaInvalida_Int:
      return "Não foi possível identificar o tipo da entrada fornecido, por favor, insira um dos valores válidos!";
    
    case Erro::ErroPadrao:
    default:
      return "Não foi possível realizar a ação necessário, tente novamente mais tarde!";
  }

  return "";
}



int selecionarOpcao() {
  int op = ERRO_PADRAO;

  try {
    // obter opção que o usuário selecionou:
    cin >> op;
  
    if (std::cin.fail()) {
      // A falha na extração ocorreu

      // Limpa a flag failbit do cin
      cin.clear();

      // Descarta o conteúdo inválido do buffer de entrada
      cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

      throw runtime_error(
        obterMensagemErro(Erro::EntradaInvalida_Int)
      );
    }
  } catch (const std::exception& ex) {
    cout << ex.what() << nl;
  }

  return op;
}

#endif