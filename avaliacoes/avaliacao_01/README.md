# 📝 Atividade avaliativa - Projeto C

***

## 👨🏻‍💻 Sobre este projeto

O **Projeto C** consistia na criação de um pequeno CRUD para gerenciamento de uma lanchonete, com perfis distintos para o cliente e gerente, incluindo a gerência de estoque e carrinho.

***

## 📋 Considerações

Particularmente, foi bastante trabalhoso implementar todas as funções necessárias e contornar os problemas sem utilizar POO. Para evitar a reescrita desnecessária de código optei por utilizar a modularização ao máximo, por isso este projeto possui um arquivo extra, denominado **file**, que lida com todas as ações necessárias para escrita e leitura de arquivos.

As funções presentes nesse arquivo são acessíveis tanto pelo gerente como pelo cliente e implementam todas as ações necessárias para o CRUD, restando apenas adaptar a leitura de entrada a cada situação e menu requisitado. 

Nesse projeto também temos uma mudança quanto a extensão do arquivo, que aqui é um **_.csv_**. Essa foi uma escolha pessoal e se deve a facilidade de visualizar os dados fora do programa, uma vez que utilizei uma matriz e um arquivo em csv permite a utilização em softwares de planilha.

***

## 🏗️ Estrutura do projeto


- <kbd><font color="#F3778F">main.cpp</font></kbd>
: Arquivo principal do projeto.
- <kbd><font color="#C472A0">*.hpp</font></kbd>
: Arquivos headers.
- <kbd><font color="#AFCEE9">file.cpp</font></kbd>
: Funções para leitura e escrita de arquivos.
- <kbd><font color="#FFF7A9">gerente.cpp</font></kbd>
: Funções para gerenciamento de estoque e menu do gerente.
- <kbd><font color="#FFF7A9">cliente.cpp</font></kbd>
: Funções para gerenciamento de carrinho e menu do cliente.