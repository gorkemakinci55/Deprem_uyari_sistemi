#include <stdio.h>
int array[];
int functionz(int A)
{
    int k = 0;    
    int y;
    while (A > 0)
    {
        array[k] = A % 10;
        k++;
        A = A/10;
    }
    
    printf("basamak sayisi= %d\n",k);
    for (y = 0; y < k ; y++)
            printf("array= %d\n",array[y]);

 
    int *new;
	new = malloc(sizeof(int)*k);
    int first = 0;
    int back = k-1;
    
    int m = 0;
    while(m != k)
    {
        new[m] = array[first];
        m++;
        if(m==k) 
        {
        break;
        }
        new[m] = array[back];
        m++;
        first++;
        back--; 
    }
    
    for (y = 0; y < k ; y++)
            printf("array= %d\n",new[y]);
    
    int i;
    int B = 0;
    int b = 1;
    int temp = sizeof(new[0]);
    for(i = temp; i >=0; i--)
    {
          B = B + (new[i] * b );
          b=b*10;
    }
    
    return B;
}

int main()
{ 
    int result;
    result = functionz(12345);
    printf("resulxt = %d",result);
}
