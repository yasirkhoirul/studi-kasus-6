#include<iostream>
using namespace std;
class Studi{
  friend istream& operator >> (istream&, Studi&);
	public :
    int proses();
    void out(){
  	cout<<"*----------------------------*"<<endl;
  	cout<<"|	 Daftar Nilai "<<nmatkul<< "|"<<endl;
  	cout<<"*----------------------------*"<<endl;
  	cout<<"| Nama Dosen "<<dosen<<endl;
  	for(int i=0;i<juma;i++){
    	cout<<"|Nilai Mahasiswa "<<i+1<<" : "<<maha[i]<< " |"     <<endl;
  	}
  	cout<<"| Nilai Tertinggi : "<<max<< " |"<<endl;
  	cout<<"| Nilai Terendah  : "<<min<< " |"<<endl;
  	cout<<"| Nilai Rata-rata : "<<rata<< " |"<<endl;
  	cout<<"*-------------------------------*";
	};
	
	private : 
	int n,i,juma,nama,max,min,rata,total,maha[20];
  string dosen,nmatkul;
};

istream& operator >> (istream& cin, Studi& masukkan) 
{
  int jumah;
  cout<<"masukkan nama dosen : ";
  getline(cin,masukkan.dosen);
  cout<<"masukkan nama matkul : ";
  getline(cin,masukkan.nmatkul);
	cout<<"masukkan jumlah mahasiswa :";cin>>jumah;
  masukkan.juma=jumah;
		for(int i=0;i<jumah;i++){
			cout<<"masukkan nilai mahasiswa "<<i+1<<" : ";cin>>masukkan.maha[i];
	}
	return cin;
}

int Studi::proses()
{
  max = maha[0];
  min = maha[0];

  for(i=0;i<juma;i++)
  {
    if(maha[i] > max)
    {
      max = maha[i];
    }
  }
  for(i=0;i<juma;i++)
  {
    if(maha[i] < min)
    {
      min = maha[i];  
    }
  }
  for(i=0;i<juma;i++)
  {
    total+=maha[i];
  }
  rata=total/juma;
  return max,min,rata;
};

int main(){
	Studi x;
  cin>>x;
	x.proses();
	x.out();
}
