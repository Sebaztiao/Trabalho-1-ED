/*=============BIBLIOTECAS=============*/

#include "Pessoa.h"
using namespace std;
class Pessoa;

/*=============CABEÇALHO=============*/

class ListaEncadeada {
private:
  Pessoa *Primeira;
  Pessoa *Atual;
  int Movimentos;
  int Testes;

public:
  ListaEncadeada();
  void incluaPessoaNoFim(string nome, int rg);
  void incluaPessoaNoInicio(string nome, int rg);
  void incluaPessoaNaPosicao(string nome, int rg, int po);
  void incluaPessoaDiscretamente(string nome, int rg);
  void RemoveDoInicio();
  void RemoveDoFim();
  void removePessoaNaPosicao(int po);
  void ListaPessoas();
  void ListaPessoas2();
  Pessoa *Busca(int rg);
  string Busca_E_Remove(int rg);
  bool TestaLista();
  void AtualizaPosicoes(Pessoa *p);
  void AtualizaPosicoes(Pessoa *p, int pos_removida);
  void LerDoArquivo();
  void SalvaLista();
  void ApagaLista();
  void CustoDaOpcao();
  int getTamanho();
};