/*=============BIBLIOTECAS=============*/

#include "Pessoa.h"

/*=============CONSTRUTORA=============*/

Pessoa::Pessoa() {
  Nome = "";
  RG = 0;
  Proximo = nullptr;
  Anterior = nullptr;
}

/*=============FUNÇÕES=DE=SET=============*/

void Pessoa::setNome(string n) { Nome = n; }

void Pessoa::setRG(int rg) { RG = rg; }

void Pessoa::setProximo(Pessoa *prox) { Proximo = prox; }

void Pessoa::setPosicao(int p) { Posicao = p; }

void Pessoa::setAnterior(Pessoa *ante) { Anterior = ante; }

/*=============FUNÇÕES=DE=GET=============*/

string Pessoa::getNome() { return Nome; }

int Pessoa::getRG() { return RG; }

int Pessoa::getPosicao() { return Posicao; }

Pessoa *Pessoa::getProximo() { return Proximo; }

Pessoa *Pessoa::getAnterior() { return Anterior; }

/*=============FUNÇÃO=QUE=TESTA=============*/

bool Pessoa::SouEu(int rg) { return (rg == RG) ? true : false; }