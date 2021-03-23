#include <stdio.h>
#include<stdlib.h>
#include<conio.h>
#define COL 10
#define ROW 50
#define FALSE 0
#define TRUE 1

void inicializa(char matriz[ROW][COL]);
void mostrarPainel(char matriz[ROW][COL]);
void comprar(char matriz[ROW][COL]);
void reservar(char matriz[ROW][COL]);
void legenda();
int menuOpcao();
int colunaY();
int linhaX();

int main (void){
  char matriz[ROW][COL];
  int opcao;
  int loopContinue=TRUE;

  inicializa(matriz); //Inicializa a matriz com valores .(Livre)

  do{
     opcao=menuOpcao();
     switch(opcao){
        case 1:
          mostrarPainel(matriz);//Mostra o Painel atualizado
          comprar(matriz); // Realiza a compra de uma cadeira no painel, marcando c/ um X
          break;

   case 2:
         mostrarPainel(matriz);
          reservar(matriz); //Realiza a reserva de uma cadeira no painel, marcando c/ um R
          break; case 3:
          system("cls");
          mostrarPainel(matriz);
          getch();
          break;

        case 4:
          loopContinue = FALSE; //condicao para saída do programa
     }
  }while(loopContinue);

  getchar();
  return 0;
}
void inicializa(char matriz[ROW][COL]){
     int i,j;
     for(i=1;i<=ROW;i++)
       for(j=1;j<=COL;j++)
          matriz[i][j] = '.';
}

void mostrarPainel(char matriz[ROW][COL]){

  int i,j;
  printf("\n\n    %c   OCUPATION PANEL %c\n\n",16,17);
  printf("          ");

  for(i=1;i<=COL;i++)
    printf("%d     ",i);

  for(i=1;i<=ROW;i++){
     printf("\n\n     %d",i);
     for(j=1;j<=COL;j++)
       printf("   (%c)",matriz[j]);
  }
  //apresenta o menu na tela
  legenda();
}

int menuOpcao(){
    int opcao=4;
    do {
         system("cls");
         printf("\n\n                    %c  MENU  %c\n\n",16,17);

         printf("                %c  1- Buy        %c\n",16,17);

         printf("                %c  2- Reserve       %c\n",16,17);

         printf("                %c  3- Show Panel  %c\n",16,17);

         printf("                %c  4- Exit           %c\n\n",16,17);

         printf("                   opcao: ");scanf("%d",&opcao);

         if(opcao <= 0 || opcao > 4){
            printf("\n\n\n    DIGITE APENAS VALORES CORESPONDENTES AO MENU !!");
            getch();
         }

     }while(opcao <= 0 || opcao > 4);

    return opcao;
}
//apresenta  a legenda na tela
void legenda(){
   printf("\n\n\n        .-Free  X-Ocuped  R-Reserved\n\n");

}
    //efetica a compra da cadeira
void comprar(char matriz[ROW][COL]){
   int row, col;
   printf("\n           Buy a chair\n\n");
   row = linhaX();
   col = colunaY();

   if(matriz[row][col]=='.'){
       matriz[row][col] = 'X';
       printf("\n\n      BUYD SUCCESSFULLY !!");
   }
   else if (matriz[row][col]=='X')
             printf("\n\n      BUSY CHAIR!! PICK OTHER !!\n\n");
        else if(matriz[row][col]=='R')
               printf("\n\n    RESERVED CHAIR!! PICK OTHER !!\n\n");

   getch();
}
//reserva a cadeira no teatro
void reservar(char matriz[ROW][COL]){
   int row, col;
    printf("\n\n         RESERVE CHAIRS\n\n");
   row = linhaX();
   col = colunaY();

   if(matriz[row][col]=='.'){
       matriz[row][col] = 'R';
       printf("\n\n      SUCESSFULLY RESERVED !!");
   }
   else if (matriz[row][col]=='X')
             printf("\n\n       BUSY CHAIR!! PICK OTHER!!\n\n");
        else if(matriz[row][col]=='R')
               printf("\n\n      RESERVED CHAIR!! PICK OTHER!!\n\n");

    getch();

}
//ler a linha oferecida pelo usuario
int linhaX(){
   int row;
   printf("          Line: "); scanf("%d",&row);
     if(row>50)
     {
       printf("\t\n This sit doen't exist!!! ");
       }
   return row;
}
//ler a coluna oferecida pelo usuario
int colunaY(){
   int col;
   printf("          Column: "); scanf("%d",&col);
   if(col>10)
     {
       printf("\t\nThis sit doen't exist!!! ");
       }
   return col;
}
