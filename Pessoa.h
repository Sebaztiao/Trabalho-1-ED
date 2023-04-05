/*=============BIBLIOTECAS=============*/

#ifndef _PESSOA_H_
#define _PESSOA_H_
#include <chrono>
#include <thread>
#include "iostream"
#include "sstream"
#include "fstream"
#include "locale.h"
#pragma once
using namespace std;

/*=============CABEÇALHO=============*/

class Pessoa {
private:
  string Nome;
  int RG, Posicao;
  Pessoa *Proximo;
  Pessoa *Anterior;

public:
  Pessoa();
  void setProximo(Pessoa *prox);
  void setAnterior(Pessoa *ante);
  Pessoa *getProximo();
  Pessoa *getAnterior();
  void setNome(string n);
  void setRG(int rg);
  string getNome();
  int getRG();
  bool SouEu(int rg);
  void setPosicao(int p);
  int getPosicao();
};
#endif