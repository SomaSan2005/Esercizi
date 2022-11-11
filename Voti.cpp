//Nicodemo Andreoli
#include<iostream>
using namespace std;
int main()
{
     int garaA[20]={};
     int garaB[20]={};
     int theBest[40]={};
     float mediaA=0;
     float mediaB=0;
     int sommaA=0;
     int sommaB=0;
     int k=0;
     int a=0;
     cout<<"inserisci in ordine i voti della prima gara"<<endl;
     for(int i=0; i<20; i++)
     {
     	cin>>garaA[i];
     	sommaA+=garaA[i];
	 }
	 cout<<"inserisci in ordine i voti della seconda gara"<<endl;
	 for(int i=0; i<20; i++)
	 {
	 	cin>>garaB[i];
	 	sommaB+=garaB[i];
	 }
	 mediaA=sommaA/20;
	 mediaB=sommaB/20;
	 for(int i=0; i<20; i++)
	 {
	 	if(garaA[i]>=mediaA)
	 	{
	 		cout<<"i migliori sono:"<<garaA[i]<<endl;
	 			theBest[k]=garaA[i];
	 			k++;
			
		 }
		 else if(garaB[i]>=mediaB)
		 {
		 	cout<<"i migiori sono: "<<garaB[i]<<endl;
		 	theBest[k]=garaB[i];
		 	k++;
		 }
		 else if(garaA[i]>=mediaA && garaB[i]>=mediaB)
		 {
		 	cout<<"i migliori sono: "<<garaA<<" "<<garaB<<endl;
		 	theBest[k]=garaA[i];
		 	theBest[k+1]=garaB[i];
		 	k++;
		 }
		 a=garaA[2];
		 for(int i=1; i<20;i++)
		 {
		 	garaA[i+1]=garaA[i];
			 	
		 }
		 garaA[2]=a;
	 }
	 
	return 0;
}
