#include <stdio.h>
#include <stdlib.h>

// Generic Programming

int Search(void *buf,int size,int l,int r,void *item,int (*compare)(void const* ,void const* )){
	if(r < l) return -1; // Not found
	int i = (l + r)/2;
	int res = compare(item,(char*)buf + i*size); //
	if(res == 0) return i;
	else if(res < 0) return Search(buf,size,l,i-1,item,compare);
	else return Search(buf,size,i+1,r,item,compare);
}

int int_compare(void const *x, void const *y){
	int m,n;
	m = (*(int*)x);
	n = (*(int*)y);
	if(m == n) return 0;
	return m>n ? 1 : -1;
}
void main(){
	int n = 30;
	int *a = (int*) malloc(30*sizeof(int));
	int r;
	for(int i=0;i<n;i++){
		r = rand()%100;
		a[i] = r;
	}
	qsort(a,n,sizeof(int),int_compare);
	printf("=====QUICK SORT====");
	for(int i=0;i<n;i++){
		printf("%d\n",a[i]);
	}
	printf("=====Search=======\n");
	int find;
	scanf("%d",&find);
	printf("\n");
	printf("%d",Search(a,sizeof(int),0,n-1,&find,int_compare));
}
