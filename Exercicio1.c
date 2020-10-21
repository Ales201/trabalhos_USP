//Grupo 1
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX 10

//funcao para a ordenacao pelo metodo quicksort a ser realizado pelo filho
void quickSort(int valor[], int esquerda, int direita){

    int i, j,x,y;

    i=esquerda;
    j=direita;
    x = valor[(esquerda + direita) / 2];

    while(i <= j){
        while(valor[i] < x && i < direita){
            i++;
        }
        while(valor[j] > x && j > esquerda){
            j--;
        }
        if(i <= j){
            y = valor[i];
            valor[i] = valor[j];
            valor[j] = y;
            i++;
            j--;
        }
    }
    if (j > esquerda){
        quickSort(valor, esquerda, j);
    }
    if (i < direita){
        quickSort(valor,i,direita);
    }

}

//ordenacao pelo metodo selection sort a ser realizado pelo main
void ordemSimples (int valor[], int tamanho){
    int i,j,min,aux;

    for(i = 0; i < (tamanho-1); i++){
        min = i;
    for(j = (i+1); j < tamanho; j++){
        if(valor[j] < valor[min])
            min = j;

    }
    if (i != min){
        aux = valor[i];
        valor [i] = valor[min];
        valor[min] = aux;
        }
    }

}

void main(){

    clock_t c1, c2; //variaveis que contam o ciclo do processo
    float tmp;
    int i;
    int n[MAX];
    pid_t rgPid;

//primeiro passo, inserir 10 numeros desordenados no vetor
    for(i = 0; i < MAX; i++){
        printf("insira um numero no vetor: ");
        scanf("%d",&n[i]);
    }

//criando um fork



//verificando se o fork nao esta com erro

if((rgPid = fork()) < 0 ){ //criando e testando o fork
    printf("o fork contem erro!");
    exit(1);
}

// processo filho

    if(rgPid == 0){
        c1 = clock();
        quickSort(n,0,MAX-1); //codigo a ser executado
        c2 = clock();
        tmp = (float) (c2 - c1)*1000/CLOCKS_PER_SEC; //tempo de execucao em milissegundos

    printf("o tempo gasto para executar, pelo filho, foi de : %f ms\n", tmp);

    for(i = 0; i < MAX ; i++){
        printf("vetor ordenado pelo filho: %d\n",n[i]);
    }
} else{ //agora para o processo pai (rgPid != 0)
    waitpid(rgPid,0,0); //deve esperar o filho acabar
    c1 = clock();
    ordemSimples(n,MAX); //codigo  ser executado
    c2 = clock();
    tmp = (float) (c2 - c1)*1000/CLOCKS_PER_SEC; //tempo de execucao em milissegundos

    printf("o tempo gasto para executar, pelo pai, foi de: %f ms\n",tmp);

    for(i = 0; i < MAX; i++){
        printf("vetor ordenado pelo pai: %d\n",n[i]);
    }

}


}
