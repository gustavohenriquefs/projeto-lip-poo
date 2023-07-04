#include <iostream>
#include <string>
#include <vector>
#include <locale>

#include "_variaveis/global.cpp"

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
  
  menu->mostrarMenu();
}

// bool interfacePrincipal() {
//   int op = Opcoes::Sair;

//   limparTerminal();
//   cout << "Menu:" << nl;

//   cout << "Digite [1] para acessar o menu de Jogadores" << nl;

//   op = selecionarOpcao();  

//   switch (op)
//   {
//     case Opcoes::Jogadores:
//       /* 
      
//       [ ] - Menu de Jogadores

//        */
//       break;
    
//     case Opcoes::Sair:
//       return false;
//     default:
      
//       break;
//     }

//   return false;
// }


// void interfaceJogadores() {
//   bool sair = false;

//   while(!sair) {
//     int op = Opcoes::Sair;

//     op = selecionarOpcao();

//     switch (op)
//     {
//     case Opcoes::Sair:
//       sair = true;
//       break;
//     default:
//       break;
//     }
//   }
// }

