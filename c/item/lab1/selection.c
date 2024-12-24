int* selection(int* p,int c);

int* selection(int* p,int c)
{
    for(int n = 0;n < c;n++)
    {
        for(int i = n,int m = n;i < c - 1;i++)
        {
            if(p[i] < p[i+1])
            {
            m = i + 1;
            }
        }
        int b = p[m];
        p[m] = p[n],p[n] = b;
    }
    return p；
}

int* selection(int* p,int c)
{
    for(int n = 0;n < c;n++)
    {
        int m = n;
        for(int i = n;i < c;i++)
        {
            if(p[m] < p[i])
            {
                m = i;
            }
        int b = p[m];
        p[m] = p[i],p[i] = b;
        }

    }
    return p；
}

int* selection(int* p,int c)
{
    for(int n = 0;n < c;c--)
    {
        int h = 0;
        for(int i = n;i < c - 1;i++)
        {
            if(p[i] > p[i+1])
            {
            int b = p[i];
            p[i] = p[i+1],p[i+1] = b;
            i = 1;
            }
        }


    }
    return p；
}







void selection(int* p,int c)
{
    if(c == 1)
    {
        return;
    }
    selection(p,c/2);
    selection(p+c/2-1,c/2);
    int* r = p+c/2-1;

    int* t = malloc(c * sizeof(int));
    if(t == NULL)
    {
        return;
    }
    for(int i = 0;i < c;i++)
    {
        if(*p > *r)
        {
            t[i] = *r;
            r++;
        }else{
            t[i] = *p;
            p++;
        }
        }
        p = p-c;
        for(i = 0;i < c;i++)
        {
            p[i] = t[i];
        }
        free(t);
    }







#include <stdio.h>
#include <stdlib.h>

void selection(int* p,int c);

int main()
{
    int p[] = {3,4,5,8,9,7,6,1,2,0};
    selection(p,10);
    for(int i = 0;i < 10;i++)
    {
        printf("%d",p[i]);
    }
}


void selection(int* p,int c)
{
    if(c <= 1)
    {
        return;
    }
    selection(p,c/2);
    selection(p+c/2,c - c/2);

    int* t = malloc(c * sizeof(int));
    if(t == NULL)
    {
        return;
    }
    int i = 0;
    int* v = p;
    int* b = p + c/2;
    while(v < p + c/2 && b < p + c)
    {
        if(*v < *b)
        {
            t[i] = *v;
            v++;
        }
        else{
            t[i] = *b;
            b++;
        }
        i++;
    }
    while(v < p + c/2)
    {
        t[i] = *v;
        i++;
        v++;
    }
    while(b < p + c)
    {
        t[i] = *b;
        i++;
        b++;
    }
    for(i = 0;i < c;i++)
    {
        p[i] = t[i];
    }
    free(t);
}
