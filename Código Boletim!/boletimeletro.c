#include <stdio.h>
#include <string.h>

int main (void){
    char disciplina[51]; //VARIÁVEL QUE IRÁ GUARDAR O NOME DA DISCIPLINA, DEVE CONTER NO MAXIMO 50 CARACTERES, NA STRING FICA 51 POR CAUSA DO '\0'
    int alunado; //VARIÁVEL PARA GUARDAR A QUANTIDADE DE ALUNOS NA TABELA
    // APRESENTAÇÃO DAS BOAS VINDAS COMO O PROBLEMA PEDE
    printf("\n*******************************************************************\n");
    printf("Olah, caros professores/estudantes! Sejam bem vindos ao portal.\n");
    printf("*******************************************************************\n\n");
    printf("Digite o nome da DISCIPLINA [max 50 caracteres]:\n");
    
    
    fgets(disciplina, 51, stdin);
        if(disciplina[strlen(disciplina) - 1] =='\n'){
            disciplina[strlen(disciplina) - 1] = '\0';
        }
    //LEITURA DO NOME DA DISCIPLINA, COMO PODE TER ESPAÇOS NESSE NOME USEI O FGETS, O IF APÓS A INSTRUÇÃO É PARA REMOVER O '\N'
    printf("Agora me informem a QUANTIDADE DE ALUNOS [max 30 alunos]:\n");
    scanf("%d", &alunado);
    //LEITURA DA QUANTIDADE DE ALUNOS, QUE O PROBLEMA CITA A QUANTIDADE MAXIMA

// ok

    int i;//VARIÁVEL PARA O FOR
    int matriculas[alunado];//ARRAY DE INTEIROS PARA ARMAZENAR AS MATRICULAS, O INDICE VAI SER ALUNADO POIS O NUMERO DE MATRÍCULAS DEPENDEM DA QUANTIDADE ALUNOS
    char nomes[alunado][31];//AQUI VAI SER UMA STRING QUE TBM DEPENDE DA QUANTIDADE DE ALUNOS, E TEM COMO MAXIMO: 30 CARACTERES POR NOME
    double nota1 [alunado];//AQUI TEMOS A PRIMEIRA NOTA DE CADA ALUNO PERCORRIDO NO ÍNDICE
    double nota2 [alunado];//AQUI TEMOS A SEGUNDA NOTA DE CADA ALUNO PERCORRIDO NO ÍNDICE 
//TODOS ESSES DEPENDEM DO NUMERO DE ALUNOS , PARA TAMBÉM FICAREM EQUIVALENTES, POR EXEMPLO:
//A MATRICULA DE INDICE 0, VAI AREMAZENAR O NOME DE INDICE 0, E AS NOTAS 1 E 2 DE INDICE 0, QUE NO CASO VAI SER O ALUNO 1
    
    for(i=0; i<alunado; i++){
        printf("Digite a MATRICULA no aluno %d [MAX 4 DIGITOS]:\n", i+1);//COMO O CONTADOR COMEÇA EM 0, COLOQUEI +1 PARA N PRINTAR ALUNO 0.
        scanf("%d%*c", &matriculas[i]);//leitura da matricula   CONFORME O INDICE DO FOR GIRA, %*C É PARA N CONTABILIZAR O '\N'
        printf("Digite agora o NOME do aluno: %d[Maximo 30 caracteres]\n", i+1);//SOLICITA O USUÁRIO A DIGITAR O NOME DO ALUNO DO RESPECTIVO INDICE DO FOR
        fgets(nomes[i], 31, stdin);//MAIS UMA VEZ IRÁ FAZER A LEITURA DE UMA STRING COM ESPAÇOS ENTRE OS NOMES, POR ISSO O USO DO FGETS
        if(nomes[i][strlen(nomes[i]) - 1] =='\n'){
            nomes[i][strlen(nomes[i]) - 1] = '\0';
        }
        //O IF SERVE PRA MAIS UMA VEZ N CONTABILIZAR O '\N' E SUBSTITUI-LO PELO '\0' QUE É O ULTIMO INDICE DA STRING
        printf("Digite agora a PRIMEIRA NOTA do aluno %d\n", i+1);
        scanf("%lf%*c", &nota1[i]);//LEITURA DA PRIMEIRA NOTA DO ALUNO CONFORME O INDICE
        printf("Digite agora a SEGUNDA NOTA do aluno %d\n", i+1);
        scanf("%lf%*c", &nota2[i]);//LEITURA DA SEGUNDA NOTA DO ALUNO CONFORME O INDICE
        
    }
    //cabeçalho fixo da tabela
    //ESTRUTURA DA TABELA CONFORME INDICA NO PROBLEMA
    printf("______________________________________________________________________________________________________________________________\n");
    printf("DISCIPLINA: %s\n", disciplina);
    printf("______________________________________________________________________________________________________________________________\n");
    printf("MATRICULA     |                     NOME                       |    NOTA 1   |    NOTA 2    |       MEDIA        |    SITUACAO\n");
    printf("______________________________________________________________________________________________________________________________\n");
    //CRIEI UM FOR IGUAL AO OUTRO PARA EXIBIR OQ FOI INSCRITO PELO USUÁRIO PARA CADA DEVIDO ALUNO, APENAS UM PRINTF COM OS DEVIDOS ESPAÇOS CERTOS, DA CERTO
    for(i=0; i<alunado; i++){
        char *situacao; //CRIAÇÃO DE UMA STRING CHAMADA SITUAÇÃO PAARA EXIBIR A SITUAÇÃO FINAL DO ALUNO
        double media;// CRIAÇÃO DE UMA VARIÁVEL MEDIA PARA QUE A PARTIR DELA O PROGRAMA EXIBA A SITUAÇÃO DO ALUNO
        media = (nota1[i]+nota2[i]) / (2);//MEDIA VAI SER IGUAL A NOTA 1 MAIS NOTA 2 DO RESPECTIVO INDICE DO FOR QUE JA FOI ARMAZENA LÁ EM CIMA DIVIDIDO POR 2
        if(media >= 7.0){//CONDIÇÃO PARA APROVAÇÃO É QUE A MÉDIA SEJA MAIOR OU IGUAL A 7
            situacao ="APROVADO";  //O ENDEREÇO DA STRING RECEBERÁ APROVADO E EXIBIRÁ ISSO NA TABELA
        }
        else{//CASO FOR MENOR QUE 7
            situacao = "REPROVADO"; //O ENDEREÇO DA STRING IRÁ RECEBER REPROVADO E EXIBIR NA TABELA
        }
    printf("%04d              %-30s                     %.1lf           %.1lf               %.1lf             %s\n", matriculas[i], nomes[i], nota1[i], nota2[i], media, situacao);
    //ESSA É A ORDEM DA "ORIGEM" DA TABELA, COMO O PROBLEMA "ORIENTA" A COLOCAR O %05D POIS SE TODOS OS ELEMENTOS DA MATRICULA FOREM 0, MESMO ASSIM ELE AINDA EXIBI, MAS EU COLOQUEI 4 PORQUE NO EXEMPLO DA MATRICULA ESTÁ SEMPRE 4 
    //O %-30S SIGNIFICA QUE A CADA LETRA ELE DIMINUI UM ESPAÇO PRA FICAR NA MESMA "CAIXINHA" DO PROXIMO NOME CONTABILIZANDO OS 30 CARACTERES
    //AS DEMAIS EXIBIÇÕES JA SÃO CORRIQUEIRAS QUE É O DO DOUBLE E O DA STRING, O DO DOUBLE EU DEFINI UMA CASA APÓS O . PARA EXIBIÇÃO, E A STRING %S PR´PRIA DELA
    printf("______________|________________________________________________|_____________|______________|____________________|____________\n");

    }
    printf("______________________________________________________________________________________________________________________________\n");


return 0;

}
