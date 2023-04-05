/*=============BIBLIOTECAS=============*/

#include "ListaSequencial.h"
#include "fstream"

/*=============CONSTRUTORA=============*/

ListaSequencial::ListaSequencial(int cap) {
  capacidade = cap;
  tamanho = 0;
  lista = new Pessoa[cap];
}

/*=============DESTRUTORA=============*/

void ListaSequencial::ApagaLista(){
  delete [] lista;
  tamanho = 0;
}

/*=============FUNÇÕES=DE=INCLUSÃO=============*/

void ListaSequencial::incluaPessoaNoFim(string nome, int rg) {
  Movimentos = 0;
  Testes = 0;
  Pessoa novo;
  novo.setNome(nome);
  novo.setRG(rg);
  lista[tamanho] = novo;
  tamanho++;
  Movimentos++;
  Testes++;
  CustoDaOpcao();
}

void ListaSequencial::incluaPessoaNoIndice(string nome, int rg, int p) {
  Movimentos = 0;
  Pessoa novo;
  novo.setNome(nome);
  novo.setRG(rg);
  for (int i = tamanho; i > p; i--) {
    Movimentos++;
    lista[i] = lista[i - 1];
  }
  lista[p] = novo;
  tamanho++;
  CustoDaOpcao();
}
void ListaSequencial::incluaPessoaDiscretamente(string nome, int rg) {
  Pessoa novo;
  novo.setNome(nome);
  novo.setRG(rg);
  lista[tamanho] = novo;
  tamanho++;
  Movimentos++;
  Testes++;
}
/*=============FUNÇÕES=COM=ARQUIVO=============*/

void ListaSequencial::LerDoArquivo() {
  Movimentos = 0;
  Testes = 0;
  string nome, Arquivo, linha;
  int rg;
  cout << "\nQual o nome do arquivo que deseja ler?\t";
  cin >> Arquivo;
  ifstream Arq(Arquivo);
  if (!Arq.is_open()) {
    Testes++;
    cout << "Erro na abertura do arquivo." << endl;
    return;
  }
  while (getline(Arq, linha) && tamanho != capacidade) {
    size_t virgula = linha.find(",");
    nome = linha.substr(0, virgula);
    rg = stoi(linha.substr(virgula + 1));
    incluaPessoaDiscretamente(nome, rg);
    Movimentos++;
  }
  if (tamanho == capacidade) {
    Testes++;
    cout << "Sua lista chegou ao limite da capacidade e pode não ter lido todo "
            "o seu arquivo."
         << endl;
  }
  Arq.close();
  CustoDaOpcao();
}

void ListaSequencial::SalvaLista() {
  Movimentos = 0;
  Testes = 0;
  string Arquivo;
  cout << "Escloha o nome do arquivo:\t" << endl;
  cin >> Arquivo;
  ofstream outfile(Arquivo);
  for (int i = 0; i < tamanho; i++) {
    Movimentos++;
    outfile << lista[i].getNome() << "," << lista[i].getRG() << endl;
  }
  outfile.close();
  CustoDaOpcao();
}

/*=============FUNÇÕES=DE=REMOÇÃO=============*/

void ListaSequencial::RemovePorIncice(int p) {
  Movimentos = 0;
  for (int i = p; i < tamanho - 1; i++) {
    lista[i] = lista[i + 1];
    Movimentos++;
  }
  tamanho--;
  CustoDaOpcao();
}

/*=============FUNÇÃO=DE=APRESENTAÇÃO=============*/

void ListaSequencial::ListaPessoa() {
  Movimentos = 0;

  for (int i = 0; i < tamanho; i++) {
    Movimentos++;
    cout << "O Rg " << lista[i].getRG() << " pertence a " << lista[i].getNome()
         << ", ocupando a posição " << (i + 1) << "° na lista.\n"
         << endl;
  }
  CustoDaOpcao();
}

void ListaSequencial::ListaPessoa2() {
  Movimentos = 0;
  for (int i = tamanho; i != 0; i--) {
    Movimentos++;
    cout << "O Rg " << lista[i].getRG() << " pertence a " << lista[i].getNome()
         << ", ocupando a posição " << (i + 1) << "° na lista.\n"
         << endl;
  }
  CustoDaOpcao();
}

int ListaSequencial::BuscaPorRG(int rg) {
  Movimentos = 0;
  Testes = 0;

  for (int i = 0; i < tamanho; i++) {
    Movimentos++;
    if (lista[i].SouEu(rg)) {
      Testes++;
      return i;
    } else {
      continue;
    }
  }
  CustoDaOpcao();
  return -1;
}

void ListaSequencial::CustoDaOpcao() {
  cout << "\nEssa opção fez " << Movimentos << " movimentos na lista e "
       << Testes << " testes logicos.\n"
       << endl;
}

/*=============FUNÇÕES=DE=GET=============*/

int ListaSequencial::getTamanho() { return tamanho; }

int ListaSequencial::getCapacidade() { return capacidade; }

string ListaSequencial::getNomeNaLista(int i) { return lista[i].getNome(); }

int ListaSequencial::getRgNaLista(int i) { return lista[i].getRG(); }