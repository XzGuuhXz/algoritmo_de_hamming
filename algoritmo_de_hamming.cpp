#include <iostream>

class Hamming
{
    private:
         

    public:
        int decodificador();
        int codificador();
        int menu();
};

int Hamming::decodificador()
{
    int value[4];
    int i;

    for(int i = 0; i < 4; i++)
    {
        std::cout << "Digite os bits de paridade: " << std::endl;
        std::cin >> value[i];
    }

    //implementar o codigo que faz a decodificação

    for(int i = 0; i < 4; i++)
    {
        std::cout << "O valor do bit " << i << " é " << value[i] << std::endl;
    }

    return 0;
}

int Hamming::codificador()
{
    int value[4];
    int i;

    for(int i = 0; i < 4; i++)
    {
        std::cout << "Digite os bits de paridade: " << std::endl;
        std::cin >> value[i];
    }

    //implementar o codigo que faz a codificação

    for(int i = 0; i < 4; i++)
    {
        std::cout << "O valor do bit " << i << " é " << value[i] << std::endl;
    }

    return 0;
}


int main()
{
    Hamming *root = new Hamming();

    root->menu();

    delete root;

    return 0;
}

int Hamming::menu()
{
    int opc;

    std::cout << "\tMenu\n" << std::endl;
    std::cout <<"\t1-Decodificador\n\n\t2-Codificador\n\n\t0-Para sair\n\n" << std::endl;
    std::cout << "\tEscolha uma opção:\t " << std::endl;
    std::cin >> opc;

    do 
        switch(opc)
        {
            case 1:
            decodificador();
            
            break;
        
            case 2:
            codificador();
            break;

            case 0:
            std::cout << "Saindo..\n";
            break;

            default:
            std::cout << "Digite uma opção valida: ";
            break;
        }
    
    while(opc != 0);

    return 0;

}