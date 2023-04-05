
/* https://replit.com/@Sebazera/Trabalho-1-ED */

/*=============BIBLIOTECAS=============*/

#include "Principal.h"
#include "Secundaria.h"
class Principal;
class Secundaria;

/*=============FUNÇÃO=DE=APRESENTAÇÃO=============*/

void Info();

void Escolhas(string nome);

void LimpaTela();

void Saida(string nome);

void Load(int sec);

/*=============FUNÇÃO=MAIN=============*/

int main() {
  setlocale(LC_ALL, "Portuguese");
  string nome;
  LimpaTela();
  cout << "Olá, Qual o seu nome:\t";
  cin >> nome;
  LimpaTela();
  cout << "Então " << nome;
  cout << " nesse programa procurei implementar um sistema que coleta, "
          "armazena e organiza dados. Ele faz isso tendo dois meios de "
          "execução, quem decidirá o melhor é você. "
       << endl;
  Load(4);
  int escolha = -1;
  do {
    do {
      LimpaTela();
      cout << "\nAgora escolha entre:\n(1)Uma lista sequencial\n(2)Uma lista "
              "encadeada\n(3)Obter mais informações sobre os dois "
              "tipos\n(4)Encerrar o Progama\n"
           << endl;
      cin >> escolha;
    } while (escolha < 1 || escolha > 4);
    LimpaTela();
    if (escolha == 1) {
      Escolhas(nome);
      Secundaria j;
      Load(3);
      LimpaTela();
      j.Executar();
    } else if (escolha == 2) {
      Escolhas(nome);
      Principal i;
      Load(3);
      LimpaTela();
      i.Executar();
    } else if (escolha == 3) {
      Info();
      cout << "\nPara voltar ao inicio digite enter." << endl;
      while (getchar() != '\n')
        ;
      getchar();
    } else if (escolha == 4) {
      Saida(nome);
    }
  } while (escolha != 4);
  return 0;
}

/*=============FUNÇÃO=DE=APRESENTAÇÃO=============*/

void Info() {
  cout << " Lá vai uma explicação breve:\n As listas encadeadas nada mais são "
          "que uma sequência de células ligadas ou encadeadas umas às outras. "
          "As células de uma lista encadeada são compostas por três elementos "
          "cada. O primeiro elemento é o dado efetivo a ser armazenado, o "
          "segundo compraz uma referência para o próximo elemento da lista e o "
          "terceiro compraz uma referência para o elemento anterior da "
          "lista.\nJá uma lista é dita sequencial quando seus componentes são "
          "armazenados em posições contíguas na memória. A implementação mais "
          "comum de uma lista sequencial usa um vetor (array), mas pode ser "
          "também usado um arquivo ou conjunto."
       << endl;
}

void Escolhas(string nome) {
  cout << "Que bom que escolheu uma das opções, " << nome
       << " lembre-se que sua escolha não é um caminho sem volta, boa sorte."
       << endl;
}

void Saida(string nome) {
  cout << nome
       << " obrigado por usar minha lista.\n\n\n\n\n\t\t\t\tby Sebastião De "
          "Castro";
}
void Load(int sec) { this_thread::sleep_for(chrono::seconds(sec)); }

void LimpaTela() {
#ifdef _WIN32
  system("cls");
#else
  system("clear");
#endif
}