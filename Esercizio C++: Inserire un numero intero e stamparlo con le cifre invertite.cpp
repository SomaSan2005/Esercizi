#include <string>

#include <iostream>

#include<cmath>		// per la funzione pow()using namespace std;

int numerocifre(int long num)

{

	//calcolo il numero di cifre

	int cifre=0;

	while (num>0) {

        num /= 10;

        cifre++;

    }

    return cifre;

}

long inverso(int long num, int nc)

{

	int cifra;

	int v[nc];

	int long temp=num;

	for(int i=nc;i!=0;i--){

		cifra=(int)(temp/pow(10,i-1));

		temp-=cifra*pow(10,i-1);

		v[i-1]=cifra;		

	}

	long risultato=0;	

	for(int i=0;i<nc;i++){

		risultato+=v[i]*pow(10,nc-i-1);

	}

	return risultato;

}

int main(){

  char continui='S';

  while(continui!='N' && continui!='n'){

  	system("CLS");

	cout<<"Invertire le cifre di un numero intero";

	int long numero;

	do{

		cout<<"\n\nNumero intero positivo: ";

		cin>>numero;

	}while(numero<0);

	int cifre=numerocifre(numero);//calcolo il numero di cifre

	cout<<"Inverso del numero "<<numero<<": "<<inverso(numero,cifre);

	cout<<"\n\nContinui? ";

    cin>>continui;

  } // chiude while()-------------------------

} // chiude main()--------
