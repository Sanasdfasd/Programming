#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#define ins 200005
using namespace std;
int f[1000][1000];
int n,k;
long int pr[10000];
long int d[10000];
long long int cal=0;
long long int calc1=0;

//std::vector< std::vector<long int> > w( std::vector<long int>(l), s );
long int w[ins];

void merge(long int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(long int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
long long int washing(int som,int p)
  {  	int i=n-1,j;
   int coun=0;
   long long int s=0;
   while(coun<p)
       {
       s=s+w[i];
       i--;
       coun++;
    }
	return s+cal;
  }
int main() {
    cin>>n>>k;
    int i,j;
    for(i=0;i<n;i++)
     {
        cin>>pr[i];
         cin>>d[i];
     }
     vector<int> someval;
   for(i=0;i<n;i++)
       {
       cal=cal+d[i];
       calc1=calc1+pr[i];
       w[i]=d[i]+pr[i];
     // someval.push_back(0);
   }
    cal=cal*(-1);

    // memset(w,0,sizeof(w));

      if((n)<=k)
      {
      	cout<<calc1<<endl;
	  }
	  else
	  {
          int c,d;
          long int t;
  /*for (c = 1 ; c <= n - 1; c++) {
    d = c;
 
    while ( d > 0 && w[d] < w[d-1]) {
      t         = w[d];
      w[d]   = w[d-1];
      w[d-1] = t;
 
      d--;
    }
  }*/
           mergeSort(w, 0,  n- 1);
	  	    long long int max=washing(n-1,k);
           cout<<max<<endl;
	  }

    return 0;
}






