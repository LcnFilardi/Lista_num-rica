#include<stdio.h>
#include<stdlib.h>

typedef struct no {
	
	int valor;
	struct no *prox;
}tipoNo;

typedef struct pilha{
	
	tipoNo *inicio;
}tipoPilha;

void iniciar(tipoPilha *p){
	
	p->inicio = NULL;
}

void inserir(tipoPilha *p, int valor){
	
	tipoNo* noh = (tipoNo*)malloc(sizeof(tipoNo));
	
	noh->valor = valor;
	noh->prox = p->inicio;
	p->inicio = noh;
}

int remover(tipoPilha *p){
	
	tipoNo *noh;
	int valor;
	
	if(p->inicio == NULL){
		
		printf("A pilha está vazia!\n");
		return -1;
	}
	
	noh = p->inicio;
	p->inicio = noh->prox;
	valor = noh->valor;
	
	free(noh);
	
	return valor;
}

void inverter(tipoPilha *p){
	
	tipoNo *prev = NULL;
	tipoNo *atual = p->inicio;
	tipoNo *proximo;
	
	while(atual != NULL){
		
		proximo = atual->prox;
		atual->prox = prev;
		prev = atual;
		atual = proximo;
		
	}
	p->inicio = prev;
}


void imprimir(tipoPilha *p){
	
	tipoNo *imp = p->inicio;
	
	printf("Lista: (");
	
	while(imp != NULL){
		
		printf("%d", imp->valor);
		
		imp = imp->prox;
		
		if( imp!= NULL){
			
			printf(" , ");
		}
	}
	printf(")\n\n");
}


int main(){
	
	tipoPilha pi;
	
	int valor, escolha;
	
	iniciar(&pi);
	
	do{
		
		printf("\nMenu: \n");
		printf("1- Inserir elemento.\n");
		printf("2- Remover elemento.\n");
		printf("3- Inverter lista.\n");
		printf("4- Imprimir lista.\n");
		printf("5- Finalizar.\n");
		printf("Digite sua escolha: ");
		scanf("%d", &escolha);
		
		switch(escolha){
			
			case 1:
				printf("Digite o valor que deseja inserir: ");
				scanf("%d", &valor);
				inserir(&pi, valor);
				break;
				
			case 2: 
				printf("\nUltimo valor removido!");
				valor = remover(&pi);
				break;
				
			case 3:
				printf("Lista Invertida: ");
				inverter(&pi);
				break;
				
			case 4:
				imprimir(&pi);
				break;
				
			case 5:
				printf("\nFIM DO PROGRAMA!");
				return 0;
				break;
				
			default:
				printf("\nERRO! Digite novamente uma opcao.");
				
				
		}
	} while(escolha != 5);
	
	return 0;

}
