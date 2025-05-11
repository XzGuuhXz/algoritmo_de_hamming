#include <iostream>

using namespace std ;

class Hamming
{
  private:
         

  public:
    int decodificador();
    int codificador();
    void menu();
};

int Hamming::decodificador()
{
  int quantidade;

  cout << "Digite a quantidade de bits que deseja: ";
  cin >> quantidade;

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

  int paridade = 0;

  for(int i = 0; i < quantidade; i++)
  {
    if(bit[i]== 1)
    {
      paridade ^= (i + 1);
    }
  }

  if(paridade == 0)
  {
    cout << "Nem um erro foi encontrado!!" << "\n\n" << endl;
  }
  else
  {
    cout << "Erro encontado no bit de posição: " << paridade << endl;
  }
    
  delete[] bit;
  return paridade;
}

int Hamming::codificador()
{
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
