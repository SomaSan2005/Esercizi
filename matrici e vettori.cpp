include <iostream>

#include <stdlib.h>	//srand() - rand()#include<ctime> 	// time()

#define nr 6		//nr numero righe

#define nc 6		//nc numero colonne

using namespace std;

int MAT[nr][nc];

int main()

{

  char continui='S';

  while(continui!='N' && continui!='n'){

  	system("CLS");

	srand((unsigned)time(NULL));

	/* la funzione srand() serve per generare numeri casuali ogni volta diversi:

     * time() restituisce un valore che varia ogni volta e quindi il numero generato

	 * varia per ogni chiamata rand()

	*/

	

	// genera la matrice MAT e ne calcola la media M

	float somma=0; 

	for(int i=0;i<nr;i++){

		for(int j=0;j<nc;j++){

			//genera un valore random compreso tra 500 valori(da 1 a 500) a partire da 1

			MAT[i][j]=rand()%500 +1;

			somma+=MAT[i][j];

		}

	}

	float M=(float)somma/(nr*nc);

	float M1=M-M*0.2;	//Media -20%

	float M2=M+M*0.2;	//Media +20%

	

	// visualizza la matrice generata e costruisce il vettore VET

	cout<<"Matrice:";

	int VET[nr*nc]; 

	int k=0;

	for(int i=0;i<nr;i++){

		cout<<"\n";

		for(int j=0;j<nc;j++){

				cout<<"\t"<<MAT[i][j];

				if(MAT[i][j]%2==0 && MAT[i][j]>M1 && MAT[i][j]<M2 ) {

					VET[k]=MAT[i][j];

					k++;

				}

		}

	}

	// stampa i valori di M, M1 e M2 

	cout<<"\n\nMedia M:"<<M<<"\t\tMedia-20% M1:"<<M1<<"\tMedia+20% M2:"<<M2;

	// stampa il vettore VET

	cout<<"\n\nVettore VET con gli elementi della matrice MAT che sono  pari e\nsi discostano non piu' del 20% dal valore della  media "<<M<<"\n";

	for(int i=0;i<k;i++){

		cout<<"\t"<<VET[i];

	}

    cout<<"\n\nContinui? ";

    cin>>continui;

  } // chiude while()-------------------------

} // chiude main()------------------------
