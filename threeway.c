#include <stdio.h>
#include <stdlib.h>

void swap(void *a, void *b ,int size){
	void *temp = (void*)malloc(sizeof(char)*size);
	void *result1 = a;
	void *result2 = b;
	for(int i = 0;i < size;i++){
		*((char*)temp + i) = *((char*)result1 + i);
		*((char*)result1 + i) = *((char*)result2 + i);
		*((char*)result2 + i) = *((char*)temp + i);
	}
}

void exchn(void *buf,int size,int i,int j){
	void *a,*b;
	a = (char*)buf + (i*size);
	b = (char*)buf + (j*size);
	swap(a,b,size);
}

int min(int a,int b){
	return a<b?a:b;
}

int compare_int(void *a,void *b){
	int m = *((int*)a);
	int n = *((int*)b);
	if(m==n) return 0;
	else return m>n?1:-1;
}

void Qsort(void *buf,int l,int r,int (*compare)(void* ,void* ),int size){
	// chia partition
	if(l >= r) return;
	int go = l,less = l,greater = r;
	int temp;
	while(go < greater){
		temp = compare(((char*)buf + size*go),((char*)buf + size*r));	
		printf("\ntemp is %d\n ",temp);
		if(temp == 0) exchn(buf,size,--greater,go);
		else if(temp < 0) exchn(buf,size,go++,less++);
		else go++;
		printf("\ni is %d k is %d p is %d\n ",go,less,greater);
	}

	int m = min(greater-less,r-greater+1); // find the number of destination for equal pivot
	int x;
	for(x=0;x<m;x++){
		exchn(buf,size,less+x,greater+x);
	}
	Qsort(buf,l,less-1,compare,size);
	Qsort(buf,r-greater+less+1,r,compare,size);
} 
/*	Explain
l = left -- index dau tien cua mang
r = right -- index cuoi cung cua mang
go -- bien di chuyen
less -- bien danh dau phan lon hon voi phan nho hon pivot
greater -- bien danh dau phan lon hon voi phan ==
*/
void main(){
	int a[26] = {7,5,3,88,5,2,3,23,41,23,57,41,23,43,23,54,23,65,8,23,9,6,23,76,5,23};
	
	Qsort(a,0,25,compare_int,sizeof(int));
	for(int i = 0;i < 26; i++){
		printf("%d ",a[i]);
	}
}
