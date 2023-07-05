#include <iostream>
#include <string>
#include <vector>
#include <locale>

#include "_variaveis/global.cpp"
#include "./enums/posicao.cpp"

#include <stdexcept>
#include <limits>

#include "utils/funcoes.cpp"

#include "enums/opcoes/principal.cpp"
#include "menus/racha.cpp"

using namespace std;

// Para alocar
// os times, o sistema recebe o número de jogadores de linha, e deve montar times
// balanceados, isto é, os níveis dos times são equilibrados, sendo que o nível de um time é
// dado pela soma dos níveis dos atletas.


bool interfacePrincipal();
void limparTerminal();

int main() {

  // Configura o locale para o idioma português
  std::setlocale(LC_ALL, "pt_BR.UTF-8");

  MenuRacha * menu = new MenuRacha();

  // MOCK

  menu->adicionarJogadorLista("Joao", "Apelido 1", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 2", "Apelido 2", Posicao::Goleiro, 4);
  menu->adicionarJogadorLista("Jogador 3", "Apelido 3", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 4", "Apelido 4", Posicao::Linha, 4);
  menu->adicionarJogadorLista("Jogador 5", "Apelido 5", Posicao::Goleiro, 2);
  menu->adicionarJogadorLista("Jogador 6", "Apelido 6", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 7", "Apelido 7", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 8", "Apelido 8", Posicao::Goleiro, 4);
  menu->adicionarJogadorLista("Jogador 9", "Apelido 9", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 10", "Apelido 10", Posicao::Linha, 4);
  menu->adicionarJogadorLista("Jogador 11", "Apelido 11", Posicao::Goleiro, 2);
  menu->adicionarJogadorLista("Jogador 12", "Apelido 12", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 13", "Apelido 13", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 14", "Apelido 14", Posicao::Goleiro, 4);
  menu->adicionarJogadorLista("Jogador 15", "Apelido 15", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 16", "Apelido 16", Posicao::Linha, 4);
  menu->adicionarJogadorLista("Jogador 17", "Apelido 17", Posicao::Goleiro, 2);
  menu->adicionarJogadorLista("Jogador 18", "Apelido 18", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 19", "Apelido 19", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 20", "Apelido 20", Posicao::Goleiro, 4);
  menu->adicionarJogadorLista("Jogador 21", "Apelido 21", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 22", "Apelido 22", Posicao::Linha, 4);
  menu->adicionarJogadorLista("Jogador 23", "Apelido 23", Posicao::Goleiro, 2);
  menu->adicionarJogadorLista("Jogador 24", "Apelido 24", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 25", "Apelido 25", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 26", "Apelido 26", Posicao::Goleiro, 4);
  menu->adicionarJogadorLista("Jogador 27", "Apelido 27", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 28", "Apelido 28", Posicao::Linha, 4);
  menu->adicionarJogadorLista("Jogador 29", "Apelido 29", Posicao::Goleiro, 2);
  menu->adicionarJogadorLista("Jogador 30", "Apelido 30", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 31", "Apelido 31", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 32", "Apelido 32", Posicao::Goleiro, 4);
  menu->adicionarJogadorLista("Jogador 33", "Apelido 33", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 34", "Apelido 34", Posicao::Linha, 4);
  menu->adicionarJogadorLista("Jogador 35", "Apelido 35", Posicao::Goleiro, 2);
  menu->adicionarJogadorLista("Jogador 36", "Apelido 36", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 37", "Apelido 37", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 38", "Apelido 38", Posicao::Goleiro, 4);
  menu->adicionarJogadorLista("Jogador 39", "Apelido 39", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 40", "Apelido 40", Posicao::Linha, 4);
  menu->adicionarJogadorLista("Jogador 41", "Apelido 41", Posicao::Goleiro, 2);
  menu->adicionarJogadorLista("Jogador 42", "Apelido 42", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 43", "Apelido 43", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 44", "Apelido 44", Posicao::Goleiro, 4);
  menu->adicionarJogadorLista("Jogador 45", "Apelido 45", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 46", "Apelido 46", Posicao::Linha, 4);
  menu->adicionarJogadorLista("Jogador 47", "Apelido 47", Posicao::Goleiro, 2);
  menu->adicionarJogadorLista("Jogador 48", "Apelido 48", Posicao::Linha, 3);
  menu->adicionarJogadorLista("Jogador 49", "Apelido 49", Posicao::Linha, 5);
  menu->adicionarJogadorLista("Jogador 50", "Apelido 50", Posicao::Goleiro, 4);
  
  menu->mostrarMenu();
}