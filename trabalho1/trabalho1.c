// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome:
//  email:
//  Matrícula:
//  Semestre:

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 07/05/2021 - 19/08/2016 - 17/10/2025

// #################################################

#include <stdio.h>
#include "trabalho1.h" 
#include <stdlib.h>

DataQuebrada quebraData(char data[]);

/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
  int i, fat = 1;
    
  for (i = x; i > 1; i--)
    fat = fat * i;
    
  return fat;
}

int teste(int a)
{
    int val;
    if (a == 2)
        val = 3;
    else
        val = 4;

    return val;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
int q1(char data[])
{
  int datavalida = 1;

  //quebrar a string data em strings sDia, sMes, sAno
    int dia, mes, ano;
    int acumulador = 0; int etapa=0;

    
    for(int i =0; data[i]!= '\0'&& data[i]!= '\n';i++){
    
        if(data[i]>= '0'&& data[i]<= '9'){
            acumulador= acumulador*10 + (data[i]-'0');
        }
        else if (data[i]== '/'){
            
            if (etapa==0){
                dia=acumulador;
                acumulador=0;
                etapa++;
            }
            else if (etapa==1){
                mes=acumulador;
                acumulador=0;
                etapa++;
            }
                    
            }

    }
        if (etapa==2){
                ano=acumulador;
            }  
            if  (etapa!= 2){
               return 0;
            }
            if (ano<100){
                ano+=2000;
            }
            if (dia<1 || dia>31 || mes<1 || mes>12 || ano<0){
               return 0;
            }
            else  if  ((mes==4 || mes==6 || mes ==9 || mes==11) && dia>30){
               return 0;
            }

            else if (mes==2 && (ano%4==0 && ano%100!=0 || ano%400==0) && dia>29){
               return 0;
            }
            else if (mes==2 && !(ano%4==0 && ano%100!=0 || ano%400==0) && dia>28){
               return 0;
            }
            else{
                return 1;
            }



}



/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. 
 @saida
    Retorna um tipo DiasMesesAnos. No atributo retorno, deve ter os possíveis valores abaixo
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
    Caso o cálculo esteja correto, os atributos qtdDias, qtdMeses e qtdAnos devem ser preenchidos com os valores correspondentes.
 */
 void pegardata(char data[], int *dia, int *mes, int *ano){

        *dia=0;
        *mes=0;
        *ano=0;
        int acumulador = 0; int etapa=0;
        int diaanterior=0, mesanterior=0, anoanterior=0;

        for(int i =0; data[i]!= '\0'&& data[i]!= '\n';i++){
        
            if(data[i]>= '0'&& data[i]<= '9'){
                acumulador= acumulador*10 + (data[i]-'0');
            }
            else if (data[i]== '/'){
                
                if (etapa==0){
                    *dia=acumulador;
                    acumulador=0;
                    etapa++;
                }
                else if (etapa==1){
                    *mes=acumulador;
                    acumulador=0;
                    etapa++;
                }
                        
                }

        }
            if (etapa==2){
                    *ano=acumulador;
                }  
                if  (etapa!= 2){
                *ano= acumulador;
                }
                if ( *ano<100){
                    *ano+=2000;
                }

            }
DiasMesesAnos q2(char datainicial[], char datafinal[])
{

    //calcule os dados e armazene nas três variáveis a seguir
    DiasMesesAnos dma;

    if (q1(datainicial) == 0){
      dma.retorno = 2;
      return dma;
    }else if (q1(datafinal) == 0){
      dma.retorno = 3;
      return dma;
    }else{
         int diaini, mesini, anoini;
    int diafin,mesfin, anofin;
    int qntd,qntm,qnta;
    
            pegardata(datainicial ,&diaini, &mesini, &anoini);
            pegardata(datafinal ,&diafin, &mesfin, &anofin);
                    if (anoini>anofin){
                        dma.retorno = 4;
                        return dma; 
                    }
                   else if (anoini==anofin && mesini>mesfin){
                        dma.retorno = 4;
                        return dma; 
                    }
                    else if (anoini==anofin && mesini==mesfin && diaini>diafin){
                      dma.retorno = 4;
                        return dma;         
                    }
                    else{
                        qntd= diafin-diaini;
                        qntm= mesfin-mesini;
                        qnta= anofin-anoini;
                        int diadomesanterior, mesanterior=mesfin-1, anoanterior=anofin;
                            if(qntd<0){
                                qntm--;
                            
                            if (mesanterior==0){
                                mesanterior=12;
                                anoanterior--;
                            }
                            if(mesanterior==1 || mesanterior==3 || mesanterior==5 || mesanterior==7 || mesanterior==8 || mesanterior==10 || mesanterior==12){
                                diadomesanterior=31;
                            }
                            else if (mesanterior==4 || mesanterior==6 || mesanterior==9 || mesanterior==11){
                                diadomesanterior=30;
                            }
                           int bissexto = (anoanterior % 4 == 0 && anoanterior % 100 != 0) || (anoanterior % 400 == 0);
                                if (mesanterior == 2) {
                                    if (bissexto) {
                                        diadomesanterior = 29;
                                    } else {
                                        diadomesanterior = 28;
                                    }
                                }
                        
                        qntd+=diadomesanterior;
                            }
                            if (qntm<0){
                                qntm+=12;
                                qnta--;
                            }
                                    dma.qtdDias = qntd;
                                    dma.qtdMeses = qntm;
                                    dma.qtdAnos = qnta;
                                    dma.retorno=1;
                                    return dma;
                    
                        }
      
    }
    
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    for (int i=0; texto[i] != '\0'; i++){
         if(isCaseSensitive ==1 && texto[i] == c){
            qtdOcorrencias++;
         } else if(isCaseSensitive != 1 && (texto[i] == c || texto[i] == c + 32 || texto[i] == c - 32)){
            qtdOcorrencias++;
         }
    }
   
    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int qtdOcorrencias = 0;
    int c1=0, c2=0;
    for (int i=0; strBusca[c1] != '\0'; i++){
            c1++;
    }

  for (int i=0; strTexto[i] != '\0'; i++){
    int achou = 1;
    for (int j=0; strBusca[j] != '\0'; j++){    
        if (strBusca[j] != strTexto[i+j]){
            achou = 0;
            break;
        }
    }
        if(achou==1){
            posicoes[qtdOcorrencias*2]= i+1;
            posicoes[qtdOcorrencias*2+1]= i+c1;
            qtdOcorrencias++;
}
    
  }
    return qtdOcorrencias;
}


/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{
    int contador =0;
    int v[10];
    int p = num;
 while(p >0){
    p=p/10;
    contador++;    
 }
 for(int i=0; i<contador;i++){
    v[i]=num%10;
    num=num/10;
 }
 num=0;
 for (int i=0;i<=contador-1; i++){
    num=num*10+v[i];
 }
    return num;
}

/*
 Q6 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int v[15], v2[15];
    int c1 = 0, c2 = 0;
    int qtdOcorrencias = 0;

   
    if (numerobase == 0) {
        v[0] = 0;
        c1 = 1;
    } else {
        while (numerobase > 0) {
            v[c1] = numerobase % 10;
            c1++;
            numerobase /= 10;
        }
        for (int i = 0; i < c1 / 2; i++) {
            int aux = v[i];
            v[i] = v[c1 - 1 - i];
            v[c1 - 1 - i] = aux;
        }
    }

    if (numerobusca == 0) {
        v2[0] = 0;
        c2 = 1;
    } else {
        while (numerobusca > 0) {
            v2[c2] = numerobusca % 10;
            c2++;
            numerobusca /= 10;
        }
        // Inverte v2 para ficar na ordem normal
        for (int i = 0; i < c2 / 2; i++) {
            int aux = v2[i];
            v2[i] = v2[c2 - 1 - i];
            v2[c2 - 1 - i] = aux;
        }
    }


    for (int i = 0; i <= c1 - c2; i++) {
        int achou = 1;
        for (int j = 0; j < c2; j++) {
            if (v[i + j] != v2[j]) {
                achou = 0;
                break;
            }
        }
        if (achou == 1) {
            qtdOcorrencias++;
        }
    }

    return qtdOcorrencias;
}

/*
 Q7 = jogo busca palavras
 @objetivo
    Verificar se existe uma string em uma matriz de caracteres em todas as direções e sentidos possíves
 @entrada
    Uma matriz de caracteres e uma string de busca (palavra).
 @saida
    1 se achou 0 se não achou
 */

 int q7(char matriz[8][10], char palavra[5])
 {
     int achou;
     return achou;
 }



DataQuebrada quebraData(char data[]){
  DataQuebrada dq;
  char sDia[3];
	char sMes[3];
	char sAno[5];
	int i; 

	for (i = 0; data[i] != '/'; i++){
		sDia[i] = data[i];	
	}
	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sDia[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }  
	

	int j = i + 1; //anda 1 cada para pular a barra
	i = 0;

	for (; data[j] != '/'; j++){
		sMes[i] = data[j];
		i++;
	}

	if(i == 1 || i == 2){ // testa se tem 1 ou dois digitos
		sMes[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }
	

	j = j + 1; //anda 1 cada para pular a barra
	i = 0;
	
	for(; data[j] != '\0'; j++){
	 	sAno[i] = data[j];
	 	i++;
	}

	if(i == 2 || i == 4){ // testa se tem 2 ou 4 digitos
		sAno[i] = '\0';  // coloca o barra zero no final
	}else {
		dq.valido = 0;
    return dq;
  }

  dq.iDia = atoi(sDia);
  dq.iMes = atoi(sMes);
  dq.iAno = atoi(sAno); 

	dq.valido = 1;
    
  return dq;
}