/*=============BIBLIOTECAS=============*/

#include "ListaEncadeada.h"

/*=============CABEÇALHO=============*/

class Principal {
private:
  ListaEncadeada *RGs = new ListaEncadeada();

public:
  Principal();
  int Menu();
  void MenuDeBusca();
  void MenuDeInclusao();
  void MenuDeBusca_Remocao();
  void Load(int sec);
  void LimpaTela();
  void Executar();
};