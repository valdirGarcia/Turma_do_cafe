#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Aluno {
    int id;
    string nome;
    string semestre;
    int ano_ingresso;
    string curso;
};

struct Contribuinte{
    int id_aluno;
    int mes;
    int ano;
    string valor_contribuicao;
};

struct NodeAluno {
    Aluno aluno;
    NodeAluno* proximo;
};

struct NodeContribuicao {
    Contribuinte contribuicoes;
    NodeContribuicao* proximo;
};

void inserir_aluno();
void editar_aluno();
void exibir_aluno();
void cadastrar_contribuinte();
void gravar_e_exibir();
void gravar_relatorio_por_curso();
void liberar_memoria();

NodeAluno* lista_alunos = NULL;
NodeContribuicao* lista_contribuicoes = NULL;

int main() {
    int opcao;

   do {
        cout << "Selecione uma opcao:\n";
        cout << "1. Inserir aluno\n";
        cout << "2. Editar aluno\n";
        cout << "3. Exibir aluno\n";
        cout << "4. Cadastrar contribuinte\n";
        cout << "5. Exibir contribuinte\n";
        cout << "6. Gravar relatorio por curso\n"; 
        cout << "7. Sair\n";
        cout << "Opcao: ";
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
            cadastrar_contribuinte();
            break;
        case 5:
            gravar_e_exibir();
            break;
        case 6:
            gravar_relatorio_por_curso(); 
            break;
        case 7:
            cout << "Saindo...\n";
            liberar_memoria(); 
            break;
        default:
            cout << "Opcao invalida. Escolha novamente.\n";
        }
    } while (opcao != 7);


    return 0;
}

void inserir_aluno() {
    NodeAluno* novo_aluno = new NodeAluno; 
    
    cout << "ID: ";
    cin >> novo_aluno->aluno.id;
    cout << "Nome: ";
    cin >> novo_aluno->aluno.nome;
    cout << "Semestre: ";
    cin >> novo_aluno->aluno.semestre;
    cout << "Ano de Ingresso: ";
    cin >> novo_aluno->aluno.ano_ingresso;
    cout << "Curso (DSM, SI, ou GE): ";
    cin >> novo_aluno->aluno.curso;

    novo_aluno->proximo = lista_alunos; 
    
    lista_alunos = novo_aluno;
}

void editar_aluno() {    
    int id_aluno;
    
    cout << "Digite o ID do aluno que deseja editar: ";
    cin >> id_aluno;

    NodeAluno* atual = lista_alunos;

    while (atual != NULL) {
        if (atual->aluno.id == id_aluno) {
            cout << "Novo Nome: ";
            cin >> atual->aluno.nome;
            cout << "Novo Semestre: ";
            cin >> atual->aluno.semestre;
            cout << "Novo Ano de Ingresso: ";
            cin >> atual->aluno.ano_ingresso;
            cout << "Novo Curso (DSM, SI, ou GE): ";
            cin >> atual->aluno.curso;
            cout << "Aluno editado com sucesso!" << endl;
            return;
        }
        atual = atual->proximo;
    }

    cout << "Aluno nao encontrado." << endl;
}

void exibir_aluno() {
    ofstream arquivo("participantes.txt"); 

    if (!arquivo) {
        cout << "Erro ao criar o arquivo." << endl;
        return;
    }

    NodeAluno* atual = lista_alunos;

    while (atual != NULL) {
       
        arquivo << "ID: " << atual->aluno.id << "\nNome: " << atual->aluno.nome << "\nSemestre: " << atual->aluno.semestre << "\nAno de Ingresso: " << atual->aluno.ano_ingresso << "\nCurso: " << atual->aluno.curso << "\n\n";
        
        atual = atual->proximo;
    }

    arquivo.close(); 

   
    ifstream arquivo_leitura("participantes.txt");
    if (!arquivo_leitura) {
        cout << "Erro ao abrir o arquivo." << endl;
        return;
    }

    string linha;
    while (getline(arquivo_leitura, linha)) {
        cout << linha << endl;
    }

    arquivo_leitura.close();
}

void cadastrar_contribuinte() {
    int id_participante;
    cout << "Digite o ID do participante: ";
    cin >> id_participante;

   
    NodeAluno* atual = lista_alunos;
    bool participante_encontrado = false;
    while (atual != NULL) {
        if (atual->aluno.id == id_participante) {
            participante_encontrado = true;
            break;
        }
        atual = atual->proximo;
    }

    if (!participante_encontrado) {
        cout << "ID do participante nao encontrado. Nenhuma contribuicao cadastrada." << endl;
        return;
    }

   
    NodeContribuicao* nova_contribuicao = new NodeContribuicao;
    nova_contribuicao->contribuicoes.id_aluno = id_participante;

    cout << "Mes (1-12): ";
    cin >> nova_contribuicao->contribuicoes.mes;

    cout << "Ano (>=2024): ";
    cin >> nova_contribuicao->contribuicoes.ano;

    cout << "Valor da contribuicao: ";
    cin >> nova_contribuicao->contribuicoes.valor_contribuicao;

   
    nova_contribuicao->proximo = lista_contribuicoes;
    lista_contribuicoes = nova_contribuicao;

    cout << "Contribuicao cadastrada com sucesso!" << endl;
}

void gravar_e_exibir() {
    
    ofstream arquivo("contribuintes.txt"); 

    if (!arquivo) {
        cout << "Erro ao criar o arquivo de contribuintes." << endl;
        return;
    }

    NodeContribuicao* atual = lista_contribuicoes;

    while (atual != NULL) {
       
        arquivo << "ID do Aluno: " << atual->contribuicoes.id_aluno << "\nMes: " << atual->contribuicoes.mes << "\nAno: " << atual->contribuicoes.ano << "\nValor da Contribuicao: " << atual->contribuicoes.valor_contribuicao << "\n\n";

        atual = atual->proximo;
    }

    arquivo.close(); 

    cout << "Contribuintes gravados com sucesso no arquivo contribuintes.txt." << endl;

   
    cout << "Contribuintes:" << endl;
    atual = lista_contribuicoes;

    while (atual != NULL) {
        cout << "ID: " << atual->contribuicoes.id_aluno << "\nMes: " << atual->contribuicoes.mes << "\nAno: " << atual->contribuicoes.ano << "\nValor da Contribuicao: " << atual->contribuicoes.valor_contribuicao << "\n\n";

        atual = atual->proximo;
    }
}

void gravar_relatorio_por_curso() {
  
    if (lista_contribuicoes == NULL) {
        cout << "Nenhum contribuinte cadastrado. Impossivel gerar o relatorio." << endl;
        return;
    }

    NodeContribuicao* atual = lista_contribuicoes;

   
    ofstream arquivo_DSM("contribuintes_DSM.txt");
    ofstream arquivo_SI("contribuintes_SI.txt");
    ofstream arquivo_GE("contribuintes_GE.txt");

    if (!arquivo_DSM || !arquivo_SI || !arquivo_GE) {
        cout << "Erro ao criar os arquivos de relatorio." << endl;
        return;
    }

    
    while (atual != NULL) {
        NodeAluno* aluno_atual = lista_alunos;
        string curso_contribuinte;
        while (aluno_atual != NULL) {
            if (aluno_atual->aluno.id == atual->contribuicoes.id_aluno) {
                curso_contribuinte = aluno_atual->aluno.curso;
                break;
            }
            aluno_atual = aluno_atual->proximo;
        }

        if (curso_contribuinte == "DSM") {
            arquivo_DSM << "ID do Aluno: " << atual->contribuicoes.id_aluno << "\nMes: " << atual->contribuicoes.mes << "\nAno: " << atual->contribuicoes.ano << "\nValor da Contribuicao: " << atual->contribuicoes.valor_contribuicao << "\n\n";
        } else if (curso_contribuinte == "SI") {
            arquivo_SI << "ID do Aluno: " << atual->contribuicoes.id_aluno << "\nMes: " << atual->contribuicoes.mes << "\nAno: " << atual->contribuicoes.ano << "\nValor da Contribuicao: " << atual->contribuicoes.valor_contribuicao << "\n\n";
        } else if (curso_contribuinte == "GE") {
            arquivo_GE << "ID do Aluno: " << atual->contribuicoes.id_aluno << "\nMes: " << atual->contribuicoes.mes << "\nAno: " << atual->contribuicoes.ano << "\nValor da Contribuicao: " << atual->contribuicoes.valor_contribuicao << "\n\n";
        }

        atual = atual->proximo;
    }

   
    arquivo_DSM.close();
    arquivo_SI.close();
    arquivo_GE.close();

    cout << "Relatorio de contribuintes por curso gravado com sucesso." << endl;
}

void liberar_memoria() {
   
    while (lista_alunos != NULL) {
        NodeAluno* temp = lista_alunos;
        lista_alunos = lista_alunos->proximo;
        delete temp;
    }

    while (lista_contribuicoes != NULL) {
        NodeContribuicao* temp = lista_contribuicoes;
        lista_contribuicoes = lista_contribuicoes->proximo;
        delete temp;
    }
}



