#include <iostream>

using namespace std ;

class Hamming
{
  private:
    int decodificador();
    int codificador();      

  public:
    void menu();
};

int Hamming::decodificador()
{
  int quantidade;
  int i = 0;

  cout << "Digite a quantidade de bits que deseja (4 ou 7): ";
  cin >> quantidade;

  if (quantidade != 4 && quantidade != 7)
  {
    cout << "Entrada inválida! Só são permitidos 4 ou 7 bits.\n\n";
    return -1;
  }

  int *bit = new int[quantidade];

  cout << "Digite os bits (0 ou 1):\n";

  for (int i = 0; i < quantidade; i++) 
  {
    cout << "Bit " << i << ": ";
    cin >> bit[i];

    while (bit[i] != 0 && bit[i] != 1) 
    {
      cout << "Bit inválido! Digite 0 ou 1: ";
      cin >> bit[i];
    }
  }

  if (quantidade == 4)
  {
    // --- Codificador (4 dados , 7 dados)
    // data d1,d2,d3,d4 em bit[0..3]
    int cw[7] = {0};
    cw[2] = bit[0];
    cw[4] = bit[1];
    cw[5] = bit[2];
    cw[6] = bit[3];

    // calcular paridades p1,p2,p4
    cw[0] = cw[2] ^ cw[4] ^ cw[6];  // pos 1
    cw[1] = cw[2] ^ cw[5] ^ cw[6];  // pos 2
    cw[3] = cw[4] ^ cw[5] ^ cw[6];  // pos 4

    cout << "\nPos decodificação (7 bits): ";
    for (i = 0; i < 7; i++)
      cout << cw[i];
    cout << "\n\n";

    delete[] bit;
    return 0;
  }
  if(quantidade == 7) // quantidade == 7
  {
    // --- Decodificador (corrige o vetor de 7 bits)
    // calcula p1,p2,p4 a partir das posições fixas
    int p1 = bit[0] ^ bit[2] ^ bit[4] ^ bit[6];
    int p2 = bit[1] ^ bit[2] ^ bit[5] ^ bit[6];
    int p4 = bit[3] ^ bit[4] ^ bit[5] ^ bit[6];
    int posErro = p1 + 2*p2 + 4*p4;

    if (posErro == 0)
    {
      cout << "Nenhum erro foi encontrado!\n\n";
    }
    else if (posErro > 0 && posErro <= 7)
    {
      cout << "Erro encontrado no bit de posição: " << posErro << "\n\n";
      bit[posErro - 1] ^= 1;
      cout << "Bit corrigido: ";
      for (i = 0; i < 7; i++)
        cout << bit[i];
      cout << "\n\n";
    }
    else
    {
      cout << "Erro de paridade fora do intervalo!\n\n";
    }

    delete[] bit;
    return posErro;
  }

  return 0;
}

int Hamming::codificador()
{
  
  const int DADOS = 4;
  const int TOTAL = 7;
  
  int dados[DADOS];
  int cw[TOTAL] = {0};  // inicializado em zero
  
  cout << "Digite 4 bits de dados (0 ou 1):\n";
  for (int i = 0; i < DADOS; i++)
  {
    cout << "Dado " << i+1 << ": ";
    cin >> dados[i];
    while (dados[i] != 0 && dados[i] != 1)
    {
      cout << "Inválido! Digite 0 ou 1: ";
      cin >> dados[i];
    }
  }
  
  // Mapeia dados em codeword
  cw[2] = dados[0];  // pos 3
  cw[4] = dados[1];  // pos 5
  cw[5] = dados[2];  // pos 6
  cw[6] = dados[3];  // pos 7
  
  // Calcula bits de paridade
  cw[0] = cw[2] ^ cw[4] ^ cw[6];  // p1
  cw[1] = cw[2] ^ cw[5] ^ cw[6];  // p2
  cw[3] = cw[4] ^ cw[5] ^ cw[6];  // p4

  cout << "Codeword gerado (7 bits): ";
  for (int i = 0; i < TOTAL; i++)
    cout << cw[i];
  cout << endl;
  
  return 0;

}
  
int main()
{
  Hamming *root = new Hamming();

  root->menu();

  delete root;

  return 0;
}

void Hamming::menu()
{
  int opc;

  do 
  {
    std::cout << "\tMenu\n";
    std::cout << "\t1 - Decodificador\n";
    std::cout << "\t2 - Codificador\n";
    std::cout << "\t0 - Sair\n";
    std::cout << "\tEscolha uma opção: ";
    std::cin >> opc;

    switch(opc)
    {
      case 1:
        decodificador();
        break;
      case 2:
        codificador();
        break;
      case 0:
        std::cout << "Saindo...\n";
        break;
      default:
        std::cout << "Opção inválida.\n";
        break;
    }

  } while(opc != 0);
}
