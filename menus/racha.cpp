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
              this->alocarTimes();
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
        
        cout << "Insira o nivel: [1 - 5]: "; 
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

      void alocarTimes() {
        cout << "----- ALOCAR TIMES -----" << nl << nl;
        
        vector<shared_ptr<Jogador>> jogadoresOrd(this->jogadores);

        sort(jogadoresOrd.begin(), jogadores.end(), [](shared_ptr<Jogador> a, shared_ptr<Jogador> b) {
          return a.get()->getNivel() > b.get()->getNivel();
        });

        int quantidadeTime = this->jogadores.size() / 11;

        cout << "Foram formados: " << quantidadeTime << "time" << (quantidadeTime > 1 ? "s" : "" ) << nl << nl;

        this->times.assign(quantidadeTime, make_shared<Time>(vector<shared_ptr<Jogador>>(), 0));


        // distribui os jogadores nos times:
        for(int numJogador = 0; numJogador < 11; ++ numJogador) {
          for(int idxTime = 0, idxJogador; idxTime < quantidadeTime; ++ quantidadeTime) {
            idxJogador = numJogador + idxTime;

            this->times[idxTime].get()->getJogadores()[numJogador] = this->jogadores[idxJogador];
          }
        }

        for(int idxTime = 0, idxJogador; idxTime < quantidadeTime; ++ quantidadeTime) {
          cout << "--- Time " << idxTime + 1 << "--- " << nl << nl;

          vector<shared_ptr<Jogador>> timeJogadores = this->times[idxTime].get()->getJogadores();
          
          for(int numJogador = 0; numJogador < 11; ++ numJogador) {
            idxJogador = numJogador + idxTime;

            Jogador * jogador = timeJogadores[numJogador].get();

            cout << numJogador + 1 << " - " << jogador->toString() << nl;
          }

          this->pausarTerminal();
        }
      }
};