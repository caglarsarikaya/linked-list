#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>
using std::cout;
using std::cin;
using std::endl;

#define BILGISAYAR 10
#define ELEKTRIK 11
#define MEKATRONIK 12
#define MAKINE 13
#define CEVRE 14
#define ENDUSTRI 15
#define INSAAT 16

void PickChoice(const int choice);

class Data{
	public:
		int number;
		char name[20];
		char surname[20];
		int search;
		
		Data*next;
		Data*prev;
		Data*temp;
		void SelectingSection(void);
		void PrintSection(void);
		
	private:
		char section[20];
		
};

class List{
	private:
		Data *ListHead;
		Data*ListEnd;
		
	public:
		List()
		{
			ListHead = NULL;
			ListEnd = NULL;
		}
		Data * getlisthead(){return ListHead;
		}
		bool ListIsEmpty();
		void AddList(void);
		void FindStudent(void);
		bool HelpToAdd(const int SearchingNumber);
		void DeleteData(const int DeletingNumber);
		void PrintList(void);
		void Findcompstudouble();
		void allstudouble();
};

class SingleData{
	public:
		int number;
		char name[20];
		char surname[20];
		int Listsearch;
		
		SingleData*next;
		SingleData*temp;
		void SelectingSection(void);
		void PrintSection(void);
		
		
	private:
		char section[20];
		
};

class SingleList{
	private:
		SingleData *SListHead;
		
	public:
		SingleList(){
			SListHead=NULL;
		}
		SingleData * getSListHead(){return SListHead;
		}
		bool SingleListIsEmpty();
		void SingleListAdd(void);
		void SingleListFindStudent(void);
		bool SingleListHelpToAdd(const int SearchingSingleNumber);
		void DeleteSingleList(const int DeletingSingleNumber);
		void PrintSingleList(void);
		void Onlygrapbubblesortfornumber();
		void Findcompstusingle();
		void allstusingle();
		void Onlygrapquicksortforsurname();
};


void allstu();



void SingleData::SelectingSection(void){
	switch(number/10000){
		case BILGISAYAR:
			strcpy(section,"Bilgisayar"); break;
		case ELEKTRIK:
			strcpy(section,"Elektrik"); break;
		case MEKATRONIK:
			strcpy(section,"Mekatronik"); break;
		case MAKINE:
			strcpy(section,"Makine"); break;
		case CEVRE:
			strcpy(section,"Çevre"); break;
		case ENDUSTRI:
			strcpy(section,"Endüstri"); break;
		case INSAAT:
			strcpy(section,"Ýnþaat"); break;
	}
}

void SingleData::PrintSection(void){
	
	cout << section <<" Muhendisligi";
}


bool SingleList::SingleListIsEmpty(void){
	return SListHead == NULL;
}

void SingleList::SingleListAdd(void){
	int choice=1;
	while(choice==1){
		SingleData*add=new SingleData();
			if(add){
			cout<<"\n Yeni Ogrenci Numarasini Giriniz(6 haneli olacak):";
			cin>> add->number;
			if(SingleListHelpToAdd(add->number))
			{
				cout << "\n"<< add->number << " ile daha once kayit yapilmistir..Numarayi Kontrol Ediniz!!\n";
				continue;
			}
			add->SelectingSection();
			for(;add->number /10000 >=17 || add->number /10000<10;)
			{
				cout<< "\nHatali Numara Girisi..Tekrar Giriniz..6 haneli olmasina dikkat ediniz.\n\n";
				cout<<"Yeni ogr numarasini giriniz:";
				cin>>add->number;
				if(SingleListHelpToAdd(add->number))
				{
					cout<<" ile daha once kayit yapilmistir..Numarayi Kontrol Ediniz!!\n";
					add->number=0;
					continue;
				}
			}
			
				add->SelectingSection();
			cout<<"Yeni ogr Adi ve Soyadini giriniz:";
			cin>>add->name;
			cin>>add->surname;
			
			
			if(SListHead == NULL){
				SListHead=add;
				add->Listsearch=1;
			}
			
			else{
				add->next=SListHead;
				SListHead=add;
				
			}
			
	}
	
	cout<<"\nYeni Ogrenci Girisi Basarili. Yeni Giris Icin 1 e basiniz.\n"
			         "Cikmak Icin 1 Disinda Rakam Giriniz.Seciminiz:";
			         
			cin>> choice;
}


}

bool SingleList::SingleListHelpToAdd(const int SearchingSingleNumber)
{
	if(SListHead == NULL) 
	return false;
	
	else if(SListHead->number > SearchingSingleNumber)
	return false;
	
	
	SingleData*sign=new SingleData();
	sign= SListHead;
	
	while (sign != NULL && sign->number !=SearchingSingleNumber)
		sign=sign->next;
	if(sign == NULL)
	return false;
	
	else if(sign->number ==SearchingSingleNumber)
	cout<<"Numara:\t" << sign->number << "Ad Soyad" << sign->name << "   "<<sign->surname;
	return true;
}


void SingleList::SingleListFindStudent(void)
{
	if(SListHead==NULL)
	{
		cout<<"\n Hata! Liste bos..\n";
		return;
	}
	
	cout<<"\nAranacak Ogrencinin Numarasini Giriniz:"; 
				int f_no;  cin>>f_no;
				
	if (f_no<100000 || f_no>169999)
	{
		cout << "\nHata! Yanlis numara girdiniz..\n ";
		return;
	}
	

	
	SingleData*sign;
	
		if(SListHead == NULL)
	{
		cout<<"\n Liste bos \n";
		return;
	}
	
	else if(SListHead->number == f_no){
		cout<<"\nNumara:\t" <<SListHead->number << "Ad Soyad"<< SListHead->name <<"  " <<SListHead->surname <<"\n";
	return;
		
	}
	
	
	else{
		sign=SListHead;
		while(sign!=NULL){
			
			if(sign->number==f_no){
				
				
				cout<<"\nNumara:\t" <<sign->number << "Ad Soyad  "<< sign->name <<"  " <<sign->surname <<"\n";
				return;
				
			}
			
	
			sign=sign->next;
		}
		
	
	}
	
	return;
}

void SingleList::DeleteSingleList(const int DeletingSingleNumber)
{
	SingleData *deleting;
	
	if(SListHead == NULL)
	{
		cout<<"\n Liste bos \n";
		return;
	}
	
	
	else if(SListHead->number== DeletingSingleNumber)
	{
		deleting=SListHead;
		SListHead=SListHead->next;
		delete deleting;
		cout<<DeletingSingleNumber << "numarali ogr silindi..\n";
		return;
		
	}
	
	else 
	{
	
		deleting=SListHead;
		while(deleting->next!=NULL){
			if(deleting->next->number==DeletingSingleNumber)
			{
				deleting->next=deleting->next->next;
			}
			deleting=deleting->next;
		}
	
	}
	return;
}

void SingleList::PrintSingleList(void)
{
	if(SListHead==NULL)
	cout<<"\n Liste bos..";
	
	else
	{
		SingleData*sign;
		sign=SListHead;
		cout<<"\n Grafik dersini alan ogrenciler \n";
		
		while(sign!=NULL)
		{
			cout<< sign->number;
			cout<<" ";
			sign->PrintSection();
			cout.width(3);
			cout<<"  "<<sign->name <<"  "<< sign->surname<< endl;
			sign=sign->next;
			
		}
	}
}

void SingleList::Onlygrapquicksortforsurname(){
	SingleData *keep;
	keep=SListHead;
	
		if(SListHead==NULL){
		cout<<"\n Liste bos..";
		
	}
	else{
		cout<<"\n Grafik dersini alan ogrenciler soyad siralama\n";
	}
	
	
}

void SingleList::Onlygrapbubblesortfornumber(){
	
	SingleData *keep;
	keep=SListHead;
	
	int dizi[50],index=0;
	
	if(SListHead==NULL){
		cout<<"\n Liste bos..";
		
	}
	else{
		cout<<"\n Grafik dersini alan ogrenciler numara siralama\n";
	}
	
	while(keep!=NULL){
		dizi[index] = keep->number;
		index++;
		keep=keep->next;
	}
	
	int i,temp=0,j;
	for(i=0;i<=index-1;i++){
		for(j=0;j<index-i-1;j++){
			if(dizi[j]>dizi[j+1]){
				temp=dizi[j];
				dizi[j]=dizi[j+1];
				dizi[j+1]=temp;
			}
		}
	}
		
		
		
	for(i=0;i<=index;i++)
	{
		keep=SListHead;
		while(keep!=NULL){
			
			if(keep->number == dizi[i]){
				
			cout<< keep->number;
			cout<<" ";
			keep->PrintSection();
			cout.width(3);
			cout<<"  "<<keep->name <<"  "<< keep->surname<< endl;
			
			}
			keep=keep->next;
		}
	
	}
	
	return;
}
SingleList SL;
List L;

void allstu(){
	Data *one;
	one=L.getlisthead();
	SingleData*two;
	two=SL.getSListHead();
	SingleData *Stus[20];
	int index=0;
	cout<<" liste !!";
	while(one!=NULL)
	{
		two=SL.getSListHead();
		while(two!=NULL)
		{
			if(one->number==two->number)
			{
				Stus[index]=two;
				index++;
			}
			two=two->next;
		}
		one=one->next;
	}
	int i=0,j=0;
	SingleData *temp;
	for(i=0;i<index-1;i++)
		for(j=0;j<index-i-1;j++)
			if(Stus[j]->name>Stus[j+1]->name)
				{
					temp=Stus[j];
					Stus[j]=Stus[j+1];
					Stus[j+1]=temp;
				}
		
		int c;		
	for(c=0;c<index;c++)
		{
			cout<< Stus[j]->number;
			cout<< "   ";
			Stus[j]->PrintSection();
			cout<< "   "<< Stus[j]->name << " " <<Stus[j]->surname<< endl;	
		}
		return;
	
}

void List::Findcompstudouble(){
	Data*one;
	one=ListHead;
	
	int dizi[50],index=0;
	if(one==NULL)
	cout<<" otoma dersi alan bilg ogr yok";
	while(one!=NULL){
		if((one->number)/10000 ==BILGISAYAR)
		{
			cout<< one->number;
			cout<< "   ";
			one->PrintSection();
			cout<< "   "<< one->name << " " <<one->surname<< endl;	
		}
		one=one->next;
	}
	return;
}



void SingleList::Findcompstusingle(){
	
	SingleData*two;
	two=SListHead;
	int dizi[50],index=0;
	if(two==NULL)
	cout<<" Bilg grafik dersi alan bilg ogr yok";
	
	while(two!=NULL){
		if((two->number)/10000 ==BILGISAYAR)
		{
			cout<< two->number;
			cout<< "   ";
			two->PrintSection();
			cout<< "   "<< two->name << " " <<two->surname<< endl;	
		}
		two=two->next;
	}
	return;
}


void Data::SelectingSection(void){
	
	switch(number/10000){
		case BILGISAYAR:
			strcpy(section,"Bilgisayar"); break;
		case ELEKTRIK:
			strcpy(section,"Elektrik"); break;
		case MEKATRONIK:
			strcpy(section,"Mekatronik"); break;
		case MAKINE:
			strcpy(section,"Makine"); break;
		case CEVRE:
			strcpy(section,"Çevre"); break;
		case ENDUSTRI:
			strcpy(section,"Endüstri"); break;
		case INSAAT:
			strcpy(section,"Ýnþaat"); break;
	}
	
}

void Data::PrintSection(void){
	
	cout << section <<" Muhendisligi";
}

bool List::ListIsEmpty(void){
	return ListHead == NULL && ListEnd == NULL;
}


void List::AddList(void){
	int choice=1;
	while(choice ==1){
		Data*add =new Data();
		if(add){
			cout<<"\n Yeni Ogrenci Numarasini Giriniz(6 haneli olacak):";
			cin>> add->number;
			if(HelpToAdd(add->number))
			{
				cout << "\n"<< add->number << " ile daha once kayit yapilmistir..Numarayi Kontrol Ediniz!!\n";
				continue;
			}
			add->SelectingSection();
			for(;add->number /10000 >=17 || add->number /10000<10;)
			{
				cout<< "\nHatali Numara Girisi..Tekrar Giriniz..6 haneli olmasina dikkat ediniz.\n\n";
				cout<<"Yeni ogr numarasini giriniz:";
				cin>>add->number;
				if(HelpToAdd(add->number))
				{
					cout<<" ile daha once kayit yapilmistir..Numarayi Kontrol Ediniz!!\n";
					add->number=0;
					continue;
				}
			}
			
			add->SelectingSection();
			cout<<"Yeni ogr Adi ve Soyadini giriniz:";
			cin>>add->name;
			cin>>add->surname;
			
			if(ListEnd==NULL)
			{
				ListHead=add;
				ListEnd=add;
				ListEnd->prev=NULL;
				ListEnd->next=NULL;
				add->search=1;
			}
			
			else if(ListHead->number > add->number)
			{
				ListHead->prev=add;
				add->next=ListHead;
				ListHead=add;
				ListHead->prev=NULL;
				add->search=1;
			}
			
			else if(add->number > ListEnd->number)
			{
				ListEnd->next=add;
				add->prev=ListEnd;
				ListEnd=add;
				ListEnd->next=NULL;
				add->search=1;
				
			}
			
			
			else
			{
				Data*sign;
				Data*sign_prev;
				sign=ListHead;
				while(add->number > sign->number)
				{
					sign_prev=sign;
					sign=sign->next;
				}
				add->next=sign;
				add->prev=sign_prev;
				sign_prev->next=add;
				sign->prev=add;
				add->search=1;
			}
		}
		
		cout<<"\nYeni Ogrenci Girisi Basarili. Yeni Giris Icin 1 e basiniz.\n"
			         "Cikmak Icin 1 Disinda Rakam Giriniz.Seciminiz:";
			         
			cin>> choice;
	}
}



bool List::HelpToAdd(const int SearchingNumber)
{
	if(ListEnd == NULL) 
	return false;
	
	else if(ListHead->number > SearchingNumber)
	return false;
	
	else if(ListEnd->number < SearchingNumber)
	return false;
	
	Data*sign=new Data();
	sign= ListHead;
	
	while (sign != NULL && sign->number !=SearchingNumber)
		sign=sign->next;
	if(sign == NULL)
	return false;
	
	else if(sign->number ==SearchingNumber)
	cout<<"Numara:\t" << sign->number << "Ad Soyad" << sign->name << "   "<<sign->surname;
	return true;
}

void List::FindStudent(void)
{
	if(ListEnd==NULL)
	{
		cout<<"\n Hata! Liste bos..\n";
		return;
	}
	
	cout<<"\nAranacak Ogrencinin Numarasini Giriniz:"; 
				int f_no;  cin>>f_no;
				
	if (f_no<100000 || f_no>169999)
	{
		cout << "\nHata! Yanlis numara girdiniz..\n ";
		return;
	}
	
	if(ListHead->number > f_no)
	{
		cout<<"\n Numara Bulunamadi \n";
		return;
	}
	else if(ListEnd->number < f_no)
	{
		cout<<"\n Numara Bulunamadi \n";
		return;
	}
	
	Data*sign=new Data();
	sign=ListHead;
	
	while(sign!= NULL && sign->number != f_no)
	sign=sign->next;
	
	if(sign==NULL)
	return;
	
	else if(sign->number == f_no)
	cout<<"\nNumara:\t" <<sign->number << "Ad Soyad"<< sign->name <<"  " <<sign->surname <<"\n";
	return;
}

void List::DeleteData(const int DeletingNumber)
{
	Data *deleting;
	
	if(ListEnd == NULL)
	{
		cout<<"\n Liste bos \n";
		return;
	}
	
	else if(ListHead == ListEnd && ListHead->number ==DeletingNumber)
	{
		ListHead=NULL;
		ListEnd=NULL;
		cout<<DeletingNumber << "numarali ogr listeden silindi..\n Liste Bos!\n";
		return;
	}
	
	else if(ListHead->number== DeletingNumber)
	{
		deleting=ListHead;
		ListHead=ListHead->next;
		ListHead->prev=NULL;
		delete deleting;
		cout<<DeletingNumber << "numarali ogr silindi..\n";
		return;
		
	}
	
	else if(ListEnd->number==DeletingNumber)
	{
		deleting=ListEnd;
		ListEnd=ListEnd->prev;
		ListEnd->next= NULL;
		delete deleting;
		cout<<"numarali ogr silindi..\n";
	}
	
	else 
	{
		deleting=ListHead;
		
		while(deleting != NULL && deleting->number != DeletingNumber)
		deleting=deleting->next;
		
		if(deleting == NULL)
		cout<< DeletingNumber <<"numarali ogr listee bulunamadi \n";
		
		else if(deleting->number ==DeletingNumber)
		{
			(deleting->prev)->next=deleting->next;
			(deleting->next)->prev=deleting->prev;
			delete deleting;
			cout << DeletingNumber << " numarali ogrenci listeden silindi.\n";
			return;
		}
	}
}

void List::PrintList(void)
{
	if(ListEnd==NULL)
	cout<<"\n Liste bos..";
	
	else
	{
		Data*sign;
		sign=ListHead;
		cout<<"\n Otoma dersini alan ogrenciler \n";
		
		while(sign!=NULL)
		{
			cout<< sign->number;
			cout<<" ";
			sign->PrintSection();
			cout.width(3);
			cout<<"  "<<sign->name <<"  "<< sign->surname<< endl;
			sign=sign->next;
			
		}
	}
}


int main(int argc, char** argv) 
{
	
	int choice;
	do{
		system("color 4b");
		cout<<"\nSecim Yapiniz...\n"
		"1.Otoma Dersi Ogrenci Ekle\n"
		"2.Otoma Dersi Ogrenci Ara\n"
		"3.Otoma Dersi Ogrenci Sil\n"
		"4.Otoma Dersi Ogrenci Listele\n\n"
		"5.Bilgisayar Grafik Dersi Ogrenci Ekle\n"
		"6.Bilgisayar Grafik Dersi Ogrenci Ara\n"
		"7.Bilgisayar Grafik Dersi Ogrenci Sil\n"
		"8.Bilgisayar Grafik Dersi Ogrenci Listele\n\n"
		"9.Bilgisayar Grafik Dersi Ogrenci Numaraya Gore Kabarcik\n"
		"10.Bilgisayar Grafik Yada Otoma Dersi Alan Bilg Ogr\n"
		"11.Iki Ders alan ogr ada gore kabarcik\n"
		"12.Bilgisayar Grafik Dersi Ogrenci soyada Gore hizli\n"
		"\n(Cikis icin 0'a basiniz)Seciminiz:";
		
		cin>>choice;
		PickChoice(choice);
		
	}while(choice!=0);

	return 0;
}

void PickChoice(const int choice)
{
	switch(choice)
	{
		case 0:exit(0); break;
		case 1:L.AddList(); break;
		case 2:L.FindStudent(); break;
		case 3: { cout<<"Silinecek Ogrencinin Numarasini Giriniz:"; int f_no; cin>>f_no; L.DeleteData(f_no);  break; }
		case 4: L.PrintList(); break;
		case 5: SL.SingleListAdd();break;
		case 6: SL.SingleListFindStudent();break;
		case 7: { cout<<"Silinecek Ogrencinin Numarasini Giriniz:"; int f_no; cin>>f_no; SL.DeleteSingleList(f_no);  break; }
		case 8: SL.PrintSingleList(); break;
		case 9: SL.Onlygrapbubblesortfornumber(); break;
		case 10:{
				SL.Findcompstusingle();
				L.Findcompstudouble();
				break;		}
		case 11: allstu(); break;
		case 12:SL.Onlygrapquicksortforsurname();break;
		
	}
}



















