#include <iostream>
#include <string>

using namespace std;

struct Aluno {
	int id;
	string nome;
	string semestre;
	int ano_ingressao;
	string curso;
};


void inserir_aluno();
void editar_aluno();
void exibir_aluno();
void sobrescrever_aluno();
void limpar_memoria();


int main() {
	
    int opcao;

    do {
        cout << "Selecione uma opção:\n";
        cout << "1. Inserir aluno\n";
        cout << "2. Editar aluno\n";
        cout << "3. Exibir aluno\n";
        cout << "4. Sobrescrever aluno\n";
        cout << "5. Sair\n";
        cout << "Opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                inserir_aluno();
                break;
            case 2:
                editar_aluno();
                break;
            case 3:
                exibir_aluno();
                break;
            case 4:
                sobrescrever_aluno();
                break;
            case 5:
                cout << "Saindo...\n";
                break;
            default:
                cout << "Opção inválida. Escolha novamente.\n";
        }
    } while (opcao != 5);

    return 0;
}

