/*
高精度加法： pprp 
*/ 

#include <iostream>
#include <cstring>

using namespace std;

int main(){
	
	char aa[100001],bb[100001];
	int a[100001],b[100001];
	
	int ans[100010];
	
	memset(ans,0,sizeof ans);
	cin >> aa >> bb;
	int lena = strlen(aa);
	int lenb = strlen(bb);
	
	for(int i = 0 ; i < 100001; i++){
		if(i < lena)
		{
			a[i] = aa[i] - '0';
		}
		else
		{
			a[i] = -1;
			
		}
		
		if(i < lenb){
			b[i] = bb[i] - '0';
		} 
		else
		{
			b[i] = -1;
		}
	}	
	
	for(int i = 0 ; i < (lena+1)/2; i++){
		int tmp = a[lena-i-1];
		a[lena-i-1] = a[i];
		a[i] = tmp;
	}
	
	for(int i = 0 ; i < (lenb+1)/2; i++){
		int tmp = b[lenb-i-1];
		b[lenb-i-1] = b[i];
		b[i] = tmp;
	}
	
	
	for(int i = 0 ; i < 10 ; i++)
		cout << a[i];
	cout << endl;
	
	for(int i = 0 ; i < 10 ; i++)
		cout << b[i];
	cout << endl;
	
	int i = 0 , k = 0;
	int c = 0;
	
	while(a[i] != -1 && b[i] != -1){
		int tmp = a[i] + b[i] + c;
		cout << tmp << "+++" << endl;
		if(tmp > 9)
		{
			ans[k++] = tmp % 10;	
			c = tmp / 10;//jin wei
		}
		else
		{
			ans[k++] = tmp; 
		}
		i++;
	}
//	cout << "test:" << k << endl; 
	while(a[i] != -1){
		int tmp = a[i] + c;
		if(tmp > 9)
		{
			ans[k++] = tmp % 10;
			c = tmp / 10;
		}
		else
		{
			ans[k++] = tmp;
			c = 0;
		}
		i++;
	}
	while(b[i] != -1){
		int tmp = b[i] + c;
		if(tmp > 9){
			ans[k++] = tmp % 10;
			c = tmp / 10;			
		}
		else
		{
			ans[k++] = tmp;
			c = 0;
		}		
		i++;
	}
	//cout << k << endl; 
	
	if(c != 0)
	{
		ans[k++] = c;
	}
	for(int i = k-1 ; i >= 0; i--)
	{
		cout << ans[i];	
	}	
	cout << endl;
	
	system("pause");
	return 0;	
} 
