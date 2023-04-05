/*=============BIBLIOTECAS=============*/

#include "Secundaria.h"

/*=============FUNÇÕES=ESTETICAS=============*/

void Secundaria::Load(int sec) { this_thread::sleep_for(chrono::seconds(sec)); }

void Secundaria::LimpaTela() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}

/*=============CONSTRUTORA=============*/

Secundaria::Secundaria() {}

/*=============FUNÇÕES=MENU=============*/

void Secundaria::MenuDeInclusao() {
  if (RGs->getTamanho() == RGs->getCapacidade()) {
    cout << "Sua lista está cheia" << endl;
  } else {
    int RG, PO, ESCOLHA;
    string nome, rg, escolha, p;
    cout << "Informe o Rg e Nome da pessoa que deseja incluir na lista;\t";
    cin >> rg;
    cin >> nome;
    RG = stoi(rg);
    do {
      getchar();
      cout << "\nDeseja Incluir essa pessoa em qual posioção?\n(1)No Incio da "
              "Lista.\n(2)No fim da Lista\n(3)Apos uma posição especifa.\n"
           << endl;
      cin >> escolha;
      ESCOLHA = stoi(escolha);
    } while (ESCOLHA < 1 || ESCOLHA > 3);
    switch (ESCOLHA) {
    case 1:
      RGs->incluaPessoaNoIndice(nome, RG, 0);
      break;
    case 2:
      RGs->incluaPessoaNoFim(nome, RG);
      break;
    case 3:
      do {
        getchar();
        LimpaTela();
        cout << "Em qual posicao deseja incluir sua nova pessoa?\t";
        cin >> p;
        PO = stoi(p);
        LimpaTela();
      } while (PO < 0 || PO > RGs->getTamanho());
      RGs->incluaPessoaNoIndice(nome, RG, PO - 1);
      break;
    }

    cout << "\nPessoa " << nome
         << " foi incluida na lista, para pesquisa-la busque pelo RG " << rg
         << " no menu da busca.\n"
         << endl;
  }
}

void Secundaria::MenuDeBusca() {
  int rg, i;
  if (RGs->getTamanho() == 0) {
    cout << "Sua lista ainda está vazia." << endl;
  } else {
    getchar();
    cout << "Informe o RG que deseja pesquisar:\t";
    cin >> rg;
    i = RGs->BuscaPorRG(rg);
    if (i == -1) {
      cout << "RG não encontrado na Lista." << endl;
    } else {
      cout << "O rg " << rg << " pertence a " << RGs->getNomeNaLista(i)
           << " e está na posição " << (i + 1) << "º na lista.\n"
           << endl;
    }
  }
}

void Secundaria::MenuDeRemocao() {
  if (RGs->getTamanho() == 0) {
    cout << "Sua lista já está vazia." << endl;
    Load(1);
  } else {
    string po, escolha;
    int PO, ESCOLHA;

    do {
      getchar();
      cout << "Desejar remover qual pessoa?\n(1)A primeira\n(2)A "
              "Ultima\n(3)Outra posição\n"
           << endl;
      cin >> escolha;
      ESCOLHA = stoi(escolha);
    } while (ESCOLHA < 1 || ESCOLHA > 3);

    switch (ESCOLHA) {
    case 1:
      RGs->RemovePorIncice(0);
      cout << "Pessoa removida da lista" << endl;
      break;
    case 2:
      RGs->RemovePorIncice(RGs->getTamanho() - 1);
      cout << "Pessoa removida da lista" << endl;
      break;
    case 3:
      cout << "Informe a posição que quer remover:\t";
      cin >> po;
      PO = stoi(po);
      RGs->RemovePorIncice(PO - 1);
      cout << "Pessoa removida da lista" << endl;
      break;
    }
  }
}

int Secundaria::Menu() {

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

void Secundaria::Executar() {
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
      if (RGs->getTamanho() == 0) {
        cout << "Sua lista está vazia." << endl;
      } else {
        RGs->ListaPessoa();
      }
      break;
    case 4:
      if (RGs->getTamanho() == 0) {
        cout << "Sua lista está vazia." << endl;
      } else {
        RGs->ListaPessoa2();
      }
      break;
    case 5:
      MenuDeRemocao();
      break;
    case 6:
      RGs->LerDoArquivo();
      Load(2);
      cout << "Arquivo lido com sucesso" << endl;
      break;
    case 7:
      if (RGs->getTamanho() == 0) {
        cout << "Sua lista ainda está vazia." << endl;
      } else {
        RGs->SalvaLista();
        Load(2);
        cout << "Lista salva." << endl;
      }
      break;
    case 8:
      if (RGs->getTamanho() != 0) {
        RGs->ApagaLista();
      }
      break;
    }
  } while (escolha != 8);
}
