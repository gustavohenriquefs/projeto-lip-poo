#include <vector>
#include <string>

#include "../models/racha.hpp"

Racha::Racha(std::string data, std::string local, std::vector<Time> times) {
  this->data = data;
  this->local = local;
  this->times = times;
}

std::string Racha::getData() {
  return this->data;
}

void Racha::setData(std::string data) {
  this->data = data;
}

std::string Racha::getLocal() {
  return this->local;
}

void Racha::setLocal(std::string local) {
  this->local = local;
}

std::vector<Time> Racha::getTimes() {
  return this->times;
}

void Racha::setTimes(std::vector<Time> times) {
  this->times = times;
}