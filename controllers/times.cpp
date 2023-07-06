#include <vector>

#include "../models/time.hpp"

Time::Time(std::vector<std::shared_ptr<Jogador>> jogadores, unsigned int numero) {
  this->jogadores = jogadores;
  this->numero = numero;
}

Time::~Time() {}

std::vector<std::shared_ptr<Jogador>> Time::getJogadores() {
  return this->jogadores;
}

void Time::adicionarJogador(shared_ptr<Jogador> jogador) {
  this->jogadores.push_back(jogador);
}

void Time::setJogadores(std::vector<std::shared_ptr<Jogador>> jogadores) {
  this->jogadores = jogadores;
}

unsigned int Time::getNumero() {
  return this->numero;
}

void Time::setNumero(unsigned int numero) {
  this->numero = numero;
}
