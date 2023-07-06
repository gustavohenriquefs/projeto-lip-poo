#include <vector>
#include <memory>

#include "jogador.hpp"
// entidade time, que contém um número, um conjunto com jogadores e um goleiro.

/*
  [ ] - Não é válido numeros negativos?

  funcionalidades:
    - [] - criar cruds
*/

class Time
{
  private:
  
    unsigned int numero;
    std::vector<std::shared_ptr<Jogador>> jogadores;   
  
  public:
  
    Time(std::vector<std::shared_ptr<Jogador>> jogadores, unsigned int numero);
    
    ~Time();

    void setNumero(unsigned int numero);

    unsigned int getNumero();

    void setJogadores(std::vector<std::shared_ptr<Jogador>> jogadores);

    void adicionarJogador(shared_ptr<Jogador> Jogador);

    std::vector<std::shared_ptr<Jogador>> getJogadores();
};
