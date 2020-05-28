#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <ctype.h>

int getint(int *n) {
  int count=0;
  scanf("%d", n);
  while (getchar() != '\n') count++;
  return count == 0;
}

float getfloat(float *n) {
  int count=0;
  scanf("%f", n);
  while (getchar() != '\n') count++;
  return count == 0;
}

int m;

void leitura_matriz(float matriz[m][m]){

	int i, j, ok=0;
	
	printf("\nDigite os valores para a matriz A: \n");
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			do {
				printf("a[%i][%i] = ", i+1, j+1);
	     		ok = getfloat(&matriz[i][j]);
	     		if (!ok) printf("\nDigite novamente, aceitamos somente numero.\n");
	        } while (!ok);
		}
	}
	
}


float determinante(float matriz_det[m][m]){
	
	float det;
	//Calculando o determinante de uma matriz 3x3
         
	if(m == 3){
		det = (matriz_det[0][0]*matriz_det[1][1]*matriz_det[2][2]) + (matriz_det[0][1]*matriz_det[1][2]*matriz_det[2][0]) + (matriz_det[0][2]*matriz_det[1][0]*matriz_det[2][1])
		- ((matriz_det[0][1]*matriz_det[1][0]*matriz_det[2][2]) + (matriz_det[0][0]*matriz_det[1][2]*matriz_det[2][1]) + (matriz_det[0][2]*matriz_det[1][1]*matriz_det[2][0]));
	}
	
	if(m == 2){
		det = ((matriz_det[0][0]*matriz_det[1][1])-(matriz_det[0][1]*matriz_det[1][0]));
	}
	
	if(m == 1){
		det = matriz_det[0][0];
	}
	
	return(det);
}

void verificacao(float matriz[m][m], int op){
	
	int i,j;
	
	// Vendo se é possivel a decomposição: 
		
	if(op == 3){
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				if(matriz[i][j]!=matriz[j][i]){
					printf("Nao eh simetrico\n\n\n");
					system("pause");
					main();
 				}
			}
		}
	}
	
	if(determinante(matriz)==0){
		printf("Nao eh possivel pois a determinante eh igual a 0\n\n");
		system("pause");
		main();
	}
	
	if(op == 3){
		printf("Eh simetrico com determinante diferente de 0, eh possivel a resolucao\n\n");			
	}else{
		printf("A determinante eh diferente de 0, eh possivel a resolucao\n\n");
	}
	
}

void imprimir_matriz(float matriz[m][m]){
	
	int i, j;
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			printf("%.2f\t", matriz[i][j]);
			if(j==(m-1)){
				printf("\n");
			}
		}
	}
}

void leitura_matriz_b(float matriz[m][1]){

	printf("Digite valor para b: \n");
	
	int i, j;
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
				if(j==0){
					scanf("%f", &matriz[i][0]);
				}	
		}
	}
	
	printf("\n");
	
}

void acha_y(float matriz_b[m][1], float ypsilon[m][1], float c[m][m]){
	
	int f=0, i, j;
	float aux;
	
	for(i=0;i<m;i++){
		for(j=0;j<m;j++){
			
			if(i!=j){
				aux=aux+(c[i][j]*ypsilon[f][0]); 
			}
			f++;
			
			if(j==2){
				ypsilon[i][0]=(matriz_b[i][0]-aux)/(c[i][i]);
				f=0;
				aux=0;
			}
		}
	}
	
}

void acha_x(float xis[m][1], float ypsilon[m][1], float d[m][m]){
	
	int f=m-1, i1=0, i, j;
	float aux;
	
	for(i=m-1;i>=0;i--){
		for(j=0;j<m;j++){
			
			if(i!=j){
				aux=aux+(d[i][j]*xis[f][0]);
			}
			f--;
			
			if(j==2){
				xis[i1][0]=(ypsilon[i][0]-aux)/(d[i][i]);
				f=m-1;
				aux=0;
				i1++;
			}
		}
	}	
}

void imprimir_matriz_coluna(float matriz[m][1], int sla1){
	
	int i, j;
	
	
	if (sla1 == 2){
    	for(i=m-1;i>=0;i--){
			for(j=0;j<m;j++){
				 if(j==0){
					printf("%.2f \n", matriz[i][0]);
				 }	
			}
    	}
	}else{
	
    	for(i=0;i<m;i++){
		   for(j=0;j<m;j++){
				if(j==0){
					printf("%.2f \n", matriz[i][0]);
				}	
		    } 
    	}
    }
	
	
}


int main()
{
    //menu
    int opcao;
    inicio:
    system("cls");
    system("color B0");
    printf("\t ___________________________________________     ___________________________________________\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|        1- Calcular o Determinante         |   |        2- Calcular pelo Metodo LU         |\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|___________________________________________|   |___________________________________________|\n\n");
    printf("\t ___________________________________________     ___________________________________________\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|       3 - Calcular metodo Cholesky        |   |                 4 - Sair                  |\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|                                           |   |                                           |\n");
    printf("\t|___________________________________________|   |___________________________________________|\n");

    opcao = getch();
    switch (opcao) {
    case '1':{

        system("cls");
        
        int i,j, ok=0;

        do {
  	 		printf("Digite a dimensao da matriz quadrada: ");
     		ok = getint(&m);
     		if (!ok) printf("\nDigite novamente, aceitamos somente numero.\n");
        } while (!ok);
        
        if(m>3){
        	printf("\nSo conseguimos calcular a determinante de matrizes at� ordem 3.");
			system("pause");
			goto inicio;				
		}

        float a[m][m];
		
		leitura_matriz(a);
		
		system("cls");
		
		printf("Matriz A: \n");
		
		imprimir_matriz(a);
		
		printf("A determinante eh: %.2f\n\n", determinante(a));
		
		printf("Pressione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
        
        break;
	}
    case '2':{
	    system("cls");
	    int i,j, ok=0;

        do {
  	 		printf("Digite a dimensao da matriz quadrada: ");
     		ok = getint(&m);
     		if (!ok) printf("\nDigite novamente, aceitamos somente numero.\n");
        } while (!ok);

		float a[m][m], u[m][m], l[m][m];
		
		leitura_matriz(a);
		
		system("cls");
		
		printf("Matriz A: \n");
		
		imprimir_matriz(a);
		
		verificacao(a, opcao);
			
		//especifica��es
		
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				
				//matriz u
				if(i>j){
					u[i][j]=0;  // sempre quando i � maior que j o resultado � 0 ==> i>j=0
				}
				
				// matriz l
				if(i==j){
					l[i][j]=1; // a diagonal principal � 1
				}else if(i<j){
					l[i][j]=0; // pra cima da diagonal principal � 0
				}
			}
		}
		
		
		
		//separande em L e U
		
		int k;
		float  somau=0, somal=0;
		
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				
				//para U
				if(i<=j){
					for(k=0;k<i;k++){
						somau= somau + (l[i][k]*u[k][j]); //somatoria de U
					}
					u[i][j]= a[i][j] - somau; 
					somau = 0;
				}
				
				//para L			
				if(i>j){
					for(k=0;k<j;k++){
						somal= somal + (l[i][k]*u[k][j]); //somatoria de L
					}
					l[i][j]= (a[i][j] - somal)/u[j][j];
					somal=0;
				}	
					
				
			}
		}
		
		printf("\n");
		
		printf("Matriz L: \n");
		
		imprimir_matriz(l);
	
		printf("\n");
	
		printf("Matriz U: \n");
		
		imprimir_matriz(u);
		
		printf("\n");
		
		float b[m][1], y[m][1], x[m][1];
		
		leitura_matriz_b(b); 
		
		acha_y(b, y, l);
		
		int sla = 1;
		
		printf("Valores de y:\n");
		         
		imprimir_matriz_coluna(y, sla);
		
		printf("\n");
		
		sla = 2; 
		
		acha_x(x, y, u);
		
		printf("Valores de x:\n");
		         
		imprimir_matriz_coluna(x, sla);
		
        printf("Pressione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
	}
    case '3':{
    	system("cls");
        int i,j, ok;
        
        do {
  	 		printf("Digite a dimensao da matriz quadrada: ");
     		ok = getint(&m);
     		if (!ok) printf("\nDigite novamente, aceitamos somente numero.\n");
        } while (!ok);
		
		float a[m][m], g[m][m], gt[m][m];
		
		leitura_matriz(a);
		
		system("cls");
		
		printf("Matriz A: \n");
		
		imprimir_matriz(a);
		
		verificacao(a, opcao);
		
		// especifica��es
			
		for(j=0;j<m;j++){
			for(i=0;i<m;i++){
				
				if(i<j){
					g[i][j]=0; // toda a vez que i < j (a parte de cima da matriz) vai ser 0
				}
				
			}
		}
		
		int k;
		float  somadg=0, somadm=0;
		
		for(j=0;j<m;j++){
			for(i=0;i<m;i++){
				
				//para diagonal principal
				if(i==j){
					
					
				
					for(k=0;k<i;k++){
						somadg= somadg + pow(g[i][k],2);  //somatoria da formula
					}
					if(pow(a[i][i] - somadg, 0.5)>=0){
				    	g[i][i]= pow(a[i][i] - somadg, 0.5);
				    	somadg = 0; 
			     	}else{
			     		printf("\nNao passou pela verificacao\n");
						system("pause");
						goto inicio;	
					}
				}
				
				//para demais valores			
				if(i>j){
					for(k=0;k<j;k++){
						somadm= somadm + (g[i][k]*g[j][k]); //somatoria da formulas
					}
					g[i][j]= (a[i][j] - somadm)/g[j][j];
					somadm=0;
				}	
			}
		}
		
		//achnado Gt
		for(i=0;i<m;i++){
			for(j=0;j<m;j++){
				if(i<j){
					gt[i][j]=g[j][i];  // quando o i < j (parte de cima da diagonal) valor de Gtij=Gji
				}else if(i==j){
					gt[i][i]=g[i][i]; // as diagonais principais sao iguais
				}else if(i>j){
					gt[i][j]=0; // a parte de baixo da diagona � 0
				}
			}
		}
		
		printf("\n");
		
		printf("Matriz G: \n");
		
		imprimir_matriz(g);
	
		printf("\n");
	
		printf("Matriz Gt: \n");
		
		imprimir_matriz(gt);
		
		printf("\n");
		
		float b[m][1], y[m][1], x[m][1], aux=0;
		
		leitura_matriz_b(b); 
		
		acha_y(b, y, g);
		
		printf("Valores de y:\n");
		
		int sla= 1;         
		
		imprimir_matriz_coluna(y, sla);
		
		printf("\n");
		
		acha_x(x, y, gt);
		
		printf("Valores de x:\n");
		         
		imprimir_matriz_coluna(x, sla);
		
		printf("Pressione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
	}
        
    case '4':
        system("cls");
        printf("voce pediu para sair, pressione qualquer tecla para continuar.\n");
        break;
        
    default:
        printf("\nPor favor, escolha uma opcao valida de 1 a 4.\n");
        printf("Pressione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
    }
    
}
