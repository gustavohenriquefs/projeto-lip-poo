
#include <string>
#include <algorithm>
#include "../models/jogador.hpp"


// criar novo jogador: (nome, apelido, nivel)
Jogador::Jogador(
  std::string nome, 
  std::string apelido, 
  int posicao, 
  int nivel
) {
  this->nome = nome;
  this->apelido = apelido;
  this->setNivel(nivel);
  this->setPosicao(posicao);
}

Jogador::~Jogador() {}

std::string Jogador::toString() {
  return "Nome: " + this->getNome() + " ; Apelido: " + this->getApelido() + ", Posição: " + this->getStrPosicao()  + "; Nível: " + getStrNivel();
}

std::string Jogador::getStrNivel() {
  switch (this->nivel)
  {
    case TipoNivel::Canela:
      return "Canela";
    break;
    case TipoNivel::Craque:
      return "Craque";
    break;
    case TipoNivel::DoutrinadorDoRacha:
      return "DoutrinadorDoRacha";
    break;
    case TipoNivel::Frango:
      return "Frango";
    break;
    case TipoNivel::Novato:
      return "Novato";
    break;
  }

  return "";
}

std::string Jogador::getStrPosicao() {
  switch (this->posicao)
  {
    case Posicao::Goleiro:
      return "Goleiro";
    case Posicao::Linha:
      return "Linha";
  }

  return "";
}

void Jogador::setNome(std::string nome) {
  this->nome = nome;
}

std::string Jogador::getNome() {
  return this->nome;
}

void Jogador::setApelido(std::string apelido) {
  this->apelido = apelido;
}

std::string Jogador::getApelido() {
  return this->apelido;
}

void Jogador::setNivel(int nivel) {
  // força que o nível esteja no range correto:
  nivel = std::min(nivel, (int)TipoNivel::MaxVal);
  nivel = std::max(nivel, (int)TipoNivel::MinVal);

  switch (nivel)
  {
    case TipoNivel::Canela:
      this->nivel = TipoNivel::Canela;
    break;
    case TipoNivel::Craque:
      this->nivel = TipoNivel::Craque;
    break;
    case TipoNivel::DoutrinadorDoRacha:
      this->nivel = TipoNivel::DoutrinadorDoRacha;
    break;
    case TipoNivel::Frango:
      this->nivel = TipoNivel::Frango;
    break;
    case TipoNivel::Novato:
      this->nivel = TipoNivel::Novato;
    break;
  }
}

TipoNivel Jogador::getNivel() {
  return this->nivel;
}

void Jogador::setPosicao(int posicao) {
  posicao = min(posicao, 2);
  posicao = max(posicao, 1);

  switch (posicao)
  {
    case Posicao::Goleiro:
      this->posicao= Posicao::Goleiro;
    break;
    case Posicao::Linha:
      this->posicao = Posicao::Linha;
    break;
  }
}