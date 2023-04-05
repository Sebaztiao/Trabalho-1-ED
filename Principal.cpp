/*=============BIBLIOTECAS=============*/

#include "Principal.h"
#include "stdlib.h"
using namespace std;

/*=============CONSTRUTORA=============*/

Principal::Principal() {}

/*=============FUNÇÕES=ESTETICAS=============*/

void Principal::Load(int sec) { this_thread::sleep_for(chrono::seconds(sec)); }

void Principal::LimpaTela() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

/*=============FUNÇÕES=MENU=============*/

void Principal::MenuDeBusca() {
  LimpaTela();
  if (RGs->TestaLista()) {
    int RG, po;
    Pessoa *Pesquisado;
    string nome;
    cout << "Informe o RG que deseja pesquisaar:\t";
    cin >> RG;
    Pesquisado = RGs->Busca(RG);
    nome = Pesquisado->getNome();
    po = Pesquisado->getPosicao();
    cout << "O rg informado pertence a " << nome << " e está na posição " << po
         << "º na lista.\n"
         << endl;
  } else {
    cout << "Sua Lista ainda esta vazia." << endl;
  }
}

void Principal::MenuDeBusca_Remocao() {
  LimpaTela();
  if (!RGs->TestaLista()) {
    cout << "Sua lista está vazia;" << endl;
    return;
  }
  string po, escolha;
  int PO, ESCOLHA;
  do {
    cout << "Desejar remover qual pessoa?\n(1)A primeira\n(2)A "
            "Ultima\n(3)Outra posição\n"
         << endl;
    cin >> escolha;
    ESCOLHA = stoi(escolha);
  } while (ESCOLHA < 1 || ESCOLHA > 3);
  switch (ESCOLHA) {
  case 1:
    RGs->RemoveDoInicio();
    cout << "Pessoa removida da lista" << endl;
    break;
  case 2:
    RGs->RemoveDoFim();
    cout << "Pessoa removida da lista" << endl;
    break;
  case 3:
    cout << "Informe a posição que quer remover:\t";
    cin >> po;
    PO = stoi(po);
    RGs->removePessoaNaPosicao(PO);
    cout << "Pessoa removida da lista" << endl;
    break;
  }
}

void Principal::MenuDeInclusao() {
  int RG, PO, ESCOLHA;
  string nome, escolha, p;
  LimpaTela();
  cout << "Informe o Rg e Nome da pessoa que deseja incluir na lista;\t";
  cin >> RG;
  cin >> nome;
  do {
    cout << "\nDeseja Incluir essa pessoa em qual posioção?\n(1)No Incio da "
            "Lista.\n(2)No fim da Lista\n(3)Apos uma posição especifa.\n"
         << endl;
    cin >> escolha;
    ESCOLHA = stoi(escolha);
  } while (ESCOLHA < 1 || ESCOLHA > 3);
  switch (ESCOLHA) {
  case 1:
    RGs->incluaPessoaNoInicio(nome, RG);
    break;
  case 2:
    RGs->incluaPessoaNoFim(nome, RG);
    break;
  case 3:
    LimpaTela();
    if (!RGs->TestaLista()) {
      cout << "Sua lista ainda não tem posições" << endl;
      return;
    } else {
      cout << "Em qual posicao deseja incluir sua nova pessoa?\t";
      cin >> p;
      PO = stoi(p);
      if (PO > RGs->getTamanho()) {
        cout << "Posição invalida." << endl;
        return;
      } else {
        RGs->incluaPessoaNaPosicao(nome, RG, PO);
      }
    }
    break;
  }
  cout << "\nPessoa " << nome
       << " foi incluida na lista, para pesquisa-la busque pelo RG " << RG
       << " no menu da busca.\n"
       << endl;
}

int Principal::Menu() {
  int ESCOLHA = 0;
  string escolha;
  do {
    cout << "\nEscolha o que deseja fazer:\n(1)Adicionar Item a "
            "lista\n(2)Buscar por um RG\n(3)Ver lista completa(do inicio para "
            "o fim).\n(4)Ver lista completa(do fim para o inicio).\n(5)Remover "
            "RG da lista.\n(6)Ler um arquivo de nome e RGs\n(7)Salvar lista em "
            "um arquivo\n(8)Voltar ao Inicio.\n\n"
         << endl;
    cin >> escolha;
    ESCOLHA = stoi(escolha);
  } while (ESCOLHA < 1 || ESCOLHA > 8);
  return ESCOLHA;
}

/*=============EXECUTORA=============*/

void Principal::Executar() {
  int escolha;
  do {
    getchar();
    escolha = Menu();
    LimpaTela();
    switch (escolha) {
    case 1:
      MenuDeInclusao();
      break;
    case 2:
      MenuDeBusca();
      break;
    case 3:
      RGs->ListaPessoas();
      break;
    case 4:
      RGs->ListaPessoas2();
      break;
    case 5:
      MenuDeBusca_Remocao();
      break;
    case 6:
      RGs->LerDoArquivo();
      break;
    case 7:
      if (!RGs->TestaLista()) {
        cout << "Sua lista está vazia." << endl;
      } else {
        RGs->SalvaLista();
        Load(2);
        cout << "Lista salva." << endl;
      }
      break;
    case 8:
      if (RGs->TestaLista()) {
        RGs->ApagaLista();
      }
      break;
    default:
      cout << "ERRO" << endl;
    }
  } while (escolha != 8);
}