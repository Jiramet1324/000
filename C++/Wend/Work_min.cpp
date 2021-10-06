#include <iostream>
#include <fstream>
#include <conio.h>
#include <string.h>
#include<stdlib.h>
#include<ctype.h>
FILE *fp,*cp,*fp2;
struct bank
{
	char code[20];
	char name[20];
	char last[20];
	char birt[20];
	char age[10];
	char t,p;
	int money,sum;
	
}a,b,c;
using namespace std;

void Open_book_bank(void);
void Deposit_money(void);
void Transaction_history(void);
void Withdraw_money(void);
void Show_datavoid(void);

void Open_book_bank(void){
	char type,ch;
	
	do{
	system("cls");
	cout << "--- Open book bank ---"<<endl;
	fp = fopen("bank.dat","ab");
	
	cout << "ID Card : ";
	cin >> a.code; fflush(stdin);
	cout << "Name : ";
	fflush(stdin);
	cin >> a.name; fflush(stdin);
	cout << "Last name : ";
	cin >> a.last; fflush(stdin);
	cout << "Birthday 00/00/0000 : ";
	cin >> a.birt; fflush(stdin);
	cout << "Age : ";
	cin >> a.age; fflush(stdin);
	cout << endl;
	a.money=0;
	cout << "-- open account type --"<<endl;
	cout << "1.Fixed account"<<endl;
	cout << "2.Current account"<<endl;
	cout << "Enter type : ";
	type = getche(); cout << endl;
	
	switch(type){
		case '1': a.t ='F';break; //Fixed account
		case '2': a.t ='C';break; //Current account
	}
	fwrite(&a,sizeof(a),1,fp);
	cout <<endl<< "Press y/n to Add Data : ";
		ch = getche();
	}while(toupper(ch)=='Y');
	fclose(fp);
}

void Deposit_money(void){
		char edit[13];
	int n=1;
	int num = sizeof(b);
	system("cls");
	if((fp = fopen("bank.dat","r+b"))==NULL){
	cout<<"Cannot open file !\n";
	}
	else{
		cout<<"----- Deposit money -----";
		cout<<endl<<"Account number : ";
		gets(edit);
		int n=1;
		cout<<endl<<"---ID Card-------Name-----Last--------Birt------Age-----------Money-----------Type----"<<endl;
		for(;;){
			if(fread(&a,sizeof(a),1,fp)!=1){
				if(feof(fp)){
					fclose(fp);
					break;
				}
			}
			if(strcmp(a.code,edit)==0){
				n++;
				cout<<a.code<<"    "<<a.name<<"    "<<a.last<<"    "<<a.birt<<"    "<<a.age<<"           "<<a.money;
				if(a.t=='F'){
					cout<<"      Fixed account"<<endl;
				}else if(a.t=='C'){
					cout<<"      Current account"<<endl;
				}
				cout<<endl<<"----- Deposit money -----";
				cout<<endl<<"Add Money = "; cin>>b.money;
				a.money = (a.money + b.money);
				a.sum = b.money;
				a.p='+';
				
				if((fp2 = fopen("history.dat","ab"))==NULL){
					cout << "Nofile bank.dat installing file..."<<endl<<endl;
					ofstream myFile("history.dat",ios::out);
					
				}else{
					fwrite(&a,sizeof(a),1,fp2);
				}
		
				fseek(fp,-(num),SEEK_CUR);
				fwrite(&a,sizeof(a),1,fp);
				cout<<"----- Success !!! -----";
				
	    
	
				break;
				
			}	
		}
		if (n==1){
				cout<<endl<<"                                       NO Data                                        "<<endl;
				cout<<endl<<"--------------------------------------------------------------------------------------"<<endl;
			}
	}
	fclose(fp);
	fclose(fp2);
	getch();
}
void Withdraw_money(void){
	char edit[13];
	int n=1;
	int num = sizeof(b);
	system("cls");
	if((fp = fopen("bank.dat","r+b"))==NULL){
		cout<<"Cannot open file !";
	}
	else{
		cout<<"----- Withdraw money -----";
		cout<<endl<<"Account number : ";
		gets(edit);
		int n=1;
		cout<<endl<<"---ID Card-------Name-----Last--------Birt------Age-----------Money-----------Type----"<<endl;
		for(;;){
			if(fread(&a,sizeof(a),1,fp)!=1){
				if(feof(fp)){
					fclose(fp);
					break;
				}
			}
			if(strcmp(a.code,edit)==0){
				n++;
				cout<<a.code<<"    "<<a.name<<"    "<<a.last<<"    "<<a.birt<<"    "<<a.age<<"           "<<a.money;
				if(a.t=='F'){
					cout<<"      Fixed account"<<endl;
				}else if(a.t=='C'){
					cout<<"      Current account"<<endl;
				}
				cout<<"----- Withdraw money -----";
				cout<<endl<<"Withdraw Money = "; cin>>b.money;
				
				if(b.money > a.money){
					cout<<"--- The transaction cannot be made due to insufficient funds. ---";
				}
				else{
					
					
					a.money = (a.money - b.money);
					a.sum = b.money;
					a.p='-';
					if((fp2 = fopen("history.dat","ab"))==NULL){
						cout << "Nofile bank.dat installing file..."<<endl<<endl;
						ofstream myFile("history.dat",ios::out);
					}else{
						fwrite(&a,sizeof(a),1,fp2);
					}
				
					fseek(fp,-(num),SEEK_CUR);
					fwrite(&a,sizeof(a),1,fp);
					cout<<"----- Success !!! -----";
				}
				break;
			}	
		}
		if (n==1){
				cout<<endl<<"                                       NO Data                                        "<<endl;
				cout<<endl<<"--------------------------------------------------------------------------------------"<<endl;
			}
	}
	fclose(fp);
	fclose(fp2);
	getch();
}

void Transaction_history(void){
	int n=1;
	system("cls");
	if((fp = fopen("history.dat","rb"))==NULL){
		printf("Cannot open file !\n");
	}
	else{
		printf("----- History Data -----\n");
		cout<<endl<<"---ID Card--------Money----------Toltal-------Type----"<<endl;
		for(;;){
			if(fread(&a,sizeof(a),1,fp)!=1){
				if(feof(fp)){
					fclose(fp);
					break;
				}
			}	
			n++;
			//cout<<a.code<<"    "<<a.name<<"    "<<a.last<<"    "<<a.birt<<"    "<<a.age<<"           "<<a.money;
			//printf("%s%9s%10s%15s%9s%16d",a.code,a.name,a.last,a.birt,a.age,a.money);
			cout<<a.code<<"     "<<a.p<<a.sum;
			printf("%16d",a.money);
				if(a.t=='F'){
					cout<<"      Fixed account"<<endl;
				}else if(a.t=='C'){
					cout<<"      Current account"<<endl;
				}
			
		}
		if (n==1){    
				cout<<endl<<"                                       NO Data                                        "<<endl;
				cout<<endl<<"--------------------------------------------------------------------------------------"<<endl;
			}
	}
	fclose(fp);
	getch();
}
void Show_data(void){
	int n=1;
	system("cls");
	if((fp = fopen("bank.dat","rb"))==NULL){
		printf("Cannot open file !\n");
	}
	else{
		printf("----- Show Data -----\n");
		cout<<endl<<"---ID Card--------Name-----Last---------Birt---------Age-----------Money-----------Type----"<<endl;
		for(;;){
			if(fread(&a,sizeof(a),1,fp)!=1){
				if(feof(fp)){
					fclose(fp);
					break;
				}
			}	
			n++;
			//cout<<a.code<<"    "<<a.name<<"    "<<a.last<<"    "<<a.birt<<"    "<<a.age<<"           "<<a.money;
			printf("%s%9s%10s%15s%9s%16d",a.code,a.name,a.last,a.birt,a.age,a.money);
				if(a.t=='F'){
					cout<<"      Fixed account"<<endl;
				}else if(a.t=='C'){
					cout<<"      Current account"<<endl;
				}
			
		}
		if (n==1){    
				cout<<endl<<"                                       NO Data                                        "<<endl;
				cout<<endl<<"--------------------------------------------------------------------------------------"<<endl;
			}
	}
	fclose(fp);
	getch();
}	
int main(){
	char ch;
	do{
	ifstream f;
	f.open("bank.dat");
	if(f.is_open()){
		system("cls");
		cout << "---Select number---"<<endl;
		cout << "1.Open book bank"<<endl;
		cout << "2.Deposit money"<<endl;
		cout << "3.Withdraw money"<<endl;
		cout << "4.Transaction history"<<endl;
		cout << "5.Show data"<<endl;
		cout<<"Press E to Exit !"<<endl;
		cout << "-------------------"<<endl;
		cout << "Enter number : ";
		ch = getche(); cout <<endl<<endl;
		
		switch(ch){
			case '1': Open_book_bank();break;
			case '2': Deposit_money();break;
			case '3': Withdraw_money();break;
			case '4': Transaction_history();break;
			case '5': Show_data();break;
	}
	}else{
		cout << "Nofile bank.dat installing file..."<<endl<<endl;
		ofstream myFile("bank.dat",ios::out);
		cout << "Please run the program again."<<endl;
	}
	
	}while(toupper(ch)!='E');
	
	return 0 ;
}
