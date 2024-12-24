bool binsearch(int c,int p[],int i):

bool binsearch(int c,int* p,int i)
{
    int left = 0, right = i - 1;
    while(left <= right)
    {
        int mid = left + (right - left)/2;
        if (n = mid)
        {
            return ture;
        }else if(n > mid)
        {
            left = mid + 1;
        }else{
            right = mid - 1;
        }
    }
    return false;
}
