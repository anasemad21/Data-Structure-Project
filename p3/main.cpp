#include <iostream>
using namespace std;
void swaper(int &num1 ,int &num2 )
{
    int temp= num1;
    num1 = num2;
    num2= temp;
}
void sort_1(int arr[],int & n)
{
    int num_zero=0;
    for(int i=0;i<n;i++)
        if(arr[i]==0)
            num_zero++;
    int j=0;
    for(j=0;j<num_zero;j++)
        arr[j]=0;
    while(j<n)
        arr[j++]=1;
}
void sort_2(int arr[],int & n)
{
    int position=0,i=0;
    do
        if(arr[i++]==0)
            arr[position++]=0;
    while(i<n);
    while(position<n)
        arr[position++]=1;
}
void sort_3(int arr[],int & n)
{
    int m=-1;
    for(int i=0;i<n;i++)
        if(arr[i]<1)
        {
            m++;
            swaper(arr[i], arr[m]);
        }
}
int main()
{
    int arr1[]={0,1,0,0,1,0,0,1,1,0,0};
    int size1= sizeof(arr1)/sizeof(arr1[0]);
    sort_1(arr1, size1);
    for(int i=0;i<size1;i++)
        cout<<arr1[i]<<'\t';
    cout<<endl<<endl;
    int arr2[]={0,1,0,0,0,1,0,0,0,0,0,1,0,1,0,0,0,0,0,0,1};
    int size2= sizeof(arr2)/sizeof(arr2[0]);
    sort_2(arr2, size2);
    for(int i=0;i<size2;i++)
        cout<<arr2[i]<<'\t';
    cout<<endl<<endl;
    int arr3[]={1,1,1,1,0,0,0,0,1,0,0,0,1,1,1,1,0,1,0,1,0,0,1,0,1,0,1,0,1};
    int size3= sizeof(arr3)/sizeof(arr3[0]);
    sort_3(arr3, size3);
    for(int i=0;i<size3;i++)
        cout<<arr3[i]<<'\t';
    cout<<endl<<endl;
    return 0;
}
