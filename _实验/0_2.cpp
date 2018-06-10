#include<cstdio>
int main(void)
{
    int m,n,i,del=0,sum;
    scanf("%d",&n);
    scanf("%d",&m);
    int a[n];
    for(i=0;i<=n-1;i++)
    a[i]=i+1;
    for(sum=n;sum!=1;sum--)
    {
        del=(del+m-1)%sum;
        printf("%d ",a[del]);
        for(i=del;i<=sum-2;i++)
        a[i]=a[i+1];
    }
    printf("%d",a[0]);
        return 0;
}
