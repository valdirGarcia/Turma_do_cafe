# Turma do Café

**Turma do Café** é um programa em C++ para gerenciamento de alunos e contribuições financeiras, permitindo cadastrar, editar e exibir informações de alunos, além de gerenciar contribuições e gerar relatórios.

## Funcionalidades

1. **Gerenciamento de Alunos**
   - Inserir novos alunos.
   - Editar informações de alunos existentes.
   - Exibir detalhes de alunos cadastrados.

2. **Gerenciamento de Contribuições**
   - Cadastrar contribuições financeiras vinculadas a alunos.
   - Exibir contribuições cadastradas.
   - Gerar relatórios de contribuições por curso (DSM, SI, GE).

3. **Relatórios**
   - Gravar e exibir detalhes de alunos e contribuições em arquivos de texto.
   - Gerar relatórios específicos por curso.

## Estruturas Principais

O programa utiliza listas encadeadas para armazenar alunos e contribuições:
- **`Aluno`**: Estrutura que contém informações do aluno (ID, nome, semestre, ano de ingresso e curso).
- **`Contribuinte`**: Estrutura que contém informações sobre contribuições (ID do aluno, mês, ano e valor da contribuição).
