# Laboratórios de Sistemas Operacionais (Mestrado em  Ciência da Computação - FACOM - UFMS)

O diretório "lab 01", é referente a criação de um módulo do kernel no linux (Debian), foi implementado neste módulo uma simples estrutura de dados (Lista Encadeada).

## Executando o módulo Kernel

Você vai precisar ter o compilador "gcc" instalado na sua máquina, caso não tenha execute os comandos abaixo: 

1. Instale o pacote "build-essential" que tras o "gcc" make e as bibliotecas básicas de C, execute os comandos abaixo
  
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ```sudo apt update```

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ```sudo apt install build-essential```

2. Instale os Kernel Headers 

&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; ```sudo apt install linux-headers-$(uname -r)```

## Como Compilar e Rodar

* Comando para gerar o arquivo 'modkernel.ko':

  ```make```
  
* Comando para inserir o módulo:
  
  ```sudo insmod modkernel.ko```
  
* Comando para visualizar as mensagens ou o que foi feito no módulo (printk):
  
  ```sudo dmesg | tail -n 20```
  
* Comando para remover o módulo::
  
  ```sudo rmmod modkernel```
