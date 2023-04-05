/*=============BIBLIOTECAS=============*/

#include "ListaEncadeada.h"
using namespace std;

/*=============CONSTRUTORA=============*/

ListaEncadeada::ListaEncadeada() {
  Primeira = nullptr;
  Atual = nullptr;
  Movimentos = 0;
  Testes = 0;
}

/*=============TESTANDO=A=LISTA=============*/

bool ListaEncadeada::TestaLista() {
  ListaEncadeada Teste = ListaEncadeada();
  if (Primeira != nullptr) {
    Testes++;
    return true;
  } else {
    return false;
  }
}

int ListaEncadeada::getTamanho() { return Atual->getPosicao(); }

/*=============FUNÇÕES=DE=INCLUSÃO=============*/

void ListaEncadeada::incluaPessoaNoFim(string nome, int rg) {
  Movimentos = 0;
  Testes = 0;
  Pessoa *p;
  p = new Pessoa();
  if (p == nullptr) {
    Testes++;
    cout << "ERRO NA ALOCAÇÃO" << endl;
  }
  p->setRG(rg);
  p->setNome(nome);
  p->setProximo(nullptr);
  Movimentos++;
  p->setAnterior(nullptr);
  Movimentos++;
  if (Primeira == nullptr) {
    Testes++;
    p->setPosicao(1);
    Primeira = p;
    Movimentos++;
    Atual = p;
    Movimentos++;
  } else {
    Atual->setProximo(p);
    Movimentos++;
    p->setAnterior(Atual);
    Movimentos++;
    Atual = p;
    Movimentos++;
    p->setPosicao(((p->getAnterior())->getPosicao()) + 1);
    Movimentos++;
  }
  CustoDaOpcao();
}

void ListaEncadeada::incluaPessoaNoInicio(string nome, int rg) {
  Movimentos = 0;
  Testes = 0;
  Pessoa *p;
  p = new Pessoa();
  if (p == nullptr) {
    Testes++;
    cout << "ERRO NA ALOCAÇÃO" << endl;
  }
  p->setRG(rg);
  p->setNome(nome);
  p->setProximo(nullptr);
  Movimentos++;
  p->setAnterior(nullptr);
  Movimentos++;
  Pessoa *atual = Primeira;
  while (atual != nullptr) {
    atual->setPosicao(atual->getPosicao() + 1);
    atual = atual->getProximo();
  }
  p->setPosicao(1);
  if (Primeira == nullptr) {
    Testes++;
    Primeira = p;
    Movimentos++;
    Atual = p;
    Movimentos++;
  } else {
    p->setProximo(Primeira);
    Primeira->setAnterior(p);
    Movimentos++;
    Primeira = p;
    Movimentos++;
  }
  CustoDaOpcao();
}

void ListaEncadeada::incluaPessoaNaPosicao(string nome, int rg, int po) {
  Movimentos = 0;
  Testes = 0;
  Pessoa *p;
  p = new Pessoa();
  if (p == nullptr) {
    Testes++;
    cout << "ERRO NA ALOCAÇÃO" << endl;
    return;
  }
  p->setRG(rg);
  p->setNome(nome);
  p->setPosicao(po);
  p->setProximo(nullptr);
  Movimentos++;
  p->setAnterior(nullptr);
  Movimentos++;
  if (Primeira == nullptr) {
    Testes++;
    Primeira = p;
    Movimentos++;
    Atual = p;
    Movimentos++;
    return;
  }
  if (po == 1) {
    Testes++;
    p->setProximo(Primeira);
    Primeira->setAnterior(p);
    Movimentos++;
    Primeira = p;
    Movimentos++;
    AtualizaPosicoes(Primeira->getProximo());
    Movimentos++;
    return;
  }
  Pessoa *anterior = Primeira;
  for (int i = 1; i < po - 1 && anterior->getProximo() != nullptr; i++) {
    anterior = anterior->getProximo();
    Movimentos++;
  }
  if (anterior->getProximo() == nullptr) {
    Testes++;
    anterior->setProximo(p);
    Movimentos++;
    p->setProximo(anterior);
    Movimentos++;
    AtualizaPosicoes(p->getProximo());
    return;
  }
  Pessoa *aux;
  aux = anterior->getProximo();
  Movimentos++;
  anterior->setProximo(p);
  Movimentos++;
  p->setAnterior(anterior);
  Movimentos++;
  p->setProximo(aux);
  Movimentos++;
  aux->setAnterior(p);
  Movimentos++;
  AtualizaPosicoes(p->getProximo());

  CustoDaOpcao();
}

void ListaEncadeada::incluaPessoaDiscretamente(string nome, int rg) {
  Movimentos = 0;
  Testes = 0;
  Pessoa *p;
  p = new Pessoa();
  if (p == nullptr) {
    Testes++;
    cout << "ERRO NA ALOCAÇÃO" << endl;
  }
  p->setRG(rg);
  p->setNome(nome);
  p->setProximo(nullptr);
  Movimentos++;
  p->setAnterior(nullptr);
  Movimentos++;
  if (Primeira == nullptr) {
    Testes++;
    p->setPosicao(1);
    Primeira = p;
    Movimentos++;
    Atual = p;
    Movimentos++;
  } else {
    Atual->setProximo(p);
    Movimentos++;
    p->setAnterior(Atual);
    Movimentos++;
    Atual = p;
    Movimentos++;
    p->setPosicao(((p->getAnterior())->getPosicao()) + 1);
  }
}

/*=============FUNÇÕES=DE=REMOÇÃO=============*/

void ListaEncadeada::RemoveDoInicio() {
  Movimentos = 0;
  Testes = 0;
  Pessoa *aux;
  aux = Primeira->getProximo();
  if (aux != nullptr) {
    Testes++;
    aux->setAnterior(nullptr);
  }
  delete Primeira;
  Primeira = aux;
  Movimentos++;
  CustoDaOpcao();
}

void ListaEncadeada::RemoveDoFim() {
  Movimentos = 0;
  Testes = 0;
  Pessoa *aux;
  aux = Atual->getAnterior();
  if (aux != nullptr) {
    Testes++;
    aux->setProximo(nullptr);
  }
  delete Atual;
  Atual = aux;
  Movimentos++;
  CustoDaOpcao();
}

void ListaEncadeada::removePessoaNaPosicao(int po) {
  Movimentos = 0;
  Testes = 0;
  Pessoa *p = Primeira;
  if (po == 1) {
    Testes++;
    Primeira = Primeira->getProximo();
    Movimentos++;
    if (Primeira != nullptr) {
      Testes++;
      Primeira->setAnterior(nullptr);
      Movimentos++;
    }
    delete p;
    AtualizaPosicoes(Primeira);
    return;
  }

  for (int i = 1; p != nullptr && i < po; i++) {
    p = p->getProximo();
    Movimentos++;
  }

  if (p == nullptr) {
    Testes++;
    cout << "Posição inválida." << endl;
    return;
  }

  if (p->getProximo() == nullptr) {
    Testes++;
    (p->getAnterior())->setProximo(nullptr);
    Movimentos++;
    delete p;
    return;
  }

  (p->getAnterior())->setProximo(p->getProximo());
  Movimentos++;
  (p->getProximo())->setAnterior(p->getAnterior());
  Movimentos++;
  delete p;
  AtualizaPosicoes(p, po);
  CustoDaOpcao();
}

string ListaEncadeada::Busca_E_Remove(int rg) {
  Movimentos = 0;
  Testes = 0;
  string positiva, negativa;
  positiva = "RG removido com sucesso";
  negativa = "RG não encontrado";
  Pessoa *Pesquisado, *aux;
  Pesquisado = Primeira;
  aux = nullptr;
  while (Pesquisado != nullptr) {
    if (Pesquisado->SouEu(rg)) {
      Testes++;
      if (aux != nullptr) {
        Testes++;
        aux->setProximo(Pesquisado->getProximo());
        Movimentos++;
      } else {
        Primeira = Pesquisado->getProximo();
        Movimentos++;
      }
      delete Pesquisado;
      CustoDaOpcao();
      return positiva;
    } else {
      Pesquisado = Pesquisado->getProximo();
      Movimentos++;
      aux = Pesquisado->getAnterior();
      Movimentos++;
    }
  }
  CustoDaOpcao();
  return negativa;
}

/*=============FUNÇÕES=COM=ARQUIVO=============*/

void ListaEncadeada::SalvaLista() {
  Movimentos = 0;
  Testes = 0;
  if (TestaLista()) {
    string Arquivo;
    cout << "Escloha o nome do arquivo:\t" << endl;
    cin >> Arquivo;
    ofstream outfile(Arquivo);
    Pessoa *i;
    i = Primeira;
    while (i != nullptr) {
      outfile << i->getNome() << "," << i->getRG() << endl;
      i = i->getProximo();
    }
    outfile.close();
  } else {
    cout << "Sua lista ainda está vazia." << endl;
  }
  CustoDaOpcao();
}

void ListaEncadeada::LerDoArquivo() {
  Movimentos = 0;
  Testes = 0;
  string nome = "", Arquivo;
  int rg = 0;
  cout << "\nQual o nome do arquivo que deseja ler?\t";
  cin >> Arquivo;
  cout << "\nLendo do arquivo " << Arquivo << ".\n" << endl;
  ifstream Arq(Arquivo);
  if (!Arq.is_open()) {
    Testes++;
    cout << "\nErro na abertura do arquivo." << endl;
    return;
  }
  string linha;
  while (getline(Arq, linha)) {
    size_t virgula = linha.find(",");
    nome = linha.substr(0, virgula);
    rg = stoi(linha.substr(virgula + 1));
    incluaPessoaDiscretamente(nome, rg);
  }
  Arq.close();
  cout << "\nArquivo lido com sucesso" << endl;
  CustoDaOpcao();
}

/*=============FUNÇÃO=DE=APRESENTAÇÃO=============*/

void ListaEncadeada::ListaPessoas() {
  Movimentos = 0;
  Testes = 0;
  if (TestaLista()) {
    Testes++;
    Pessoa *aux;
    aux = Primeira;
    while (aux != nullptr) {
      cout << "O RG " << aux->getRG() << " pertence a " << aux->getNome()
           << ", que está na posição " << aux->getPosicao() << "º na lista.\n"
           << endl;
      aux = aux->getProximo();
      Movimentos++;
    }
  } else {
    cout << "Sua Lista ainda está vazia." << endl;
  }
  CustoDaOpcao();
}

void ListaEncadeada::ListaPessoas2() {
  Movimentos = 0;
  Testes = 0;
  if (TestaLista()) {
    Testes++;
    Pessoa *aux;
    aux = Atual;
    while (aux != nullptr) {
      cout << "O RG " << aux->getRG() << " pertence a " << aux->getNome()
           << ", que está na posição " << aux->getPosicao() << "º na lista.\n"
           << endl;
      aux = aux->getAnterior();
      Movimentos++;
    }
  } else {
    cout << "Sua lista Ainda está vazia." << endl;
  }
  CustoDaOpcao();
}

Pessoa *ListaEncadeada::Busca(int rg) {
  Movimentos = 0;
  Testes = 0;
  Pessoa *Pesquisado;
  Pesquisado = Primeira;
  while (Pesquisado != nullptr) {
    if (Pesquisado->SouEu(rg)) {
      Testes++;
      CustoDaOpcao();
      return Pesquisado;
    } else {
      Pesquisado = Pesquisado->getProximo();
      Movimentos++;
    }
  }
  CustoDaOpcao();
  return NULL;
}

void ListaEncadeada::CustoDaOpcao() {
  cout << "\nEssa opção fez " << Movimentos << " movimentos na lista e "
       << Testes << " testes logicos.\n"
       << endl;
}

/*=============ATUALIZANDO=A=LISTA=============*/

void ListaEncadeada::AtualizaPosicoes(Pessoa *p) {
  int i = p->getPosicao() + 1;
  for (; p != nullptr; p = p->getProximo()) {
    p->setPosicao(i++);
  }
}

void ListaEncadeada::AtualizaPosicoes(Pessoa *p, int pos_removida) {
  for (; p != nullptr; p = p->getProximo()) {
    if (p->getPosicao() >= pos_removida) {
      Testes++;
      p->setPosicao(p->getPosicao() - 1);
    }
  }
}

void ListaEncadeada::ApagaLista() {
  Movimentos = 0;
  Testes = 0;
  Pessoa *aux;

  while (Primeira != nullptr) {
    aux = Primeira;
    Primeira = Primeira->getProximo();
    Movimentos++;
    delete aux;
  }
  CustoDaOpcao();
}