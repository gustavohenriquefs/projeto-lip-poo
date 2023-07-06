#ifndef I_JOGADOR_H
#define I_JOGADOR_H

#include <string>
#include "../enums/nivel.cpp"
#include "../enums/posicao.cpp"

class Jogador
{
  private:
  
    std::string nome;
    
    std::string apelido;

    Posicao posicao;

    TipoNivel nivel;
  
  public:
    Jogador(std::string nome, std::string apelido, int posicao, int nivel);
    
    ~Jogador();


    std::string toString();

    std::string getStrNivel();

    void setNome(std::string nome);
    
    std::string getNome();

    void setApelido(std::string apelido);

    std::string getApelido();

    void setPosicao(int posicao);

    Posicao getPosicao();

    void setNivel(int nivelJogador);

    TipoNivel getNivel();

    std::string getStrPosicao();
};

#endif