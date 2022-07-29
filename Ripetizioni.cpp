#include<iostream>

#include <stdlib.h>	/*srand() - rand()*/#include<ctime> 	/* time()*/

#define n 30

using namespace std;

int main()

{

  char ripeti='S';

  while(ripeti!='N' && ripeti!='n'){

  	system("CLS");

	srand((unsigned)time(NULL));

	/* la funzione srand() serve per generare numeri casuali ogni volta diversi:

     * time() restituisce un valore che varia ogni volta e quindi il numero generato

	 * varia per ogni chiamata rand()

	*/

	int arr[n];

	for(int i=0;i<n;i++){

		//viene generato un valore random compreso tra 40 valori(da 1 a 40) a partire da 1

		arr[i]=rand() % 40 + 1;

	}

	// ordino l'array arr in senso crescente

	for(int i=0;i<n;i++)

	{		

		for(int j=i+1;j<n;j++)

		{

			if(arr[j]<arr[i])

			{

				int temp  =arr[i];

				arr[i]=arr[j];

				arr[j]=temp;

			}

		}

	}

	// visualizzo l'array arr  ordinato in senso crescente in righe di 5 elementi ciascuna

	cout<<"Array generato in modo random e ordinato in senso crescente\n";

	int k=0;

	for(int i=0;i<n;i++)

	{

		cout<<arr[i]<<"\t";

		k++;

		if(k==5){

			k=0;

			cout<<"\n";

		}

	}

	// visualizzo gli elementi che sono stati generati piĂą volte	

	cout<<"\nElementi che si ripetono:\n";

	for(int i=0;i<n-1;)

	{

		if(arr[i]==arr[i+1]){

			int temp=arr[i];

			while(temp==arr[i]){

				i++;

			}

			cout<<temp<<"\t";

		}

		else i++;

	}

	cout<<"\n\nRipeti? ";

    cin>>ripeti;

	

  } // chiude while()------------------------------------

}// chiude main--------------------------------------------------------
