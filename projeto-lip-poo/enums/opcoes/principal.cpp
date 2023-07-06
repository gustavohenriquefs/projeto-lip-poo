#ifndef ENUMS_OPCOES_PRINCIPAL_H
#define ENUMS_OPCOES_PRINCIPAL_H

#include "../../_variaveis/global.cpp"

enum Opcoes {
  Sair = 99,
  ErroEntrada = 0,
  MostrarJogadores = 1,
  CriarJogador = 2,
  AtualizarJogador = 3,
  RemoverJogador = 4,
  AlocarTime = 5,
  OpInvalida = ERRO_PADRAO
};

enum OpcoesJogadores {
  Criar = 0
};

#endif