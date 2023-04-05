/*=============BIBLIOTECAS=============*/

#include "ListaSequencial.h"
#define MAX 13000000

/*=============CABEÇALHO=============*/

class Secundaria {
private:
  ListaSequencial *RGs = new ListaSequencial(MAX);

public:
  Secundaria();
  void MenuDeInclusao();
  void MenuDeBusca();
  void MenuDeRemocao();
  int Menu();
  void Executar();
  void LimpaTela();
  void Load(int sec);
};