#include <iostream>

using namespace std;

#ifdef _WIN32
    #define CLEAR_COMMAND "cls"
#else
    #define CLEAR_COMMAND "clear"
#endif

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
      system("serve.bat");
    } catch (...) {
      std::cout << "O arquivo não existe, ou não é compatível com o SO." << nl;
    }
  }

};
