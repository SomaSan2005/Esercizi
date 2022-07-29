#include <string>
#include <iostream>
#include<cmath>		// per la funzione pow()
using namespace std;
string numeri1_19[] = { 
    "","uno", "due", "tre", "quattro", "cinque","sei", "sette", "otto", "nove", "dieci", "undici", 
	"dodici", "tredici", "quattordici","quindici", "sedici", "diciassette", "diciotto","diciannove" };
string decine[] = { "", "", "venti", "trenta", 
    "quaranta", "cinquanta", "sessanta", "settanta", "ottanta", "novanta" };
string centinaia[] = { "", "cento", "duecento", "trecento","quattrocento", "cinquecento", "seicento", 
	"settecento", "ottocento",  "novecento" }; 
int v[8];   //array contenente le cifre che compongono il numero fornito in input

string dec_uni(int d, int u)//decine-unità
{
	int vv=d*10+u;
	if(vv<20) return numeri1_19[vv];
	if (u==1  || u==8) 	return(decine[d].substr(0,decine[d].length()-1))+numeri1_19[u];//per scrivere ad es.ventuno e non ventiuno
	return decine[d]+numeri1_19[u];
}

string convertiinlettere (int num)
{
   if(num<20) return numeri1_19[num];
   //calcolo il numero di cifre nc 
   	int nc=0;
   	int long temp=num;
	while (temp>0) {
        temp /= 10;
        nc++;
    }
   temp=num;
   int cifra;
     // costruisco l'array contenente le cifre che compongono il numero
	for(int i=nc;i!=0;i--){
		cifra=(int)(temp/pow(10,i-1));
		temp-=cifra*pow(10,i-1);
		v[i-1]=cifra;		
	} 
	string mila,milioni;
	switch(nc)
	{
		case(2): //decine-unità
			return dec_uni(v[1],v[0]);
		case(3)://centinaia-decine-unità
				return centinaia[v[2]]+dec_uni(v[1],v[0]);
		case(4)://migliaia-centinaia-decine-unità
			if(num<2000) return "mille"+centinaia[v[2]]+dec_uni(v[1],v[0]);	
			return numeri1_19[v[3]]+"mila"+centinaia[v[2]]+dec_uni(v[1],v[0]);
		case(5)://decine di migliaia-centinaia-decine-unità
			return dec_uni(v[4],v[3])+"mila"+centinaia[v[2]]+dec_uni(v[1],v[0]);
		case(6)://centinaia di migliaia-centinaia-decine-unità
			return centinaia[v[5]]+dec_uni(v[4],v[3])+"mila"+centinaia[v[2]]+dec_uni(v[1],v[0]);
		case(7)://milioni-migliaia_centinaia-decine-unità
			milioni=numeri1_19[v[6]]+"milioni";
			if (v[6]==1)milioni="unmilione";
			mila=centinaia[v[5]]+dec_uni(v[4],v[3])+"mila";
			if(v[5]==0 && v[4]==0 && v[3]==0) mila="";
			if (v[5]==0 && v[4]==0 && v[3]==1) mila="mille";
			return milioni+mila+centinaia[v[2]]+dec_uni(v[1],v[0]);
		case(8)://decine di milioni-migliaia-centinaia-decine-unità
			milioni=dec_uni(v[7],v[6])+"milioni";
			mila=centinaia[v[5]]+dec_uni(v[4],v[3])+"mila";
			if(v[5]==0 && v[4]==0 && v[3]==0) mila="";
			if (v[5]==0 && v[4]==0 && v[3]==1) mila="mille";
			return milioni+mila+centinaia[v[2]]+dec_uni(v[1],v[0]);	
	}
}
                
                
int main()
{
    long int numero; 			// numero in input
    string numlettere="";  		// numero convertito in lettere
	long int mv=99999999; 		// massimo valore mv che si può fornire in input: 99999999
	char continui='s';
   	while(continui!='n'&& continui!='N')
	{
   		system("CLS");	
   		cout<<"Conversione di numeri in lettere";
   		cout<<"\nIl numero fornito in input deve essere compreso tra 0 99999999";
	  	do{	
			cout<<"\n\nInserisci il numero [0-9999999]: ";
        	cin >> numero;
		}while(numero<0  or numero>mv);	
		numlettere=convertiinlettere(numero);
		cout<<"\nNumero: "<< numero<<"\nIn lettere: "<<numlettere;
		cout<<"\n\nContinui? ";
		cin>>continui;
	}
}  
