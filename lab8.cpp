#include<iostream> 
#include<algorithm> 
#include<climits> 
#include<cmath>
  
using namespace std; 
  
long long int partition(double arr[], long long int l, long long int r, double k); 
  
double findMedian(double arr[], long long int n) 
{ 
    sort(arr, arr+n);  
    return arr[n/2];   
} 
  
double kthSmallest(double arr[], long long int l, long long int r, long long int k) 
{ 
    if (k > 0 && k <= r - l + 1) 
    { 
        long long int n = r-l+1; 
        long long int i; double median[(n+4)/5]; 
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n) 
        { 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        double medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        int pos = partition(arr, l, r, medOfMed); 
  
    
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1)  
            return kthSmallest(arr, l, pos-1, k); 
  

        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
  
} 
  
void swap(double *a, double *b) 
{ 
    double temp = *a; 
    *a = *b; 
    *b = temp; 
} 
  

long long int partition(double arr[], long long int l, long long int r, double x) 
{ 
 
    long long int i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]); 
  

    i = l; 
    for (long long int j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 
  
int main() 
{ 
    long long int t;
    cin>>t;
    while(t--)
    {
        long long int p;
        cin>>p;
        double arr[p];
        for(long long int i=0;i<p;i++)
        {
            long long int x,y;
            cin>>x>>y;
            double d = sqrt(x*x+y*y);
            arr[i] = d;
        }
        /*for(long long int i=0;i<p;i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        cout<<(p+1)/2<<" ";*/
        cout<<kthSmallest(arr,0,p-1,(p+1)/2);
        cout<<endl;
    }
    return 0; 
} 