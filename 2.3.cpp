#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

int X[100];
int N;
int fact;
int op=0;
int **res_sw = new int*[N];

void Swap(int a,int b)
{
    int t=X[a];
    X[a]=X[b];
    X[b]=t;
}
int Generate(int k, int **res_sw)
{
    if (k==N)
    {
        for(int i=0;i<N;i++)
        {
        	res_sw[i][op]=X[i];
        }
        op++;
		//std::cout<<X[i]<<" ";
        //std::cout<<"\n";
    }
    else
    { 
        for(int j=k;j<N;j++)
        {
            Swap(k,j);
            Generate(k+1, res_sw);
            Swap(k,j);
        }
    }
    return **res_sw;
}

	int kon (int *a, int *b, int *c)   //получаем конъюнкцию
	{
	  for(int i=0;i<16;i++)    //aeyrwbz cxbnftn ry
	  {
		if((a[i]==1)&&(b[i]==1)){c[i]=1;}
		else{c[i]=0;}
	  }
	return *c;
	}

	int dis (int *a, int *b, int *c)  // получаем дизъюнкцию
	{
	  for(int i=0;i<16;i++)    //aeyrwbz cxbnftn ry
	  {
		if((a[i]==0)&&(b[i]==0)){c[i]=0;}
		else{c[i]=1;}
	  }

	return *c;
	}

	int imp (int *a, int *b, int *c) // получаем имплкацию
	{
	  for(int i=0;i<16;i++)    //aeyrwbz cxbnftn ry
	  {
		if((a[i]==1)&&(b[i]==0)){c[i]=0;}
		else{c[i]=1;}
	  }

	return *c;
	}

	int ekw (int *a, int *b, int *c)  //получаем эквивалентнсть
	{
	  for(int i=0;i<16;i++)    //aeyrwbz cxbnftn ry
	  {
		if(a[i]==b[i]){c[i]=1;}
		else{c[i]=0;}
	  }

	return *c;
	}

int main ()
{
	cout<<"Input number of formulas: "<<endl;   //вводим количество формул
	int num_f;
	cin>>num_f;
//----------------------------------------------------------------------------------------------
	int **res_arr = new int*[num_f];
	for(int i=0;i<num_f;i++)
	{
		res_arr[i]=new int[16];
	}

char musor[1];          //записываем какой-то мусор для норм работы проги
cin.getline(musor, 1);  //мусор тоже пишем сюда

	for(int z=0;z<num_f;z++)
	{

		cout<<"Start program"<<endl;
		
	cout<<endl;
	int **array = new int*[8];
	for(int i=0;i<8;i++)
	{
	  array[i]=new int[16];
	}

	/////////////////////////////////----заполняем начальный массив из 4 столбцов ↓
	for(int i=0;i<16;i++)
	{
	  for(int j=0;j<7;j++)
	  {
		array[j][i]=0;
	  }
	}
	for (int j=0;j<16;j+=2)
	{
	  int i=0;
	  array[3][j]=i;
	  i=1;
	  array[3][j+1]=i;
	}
	for (int j=0;j<16;j+=4)
	{
	  int i=0;
	  array[2][j]=i;
	  array[2][j+1]=i;
	  i=1;
	  array[2][j+2]=i;
	  array[2][j+3]=i;
	}
	for (int j=0;j<16;j+=8)
	{
	  int i=0;
	  array[1][j]=i;
	  array[1][j+1]=i;
	  array[1][j+2]=i;
	  array[1][j+3]=i;
	  i=1;
	  array[1][j+4]=i;
	  array[1][j+5]=i;
	  array[1][j+6]=i;
	  array[1][j+7]=i;
	}
	for (int j=0,k=15;j<8;j++,k--)
	{
	  int i=0;
	  array[0][j]=i;
	  i=1;
	  array[0][k]=i;

	}
	/////////////////////////////////----заполняем начальный массив из 4 столбцов ↑
	
	
	char str[40];   //  вводим формулу
	cout<<"Your formula should be written in this format: [-]A*(B*(C*D))"<<endl;
	cout<<"Where '*' - any logic operation, 'A,B,C,D' may be in any order"<<endl;
	cout<<"Use it to write logic operations:"<<endl;
	cout<<endl;
	cout<<"(i) Implication - '->'"<<endl;
	cout<<"(e) Equivalent  - '<->'"<<endl;
	cout<<"(k) Konjunction - '/\\'"<<endl;
	cout<<"(d) Disjunction - '\\/'"<<endl;
	cout<<"(o) Otricanie   - '-'"<<endl;
	cout<<"(n) Normal      - '+'"<<endl;
	cout<<endl;
	cout<<"input Your formula: ";
	cin.getline(str,40);

	char massN[4];
	int counter=0;
	
	int lon=strlen(str);
	char prov[lon];
	int u=0;
	if(str[0]!='-'){prov[0]='n'; u++;}
	
	//-B\\/(C<->(D||A))
	
for(int i=0;i<30;i++)
	{
	  if((str[i]=='/')&&(str[i+1]=='\\')){prov[u]='k'; u++;}
	  if((str[0]=='/')&&(str[i+1]=='\\')){prov[u]='k'; u++;}
	  if((str[i]=='\\')&&(str[i+1]=='/')){prov[u]='d'; u++;}
	  if((str[i-1]!='<')&&(str[i]=='-')&&(str[i+1]=='>')){prov[u]='i'; u++;}
	  if((str[i-1]=='<')&&(str[i]=='-')&&(str[i+1]=='>')){prov[u]='e'; u++;}
	  if(str[i]=='('){prov[u]=str[i]; u++;}
	  if(str[i]==')'){prov[u]=str[i]; u++;}
	  if(str[i]=='A'){prov[u]=str[i]; u++;}
	  if(str[i]=='B'){prov[u]=str[i]; u++;}
	  if(str[i]=='C'){prov[u]=str[i]; u++;}
	  if(str[i]=='D'){prov[u]=str[i]; u++;}
	  if((str[i]=='-')&&(str[i+1]!='>')&&(str[i-1]!='<')){prov[u]='o'; u++;}	  
	}	
	
	cout<<"Polnaya phormula:   ";
	cout<<endl;
	for(int i=0;i<12;i++)
	{
		cout<<prov[i]<<" ";
	}
	cout<<endl;
	cout<<"____________________________________________"<<endl;


///////////////////////////////////////////////////
	///////////////////////////////////////////
	///////////////////////////////////////
	//////////

	
	char lett[4]; //храним буквы подряд
	int let=0;
	for(int i=0;i<18;i++)
	{
	  if((str[i]=='A')||(str[i]=='B')||(str[i]=='C')||(str[i]=='D'))
	  {
		lett[let]=str[i];
		let++;
		if(let==4)
		{
		  break;
		}
	  }
	}
	cout<<"letters: ";
	for(int i=0;i<4;i++)
	{
		cout<<lett[i]<<" ";
	}
	cout<<endl;
	

	int counter2=0;
	int c1;
	int mc1[4];
	char b1=lett[0];
	if(b1=='A'){c1=0;counter2++;mc1[0]=c1;}
	if(b1=='B'){c1=1;counter2++;mc1[0]=c1;}
	if(b1=='C'){c1=2;counter2++;mc1[0]=c1;}
	if(b1=='D'){c1=3;counter2++;mc1[0]=c1;}
	int c2;
	char b2=lett[1];
	if(b2=='A'){c2=0;counter2++;mc1[1]=c2;}
	if(b2=='B'){c2=1;counter2++;mc1[1]=c2;}
	if(b2=='C'){c2=2;counter2++;mc1[1]=c2;}
	if(b2=='D'){c2=3;counter2++;mc1[1]=c2;}
	int c3;
	char b3=lett[2];
	if(b3=='A'){c3=0;counter2++;mc1[2]=c3;}
	if(b3=='B'){c3=1;counter2++;mc1[2]=c3;}
	if(b3=='C'){c3=2;counter2++;mc1[2]=c3;}
	if(b3=='D'){c3=3;counter2++;mc1[2]=c3;}
	int c4;
	char b4=lett[3];
	if(b4=='A'){c4=0;counter2++;mc1[3]=c4;}
	if(b4=='B'){c4=1;counter2++;mc1[3]=c4;}
	if(b4=='C'){c4=2;counter2++;mc1[3]=c4;}
	if(b4=='D'){c4=3;counter2++;mc1[3]=c4;}
	

	int null=0;
	int one=0;
	
	if(((prov[0]=='o')||(prov[0]=='n'))&&((prov[1]=='A')||(prov[1]=='B')||(prov[1]=='C')||(prov[1]=='D'))&&((prov[2]=='k')||(prov[2]=='d')||(prov[2]=='e')||(prov[2]=='i'))&&(prov[3]=='(')&&((prov[4]=='A')||(prov[4]=='B')||(prov[4]=='C')||(prov[4]=='D'))&&((prov[5]=='k')||(prov[5]=='d')||(prov[5]=='i')||(prov[5]=='e'))&&(prov[6]=='(')&&((prov[7]=='A')||(prov[7]=='B')||(prov[7]=='C')||(prov[7]=='D'))&&((prov[8]=='k')||(prov[8]=='d')||(prov[8]=='e')||(prov[8]=='i'))&&((prov[9]=='A')||(prov[9]=='B')||(prov[9]=='C')||(prov[9]=='D'))&&(prov[10]==')')&&(prov[11]==')')  )
	{	

	int caunt=0;
	for(int i=0;i<12;i++)
	{
		if(prov[i]=='o'){massN[caunt]=prov[i]; caunt++;}
		if(prov[i]=='n'){massN[caunt]=prov[i]; caunt++;}
		if(prov[i]=='k'){massN[caunt]=prov[i]; caunt++;}
		if(prov[i]=='d'){massN[caunt]=prov[i]; caunt++;}
		if(prov[i]=='e'){massN[caunt]=prov[i]; caunt++;}
		if(prov[i]=='i'){massN[caunt]=prov[i]; caunt++;}
	}
	cout<<"Formulas: ";
	for(int i=0;i<4;i++)
	{
		cout<<massN[i]<<" ";
	}
	cout<<endl;
	
	//В z1, z2, z3, z4 хранятся полследовательность формул
	char z1=massN[0];
	char z2=massN[1];
	char z3=massN[2];
	char z4=massN[3];






		cout<<"first variant";
		cout<<endl;

			if(z1=='o')

			//(-B\/C)<->(D/\A)
			//-B\/(C<->(D/\A))

			{
				cout<<endl;
				cout<<"A    "<<"B    "<<"C    "<<"D   "<<"-"<<lett[0]<<"   ";

				for(int i=0;i<16;i++)
				{
					if(array[c1][i]==0){array[4][i]=1;continue;}
					if(array[c1][i]==1){array[4][i]=0;continue;}
				}
				
				int E[16];  /// второй сравниваемый столбец
				int F[16];  /// первый сравниваемый столбец
				
				for (int i=0;i<16;i++)
				{
				  E[i]=array[c4][i];
				}
					
				for (int i=0;i<16;i++)
				{
				  F[i]=array[c3][i];
				}
				
				int result1[16];

//(-B\/C)<->(D/\A)
//-B\/(C<->(D/\A))
				
				if(z4=='k'){cout<<lett[2]<<"/\\"<<lett[3]<<"  "; kon(F,E,result1);}
				if(z4=='d'){cout<<lett[2]<<"\\/"<<lett[3]<<"  "; dis(F,E,result1);}
				if(z4=='i'){cout<<lett[2]<<"->"<<lett[3]<<"  "; imp(F,E,result1);}
				if(z4=='e'){cout<<lett[2]<<"<->"<<lett[3]<<"  "; ekw(F,E,result1);}

				for (int i=0;i<16;i++)
				{
				  array[5][i]=result1[i];
				}

				for (int i=0;i<16;i++)
				{
				  E[i]=array[5][i];
				}
				
				for (int i=0;i<16;i++)
				{
				  F[i]=array[c2][i];
				}
				
				if(z3=='k'){cout<<lett[1]<<"/\\"<<"f1  "; kon(F,E,result1);}
				if(z3=='d'){cout<<lett[1]<<"\\/"<<"f1  "; dis(F,E,result1);}
				if(z3=='i'){cout<<lett[1]<<"->"<<"f1  "; imp(F,E,result1);}
				if(z3=='e'){cout<<lett[1]<<"<->"<<"f1  "; ekw(F,E,result1);}

				for (int i=0;i<16;i++)
				{
				  array[6][i]=result1[i];
				}
				/////////////////////////////////////////////////////////-----пром результтат
				for (int i=0;i<16;i++)
				{
				  E[i]=array[6][i];
				}
					
				for (int i=0;i<16;i++)
				{
				  F[i]=array[4][i];
				}
				
				if(z2=='k'){cout<<"-"<<lett[0]<<"/\\f2"<<endl; kon(F,E,result1);}
				if(z2=='d'){cout<<"-"<<lett[0]<<"\\/f2"<<endl; dis(F,E,result1);}
				if(z2=='i'){cout<<"-"<<lett[0]<<"->f2"<<endl; imp(F,E,result1);}
				if(z2=='e'){cout<<"-"<<lett[0]<<"<->f2"<<endl; ekw(F,E,result1);}
				cout<<endl;
				for (int i=0;i<16;i++)
				{
				  array[7][i]=result1[i];
				}

				for(int i=0;i<16;i++)
				{
				  for(int j=0;j<8;j++)
				  {
				  	if(j==7)
				  	{
				  		if(array[j][i]==0)
				  		{
				  			null++;
				  		}
				  		if(array[j][i]==1)
				  		{
				  			one++;
				  		}
				  	}
					cout<<array[j][i]<<"    ";
					if(j==5)
					{
						cout<<"  ";
					}
					if(j==6)
					{
						cout<<"    ";
					}
				  }
				  cout<<endl;
				}


				cout<<"nulls: "<<null<<endl;
				cout<<"one: "<<one<<endl;


				for(int i=0;i<16;i++)
				{
					res_arr[z][i]=array[7][i];
				}
				/*
				cout<<endl;
				cout<<endl;
				cout<<z1<<z2<<z3<<z4<<endl;
				cout<<c1<<c2<<c3<<c4<<endl;
				cout<<endl;
				*/

			}
			
			if(z1=='n')
			{
				cout<<endl;
				cout<<"A    "<<"B    "<<"C    "<<"D   ";

				int E[16];  /// второй сравниваемый столбец
				int F[16];  /// первый сравниваемый столбец
				
				for (int i=0;i<16;i++)
				{
				  E[i]=array[c4][i];
				}
					
				for (int i=0;i<16;i++)
				{
				  F[i]=array[c3][i];
				}
				
				int result1[16];
				
				if(z4=='k'){cout<<lett[2]<<"/\\"<<lett[3]<<"  "; kon(F,E,result1);}
				if(z4=='d'){cout<<lett[2]<<"\\/"<<lett[3]<<"  "; dis(F,E,result1);}
				if(z4=='i'){cout<<lett[2]<<"->"<<lett[3]<<"  "; imp(F,E,result1);}
				if(z4=='e'){cout<<lett[2]<<"<->"<<lett[3]<<"  "; ekw(F,E,result1);}

				for (int i=0;i<16;i++)
				{
				  array[4][i]=result1[i];
				}

				for (int i=0;i<16;i++)
				{
				  E[i]=array[4][i];
				}
				
				for (int i=0;i<16;i++)
				{
				  F[i]=array[c2][i];
				}
				
				if(z3=='k'){cout<<lett[1]<<"/\\"<<"f1   "; kon(F,E,result1);}
				if(z3=='d'){cout<<lett[1]<<"\\/"<<"f1   "; dis(F,E,result1);}
				if(z3=='i'){cout<<lett[1]<<"->"<<"f1   "; imp(F,E,result1);}
				if(z3=='e'){cout<<lett[1]<<"<->"<<"f1   "; ekw(F,E,result1);}
				//D<->(B->(A\\/C))
				for (int i=0;i<16;i++)
				{
				  array[5][i]=result1[i];
				}
				/////////////////////////////////////////////////////////-----пром результтат
				for (int i=0;i<16;i++)
				{
				  E[i]=array[5][i];
				}
					
				for (int i=0;i<16;i++)
				{
				  F[i]=array[c1][i];
				}
				
				if(z2=='k'){cout<<lett[0]<<"/\\f2"<<endl; kon(F,E,result1);}
				if(z2=='d'){cout<<lett[0]<<"\\/f2"<<endl; dis(F,E,result1);}
				if(z2=='i'){cout<<lett[0]<<"->f2"<<endl; imp(F,E,result1);}
				if(z2=='e'){cout<<lett[0]<<"<->f2"<<endl; ekw(F,E,result1);}
				
				for (int i=0;i<16;i++)
				{
				  array[6][i]=result1[i];
				}

				for(int i=0;i<16;i++)
				{
				  for(int j=0;j<7;j++)
				  {
				  	if(j==6)
				  	{
				  		if(array[j][i]==0)
				  		{
				  			null++;
				  		}
				  		if(array[j][i]==1)
				  		{
				  			one++;
				  		}
				  	}
					cout<<array[j][i]<<"    ";
					if(j==4)
					{
						cout<<"  ";
					}
					if(j==5)
					{
						cout<<"    ";
					}
				  }
				  cout<<endl;
				}

				for(int i=0;i<16;i++)
				{
					res_arr[z][i]=array[6][i];
				}

				cout<<"nulls: "<<null<<endl;
				cout<<"one: "<<one<<endl;
				/*
				cout<<endl;
				cout<<endl;
				cout<<z1<<z2<<z3<<z4<<endl;
				cout<<c1<<c2<<c3<<c4<<endl;
				cout<<endl;
				*/
			}
	}


	if(((((prov[0]=='n')||(prov[0]=='o'))&&(prov[1]=='(')&&((prov[2]=='A')||(prov[2]=='B')||(prov[2]=='C')||(prov[2]=='D'))&&((prov[3]=='k')||(prov[3]=='d')||(prov[3]=='e')||(prov[3]=='i'))&&((prov[4]=='A')||(prov[4]=='B')||(prov[4]=='C')||(prov[4]=='D'))&&((prov[5]==')'))&&((prov[6]=='k')||(prov[6]=='d')||(prov[6]=='i')||(prov[6]=='e'))&&(prov[7]=='(')&&((prov[8]=='A')||(prov[8]=='B')||(prov[8]=='C')||(prov[8]=='D'))&&((prov[9]=='k')||(prov[9]=='d')||(prov[9]=='e')||(prov[9]=='i'))&&((prov[10]=='A')||(prov[10]=='B')||(prov[10]=='C')||(prov[10]=='D'))&&(prov[11]==')')))||((((prov[0]=='o')||(prov[0]=='n'))&&(prov[1]=='(')&&((prov[2]=='o'))&&((prov[3]=='A')||(prov[3]=='B')||(prov[3]=='C')||(prov[3]=='D'))&&((prov[4]=='k')||(prov[4]=='d')||(prov[4]=='e')||(prov[4]=='i'))&&((prov[5]=='A')||(prov[5]=='B')||(prov[5]=='C')||(prov[5]=='D'))&&((prov[6]==')'))&&((prov[7]=='k')||(prov[7]=='d')||(prov[7]=='i')||(prov[7]=='e'))&&(prov[8]=='(')&&((prov[9]=='A')||(prov[9]=='B')||(prov[9]=='C')||(prov[9]=='D'))&&((prov[10]=='k')||(prov[10]=='d')||(prov[10]=='e')||(prov[10]=='i'))&&((prov[11]=='A')||(prov[11]=='B')||(prov[11]=='C')||(prov[11]=='D'))&&(prov[12]==')'))))
	{

		

		int caunt=0;
		if(prov[2]!='o'){massN[caunt]='n'; caunt++;}
		for(int i=1;i<12;i++)
		{
			if(prov[i]=='o'){massN[caunt]=prov[i]; caunt++;}
			if(prov[i]=='k'){massN[caunt]=prov[i]; caunt++;}
			if(prov[i]=='d'){massN[caunt]=prov[i]; caunt++;}
			if(prov[i]=='e'){massN[caunt]=prov[i]; caunt++;}
			if(prov[i]=='i'){massN[caunt]=prov[i]; caunt++;}
		}
		cout<<"Formulas: ";
		for(int i=0;i<4;i++)
		{
			cout<<massN[i]<<" ";
		}
		cout<<endl;
		
		//В z1, z2, z3, z4 хранятся полследовательность формул
		char z1=massN[0];
		char z2=massN[1];
		char z3=massN[2];
		char z4=massN[3];
		cout<<endl;
		/*
		cout<<endl;
		cout<<z1<<z2<<z3<<z4<<endl;
		cout<<c1<<c2<<c3<<c4<<endl;
		cout<<endl;
		*/
		cout<<"second variant"<<endl;


		int arr1[2];     /// храним значения по приоритетам, где 5-высший. а 2 - низший.

		if(z2=='k'){arr1[0]=5;}
		if(z2=='d'){arr1[0]=4;}
		if(z2=='i'){arr1[0]=3;}
		if(z2=='e'){arr1[0]=2;}

		if(z4=='k'){arr1[1]=5;}
		if(z4=='d'){arr1[1]=4;}
		if(z4=='i'){arr1[1]=3;}
		if(z4=='e'){arr1[1]=2;}

		if(prov[2]=='o')
			{
				cout<<endl;
				cout<<"Orticanie"<<endl;
				cout<<endl;

				cout<<"A    "<<"B    "<<"C    "<<"D   "<<"-"<<lett[0]<<"   ";

				for(int i=0;i<16;i++)
				{
					if(array[c1][i]==0){array[4][i]=1;continue;}
					if(array[c1][i]==1){array[4][i]=0;continue;}
				}

				int F[16];  /// первый сравниваемый столбец
				int E[16];  /// второй сравниваемый столбец

				if((arr1[0]>arr1[1])||(arr1[0]==arr1[1]))
				{

					int result1[16];

					for (int i=0;i<16;i++)
					{
					  F[i]=array[4][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[c2][i];
					}
					
					if(z2=='k'){cout<<lett[0]<<"/\\"<<lett[1]<<"    "; kon(F,E,result1);}
					if(z2=='d'){cout<<lett[0]<<"\\/"<<lett[1]<<"    "; dis(F,E,result1);}
					if(z2=='i'){cout<<lett[0]<<"->"<<lett[1]<<"    "; imp(F,E,result1);}
					if(z2=='e'){cout<<lett[0]<<"<->"<<lett[1]<<"    "; ekw(F,E,result1);}

					for (int i=0;i<16;i++)
					{
					  array[5][i]=result1[i];
					}
//-------------------------------------------------------------
					for (int i=0;i<16;i++)
					{
					  F[i]=array[c3][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[c4][i];
					}
					
					if(z4=='k'){cout<<lett[2]<<"/\\"<<lett[3]<<"     "; kon(F,E,result1);}
					if(z4=='d'){cout<<lett[2]<<"\\/"<<lett[3]<<"     "; dis(F,E,result1);}
					if(z4=='i'){cout<<lett[2]<<"->"<<lett[3]<<"     "; imp(F,E,result1);}
					if(z4=='e'){cout<<lett[2]<<"<->"<<lett[3]<<"     "; ekw(F,E,result1);}

					for (int i=0;i<16;i++)
					{
					  array[6][i]=result1[i];
					}
//----------------------------------------------------

					for (int i=0;i<16;i++)
					{
					  F[i]=array[5][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[6][i];
					}
						
					
					if(z3=='k'){cout<<"f1/\\f2"; kon(F,E,result1);}
					if(z3=='d'){cout<<"f1\\/f2"; dis(F,E,result1);}
					if(z3=='i'){cout<<"f1->f2"; imp(F,E,result1);}
					if(z3=='e'){cout<<"f1<->f2"; ekw(F,E,result1);}
					
					for (int i=0;i<16;i++)
					{
					  array[7][i]=result1[i];
					}

						cout<<endl; 
						cout<<endl;

					for(int i=0;i<16;i++)
					{
					  for(int j=0;j<8;j++)
					  {

					  	if(j==6)
					  	{
					  		cout<<"    ";
					  	}
					  	if(j==7)
					  	{
					  		cout<<"     ";
					  	}
					  	if(j==7)
				  		{
					  		if(array[j][i]==0)
					  		{
					  			null++;
					  		}
					  		if(array[j][i]==1)
					  		{
					  			one++;
					  		}
				  		}
						cout<<array[j][i]<<"    ";
					  }
					  cout<<endl;
					}

				for(int i=0;i<16;i++)
				{
					res_arr[z][i]=array[7][i];
				}

				cout<<"nulls: "<<null<<endl;
				cout<<"one: "<<one<<endl;

				}

				if((arr1[0]<arr1[1])||(arr1[0]==arr1[1]))
				{

					int result1[16];

					for (int i=0;i<16;i++)
					{
					  F[i]=array[c3][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[c4][i];
					}
					
					if(z4=='k'){cout<<lett[2]<<"/\\"<<lett[3]<<"    "; kon(F,E,result1);}
					if(z4=='d'){cout<<lett[2]<<"\\/"<<lett[3]<<"    "; dis(F,E,result1);}
					if(z4=='i'){cout<<lett[2]<<"->"<<lett[3]<<"    "; imp(F,E,result1);}
					if(z4=='e'){cout<<lett[2]<<"<->"<<lett[3]<<"    "; ekw(F,E,result1);}

					for (int i=0;i<16;i++)
					{
					  array[5][i]=result1[i];
					}
//---------------------------------------------------
					for (int i=0;i<16;i++)
					{
					  F[i]=array[4][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[c2][i];
					}
					
					if(z2=='k'){cout<<lett[0]<<"/\\"<<lett[1]<<"     "; kon(F,E,result1);}
					if(z2=='d'){cout<<lett[0]<<"\\/"<<lett[1]<<"     "; dis(F,E,result1);}
					if(z2=='i'){cout<<lett[0]<<"->"<<lett[1]<<"     "; imp(F,E,result1);}
					if(z2=='e'){cout<<lett[0]<<"<->"<<lett[1]<<"     "; ekw(F,E,result1);}

					for (int i=0;i<16;i++)
					{
					  array[6][i]=result1[i];
					}
//----------------------------------------------------

					for (int i=0;i<16;i++)
					{
					  F[i]=array[5][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[6][i];
					}
						
					
					if(z3=='k'){cout<<"f1/\\f2"; kon(F,E,result1);}
					if(z3=='d'){cout<<"f1\\/f2"; dis(F,E,result1);}
					if(z3=='i'){cout<<"f1->f2"; imp(F,E,result1);}
					if(z3=='e'){cout<<"f1<->f2"; ekw(F,E,result1);}
					
					for (int i=0;i<16;i++)
					{
					  array[7][i]=result1[i];
					}
					cout<<endl;
					cout<<endl;
					for(int i=0;i<16;i++)
					{
					  for(int j=0;j<8;j++)
					  {
					  	if(j==6)
					  	{
					  		cout<<"    ";
					  	}
					  	if(j==7)
					  	{
					  		cout<<"     ";
					  	}
					  	if(j==7)
				  		{
					  		if(array[j][i]==0)
					  		{
					  			null++;
					  		}
					  		if(array[j][i]==1)
					  		{
					  			one++;
					  		}
				  		}
						cout<<array[j][i]<<"    ";
					  }
					  cout<<endl;
					}

				for(int i=0;i<16;i++)
				{
					res_arr[z][i]=array[7][i];
				}

				cout<<"nulls: "<<null<<endl;
				cout<<"one: "<<one<<endl;
				}
			}

		if(prov[2]!='o')
			{

				//(A->D)\/(C/\B)

				cout<<"Polozhitelnoe"<<endl;
				cout<<endl;
				cout<<"A    "<<"B    "<<"C    "<<"D   ";

				int F[16];  /// первый сравниваемый столбец
				int E[16];  /// второй сравниваемый столбец

				if((arr1[0]>arr1[1])||(arr1[0]==arr1[1]))
				{
					int result1[16];

					for (int i=0;i<16;i++)
					{
					  F[i]=array[c1][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[c2][i];
					}
					
					if(z2=='k'){cout<<lett[0]<<"/\\"<<lett[1]<<"     "; kon(F,E,result1);}
					if(z2=='d'){cout<<lett[0]<<"\\/"<<lett[1]<<"     "; dis(F,E,result1);}
					if(z2=='i'){cout<<lett[0]<<"->"<<lett[1]<<"     "; imp(F,E,result1);}
					if(z2=='e'){cout<<lett[0]<<"<->"<<lett[1]<<"     "; ekw(F,E,result1);}

					for (int i=0;i<16;i++)
					{
					  array[4][i]=result1[i];
					}
//---------------------------------------------------
					for (int i=0;i<16;i++)
					{
					  F[i]=array[c3][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[c4][i];
					}
					
					if(z4=='k'){cout<<lett[2]<<"/\\"<<lett[3]<<"    "; kon(F,E,result1);}
					if(z4=='d'){cout<<lett[2]<<"\\/"<<lett[3]<<"    "; dis(F,E,result1);}
					if(z4=='i'){cout<<lett[2]<<"->"<<lett[3]<<"    "; imp(F,E,result1);}
					if(z4=='e'){cout<<lett[2]<<"<->"<<lett[3]<<"    "; ekw(F,E,result1);}

					for (int i=0;i<16;i++)
					{
					  array[5][i]=result1[i];
					}
//----------------------------------------------------

					for (int i=0;i<16;i++)
					{
					  F[i]=array[4][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[5][i];
					}
						
					
					if(z3=='k'){cout<<"f1/\\f2"; kon(F,E,result1);}
					if(z3=='d'){cout<<"f1\\/f2"; dis(F,E,result1);}
					if(z3=='i'){cout<<"f1->f2"; imp(F,E,result1);}
					if(z3=='e'){cout<<"f1<->f2"; ekw(F,E,result1);}
					
					for (int i=0;i<16;i++)
					{
					  array[6][i]=result1[i];
					}
					cout<<endl;
					for(int i=0;i<16;i++)
					{
					  for(int j=0;j<7;j++)
					  {
					  	if(j==5)
					  	{
					  		cout<<"    ";
					  	}
					  	if(j==6)
					  	{
					  		cout<<"     ";
					  	}
					  	if(j==6)
				  		{
					  		if(array[j][i]==0)
					  		{
					  			null++;
					  		}
					  		if(array[j][i]==1)
					  		{
					  			one++;
					  		}
				  		}
						cout<<array[j][i]<<"    ";
					  }
					  cout<<endl;
					}

				for(int i=0;i<16;i++)
				{
					res_arr[z][i]=array[6][i];
				}

				cout<<"nulls: "<<null<<endl;
				cout<<"one: "<<one<<endl;

				}

				if((arr1[0]<arr1[1])||(arr1[0]==arr1[1]))
				{
					int result1[16];

					for (int i=0;i<16;i++)
					{
					  F[i]=array[c3][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[c4][i];
					}
					
					if(z4=='k'){cout<<lett[2]<<"/\\"<<lett[3]<<"     "; kon(F,E,result1);}
					if(z4=='d'){cout<<lett[2]<<"\\/"<<lett[3]<<"     "; dis(F,E,result1);}
					if(z4=='i'){cout<<lett[2]<<"->"<<lett[3]<<"     "; imp(F,E,result1);}
					if(z4=='e'){cout<<lett[2]<<"<->"<<lett[3]<<"     "; ekw(F,E,result1);}

					for (int i=0;i<16;i++)
					{
					  array[4][i]=result1[i];
					}
//---------------------------------------------------
					for (int i=0;i<16;i++)
					{
					  F[i]=array[c1][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[c2][i];
					}
					
					if(z2=='k'){cout<<lett[0]<<"/\\"<<lett[1]<<"    "; kon(F,E,result1);}
					if(z2=='d'){cout<<lett[0]<<"\\/"<<lett[1]<<"    "; dis(F,E,result1);}
					if(z2=='i'){cout<<lett[0]<<"->"<<lett[1]<<"    "; imp(F,E,result1);}
					if(z2=='e'){cout<<lett[0]<<"<->"<<lett[1]<<"    "; ekw(F,E,result1);}

					for (int i=0;i<16;i++)
					{
					  array[5][i]=result1[i];
					}
//----------------------------------------------------

					for (int i=0;i<16;i++)
					{
					  F[i]=array[4][i];
					}

					for (int i=0;i<16;i++)
					{
					  E[i]=array[5][i];
					}
						
					
					if(z3=='k'){cout<<"f1/\\f2"; kon(F,E,result1);}
					if(z3=='d'){cout<<"f1\\/f2"; dis(F,E,result1);}
					if(z3=='i'){cout<<"f1->f2"; imp(F,E,result1);}
					if(z3=='e'){cout<<"f1<->f2"; ekw(F,E,result1);}
					
					for (int i=0;i<16;i++)
					{
					  array[6][i]=result1[i];
					}
						cout<<endl;
					for(int i=0;i<16;i++)
					{
					  for(int j=0;j<7;j++)
					  {
					  	if(j==5)
					  	{
					  		cout<<"    ";
					  	}
					  	if(j==6)
					  	{
					  		cout<<"     ";
					  	}
					  	if(j==6)
				  		{
					  		if(array[j][i]==0)
					  		{
					  			null++;
					  		}
					  		if(array[j][i]==1)
					  		{
					  			one++;
					  		}
				  		}
						cout<<array[j][i]<<"    ";
					  }
					  cout<<endl;
					}

				for(int i=0;i<16;i++)
				{
					res_arr[z][i]=array[6][i];
				}

				cout<<"nulls: "<<null<<endl;
				cout<<"one: "<<one<<endl;	
				}
			}
	}

	else
	{
	cout<<endl;
	cout<<endl;
	cout<<"Error in Your input Formula, check and try again!"<<endl;

	}
cout<<"this is the end"<<endl;
}//конец цикла работы программы

	cout<<endl;
	cout<<endl;
	cout<<"Results: "<<endl;
	cout<<endl;


/*
	for(int i=0;i<16;i++)
	{
		for(int j=0; j<num_f; j++)
		{
			cout<<res_arr[j][i]<<" ";  //ыводим крайние результативные стлбики
		}
		cout<<endl;
	}
 */


    std::cout<<"N=";
    N=num_f;
	
	fact=N;
	for(int i=N-1; i>0; i--)
	{
		fact=fact*i;
	}
	cout<<"FACTORIAL: "<<fact<<endl;
	for(int i=0;i<N;i++)
	{
		res_sw[i]=new int[fact];
	}


    for(int i=0;i<N;i++)
    X[i]=i+1;
    Generate(0, res_sw);

/*

	for(int i=0;i<fact;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<res_sw[j][i]<<" ";
		}
		cout<<endl;
	}
*/

cout<<"NEW METOD"<<endl;
	for(int x=0;x<fact;x++)
	{
		int msw[num_f];
		for(int i=0;i<num_f;i++)
		{
			msw[i]=res_sw[i][x];
			//cout<<msw[i]<<" ";
		}

		cout<<endl;
		cout<<endl;

		for(int c=0;c<num_f;c++)
		{
			cout<<msw[c]<<" ";
		}
		cout<<"______"<<endl;
		cout<<endl;
		
		for(int h=0;h<16;h++)
		{	
			int counter3=0;
			for(int j=0; j<num_f-1; j++)
			{
				int m=msw[j];
				//cout<<m<<" ";
				cout<<res_arr[m-1][h]<<" ";
				if(j==num_f-2)
				{
					m=msw[j+1];
					cout<<res_arr[m-1][h]<<" ";
				}
				m=msw[j];
				/*if(res_arr[m-1][h]==0)
				{
					//cout<<i<<"line"<<j<<"kol";
					break;
				}*/
				if(res_arr[m-1][h]==1){counter3++;}
				

				if(counter3==(num_f-1))
				{
					cout<<"Stroka odinici vse "<<msw[num_f-1];
					int kvo=msw[num_f-1];

					//cout<<" "<<res_arr[kvo-1][h];

					//cout<<i<<"line is full of 1";
					if(res_arr[kvo-1][h]==0)
					{
						cout<<"Ne sleduet";
						goto zanovo;
						//exit(0);   //выходим из Всех циклов. и говорим что не следствие
					}
					if(res_arr[kvo-1][h]==1)
					{
						if(h==15)
						{
							cout<<endl;
							cout<<"SLEDUET";   //выходим ото всюду и говорим что следование выполняется.
							cout<<endl;
						}
						break;  //выходим из первого цикла фор.
					}
					break;
					
				}


				//cout<<res_arr[m][h]<<" ";  //ыводим крайние результативные стлбики
			}
			cout<<endl;
		}
		zanovo:
		cout<<"======"<<endl;
		

		cout<<endl;
	}

cout<<"NEW METOD"<<endl;

cout<<endl;
//--------------------Этот цикл определяет, Является ли текущая последовательность столбиков следованием. 
//--------------------Точнее Является ли крайный столбик следованием предидущих столбиков.
/*int counter3=0;
for(int i=0;i<16;i++)
{
	counter3=0;
	for(int j=0,int y=res_sw[j];j<(num_f-1);j++)
	{
		if(res_arr[y][i]==0)
		{
			//cout<<i<<"line"<<j<<"kol";
			break;
		}
		if(res_arr[y][i]==1){counter3++;}
		if(counter3==(num_f-1))
		{
			//cout<<i<<"line is full of 1";
			if(res_arr[num_f-1][i]==0)
			{
				cout<<"Ne sleduet";
				exit(0);   //выходим из Всех циклов. и говорим что не следствие
			}
			if(res_arr[num_f-1][i]==1)
			{
				if(i==15)
				{
					cout<<"SLEDUET";   //выходим ото всюду и говорим что следование выполняется.
				}
				break;  //выходим из первого цикла фор.
			}
			break;
		}
	//	cout<<res_arr[j][i]<<" ";
	}
}
*/
} //конец маина
	

	
	//(-B\\/C)<->(D||A)

//                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
//(B\/C)<->(D->A)
//-B\/(C<->(D/\A))
	
//-B|/(C<->(D||A))
//A||(D->(B|/C))
//X||(Z->(Y|/K))
//(X||Z)->(Y|/K)

//1010101110101011
//1010101111111111

//-A\/(B->(C/\D))