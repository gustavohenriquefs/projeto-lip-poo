#include <iostream>
#include <vector>
#include <memory>

#include "../_variaveis/global.cpp"
#include "../enums/opcoes/principal.cpp"
#include "../enums/posicao.cpp"
#include "../utils/funcoes.cpp"
#include "../controllers/jogador.cpp"
#include "./menu.cpp"
#include "../controllers/times.cpp"

using namespace std;

class MenuRacha: public Menu {
  private:
    vector<shared_ptr<Jogador>> jogadores;
    vector<shared_ptr<Time>> times;
  public:
      MenuRacha(): Menu() {};
      
      void mostrarMenu() {
        bool sair = false;
        int op = Opcoes::Sair;
        

        while(!sair) {
          limparTerminal();

          cout << "----- Menu Racha: -----" << nl << nl;

          cout << "- Digite " + to_string(Opcoes::Sair)             + " para sair: "                   << nl;
          cout << "- Digite " + to_string(Opcoes::MostrarJogadores) + " para listar jogadores: "       << nl;
          cout << "- Digite " + to_string(Opcoes::CriarJogador)     + " para adicionar novo jogador: " << nl;
          cout << "- Digite " + to_string(Opcoes::AtualizarJogador) + " para atualizar jogador: "      << nl;
          cout << "- Digite " + to_string(Opcoes::RemoverJogador)   + " para remover jogador: "        << nl;
          cout << "- Digite " + to_string(Opcoes::AlocarTime)       + " para ordenar os times: "       << nl;

          op = selecionarOpcao();

          switch (op)
          {
            case Opcoes::Sair:
              sair = true;
            break;
            case Opcoes::MostrarJogadores: 
              this->mostrarJogadoresRacha();
            break;
            case Opcoes::CriarJogador:
              this->adicionarJogadorLista();
            break;
            case Opcoes::AtualizarJogador:
              this->atualizarJogador();
            break;
            case Opcoes::RemoverJogador:
              this->removerJogaodr();
            break;
            case Opcoes::AlocarTime:
              this->alocarTimeRacha();
            break;
            case Opcoes::ErroEntrada:
              this->pausarTerminal();
            break;
            case Opcoes::OpInvalida:
              this->reload();
            break;
          default:
            break;
          }
        }
      }

      void atualizarJogador() {
        string nome;

        cin.ignore();
        cout << "Qual o nome do jogador que deseja atualizar? ";
        getline(cin, nome);

        shared_ptr<Jogador> jogador = obterJogador(nome);

        if(jogador == nullptr) {
          cout << "Não encontrado" << nl;
          this->pausarTerminal();
          return;
        }

        cout << "Novo nome (deixe em branco para manter o atual): ";
        string novoNome;
        getline(cin, novoNome);
        if (!novoNome.empty()) {
            jogador.get()->setNome(novoNome);
        }

        cout << "Novo apelido (deixe em branco para manter o atual): ";
        string novoApelido;
        getline(cin, novoApelido);
        if (!novoApelido.empty()) {
            jogador.get()->setApelido(novoNome);
        }

        cout << "Novo nível [1-5] (digite para man 0 para manter o atual): ";
        
        int novoNivel;
        cin >> novoNivel;

        if (novoNivel) {
            jogador.get()->setNivel(novoNivel);
        }
      }

      void removerJogaodr() {
        string nome;

        cin.ignore();
        cout << "Qual o nome do jogador que deseja atualizar? ";
        getline(cin, nome);

        for (size_t i = 0; i < jogadores.size(); i++) {
          if(jogadores[i].get()->getNome() == nome) {
            jogadores.erase(jogadores.begin() + i);
            
            cout << "Jogador removido!" << nl;

            this->pausarTerminal();

            return;
          }
        }

        cout << "Não encontrado" << nl;
        this->pausarTerminal();
        return;
      }

      shared_ptr<Jogador> obterJogador(string nome) {
        for (size_t i = 0; i < jogadores.size(); i++) {
          if(jogadores[i].get()->getNome() == nome) {
            return jogadores[i];
          }
        }

        return nullptr;
      }

      void adicionarJogadorLista(string nome, string apelido, int posicao, int nivel) {
        jogadores.push_back(make_shared<Jogador>(nome, apelido, posicao, nivel));
      }

      void adicionarJogadorLista() {

        string nome, apelido;
        int nivel, posicao;

        cin.ignore();

        cout << "Insira o nome: "; getline(cin, nome);

        
        if(this->obterJogador(nome) != nullptr) {
          cout << "Não foi possível continua o cadastro. Esse nome de jogador já existe!" << nl;

          this->pausarTerminal();
          return;
        }

        cout << "Informe a posição do jogador [" + to_string(Posicao::Linha) + " - Linha, " + to_string(Posicao::Goleiro) + " - Goleiro]:"; 
        
        cin >> posicao;
        cin.ignore();

        cout << "Insira o apelido: "; 
        getline(cin, apelido);
        
        cout << "Insira o nivel: [ 1 para Canela, 2 para Frango, 3 para Novato, 4 para Craque, 5 para DoutrinadorDoRacha ]: "; 
        scanf("%d", &nivel);

        jogadores.push_back(make_shared<Jogador>(nome, apelido, posicao, nivel));

        cout << "Jogador inserido!" << nl;

        cin.ignore();
        this->pausarTerminal();
      }

      void mostrarJogadoresRacha() {
        cin.ignore();

        for(auto jogador: jogadores) {
          cout << jogador.get()->toString() << nl;
        }

        cout << nl;
        pausarTerminal();
      }
      
      void alocarTimeRacha() {
        
        vector<shared_ptr<Jogador>> jogadoresGoleiros(jogadores);
        
        sort(jogadoresGoleiros.begin(), jogadoresGoleiros.end(), [](shared_ptr<Jogador> a, shared_ptr<Jogador> b) {
          return a.get()->getNivel() > b.get()->getNivel();
        }); 

        vector<shared_ptr<Jogador>> goleiros;
        vector<shared_ptr<Jogador>> jogadoresLinha;
        
        for(auto jogador: jogadoresGoleiros) {
          if(jogador.get()->getPosicao() == Posicao::Goleiro) {
            goleiros.push_back(jogador);
          } else {
            jogadoresLinha.push_back(jogador);
          }
        }

        bool limitadoPorGoleiros = false;
        int quantidadeMaxTimes = 0;

        if((int)goleiros.size() < (int)jogadoresLinha.size() / 10) {
          limitadoPorGoleiros = true;
          quantidadeMaxTimes = goleiros.size();
        } else {
          quantidadeMaxTimes = jogadoresLinha.size() / 10;
        }

        vector<shared_ptr<Time>> times(quantidadeMaxTimes);

        for(int i = 0; i < quantidadeMaxTimes; ++ i) {
          times[i] = make_shared<Time>(vector<shared_ptr<Jogador>>(), i + 1);
        }
      
        for(int i = 0, idxTime = 0; i < jogadoresLinha.size(); ++ i) {
          if(idxTime == quantidadeMaxTimes) {
            idxTime = 0;
          }

          if(jogadoresLinha[i].get()->getPosicao() == Posicao::Linha) {
            times[idxTime].get()->adicionarJogador(jogadoresLinha[i]);
            ++ idxTime;
          }
        }

        if(limitadoPorGoleiros) {
          for(int i = 0, idxTime = 0; i < goleiros.size(); ++ i) {
            if(idxTime == quantidadeMaxTimes) {
              idxTime = 0;
            }

            times[idxTime].get()->adicionarJogador(goleiros[i]);
            ++ idxTime;
          }
        } else {
          for(int i = 0, idxTime = 0; i < goleiros.size(); ++ i) {
            if(idxTime == quantidadeMaxTimes) {
              idxTime = 0;
            }

            times[idxTime].get()->adicionarJogador(goleiros[i]);
            ++ idxTime;
          }
        }

        for(auto time: times) {
          cout << nl << "=== TIME " << time.get()->getNumero() << " ===" << nl << nl;
          
          for(auto jogador: time.get()->getJogadores()) {
            cout << jogador.get()->toString() << nl;
          }
        }

        cin.ignore();
        this->pausarTerminal();
      }
};