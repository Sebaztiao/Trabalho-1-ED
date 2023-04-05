/*=============BIBLIOTECAS=============*/

#include "Pessoa.h"
using namespace std;

/*=============CABEÇALHO=============*/

class ListaSequencial {
private:
  Pessoa *lista;
  int tamanho;
  int capacidade;
  int Movimentos;
  int Testes;

public:
  ListaSequencial(int cap);
  void ApagaLista();
  void incluaPessoaNoFim(string nome, int rg);
  void incluaPessoaNoIndice(string nome, int rg, int p);
  void incluaPessoaDiscretamente(string nome, int rg);
  void RemovePorIncice(int p);
  int getTamanho();
  void LerDoArquivo();
  void SalvaLista();
  int BuscaPorRG(int rg);
  void ListaPessoa();
  void ListaPessoa2();
  int getCapacidade();
  string getNomeNaLista(int i);
  int getRgNaLista(int i);
  void CustoDaOpcao();
};