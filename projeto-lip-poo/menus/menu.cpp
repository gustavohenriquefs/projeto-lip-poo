#include <iostream>
#include "../_variaveis/global.cpp"

using namespace std;

class Menu {
  public:
  Menu() {};

  ~Menu() {};

  void limparTerminal() {
    try {
      system(CLEAR_COMMAND);
    } catch (...) {
      cout << "Falha ao tentar limpar a tela" << endl;
    }
  }

  void pausarTerminal() {
    string c = "";

    std::cout << "Pressione Enter para sair..." << nl;

    cin.ignore();
  }

  void reload() {
    try {
      system(RELOAD_FILE);
    } catch (...) {
      std::cout << "O arquivo não existe, ou não é compatível com o SO." << nl;
    }
  }

};
