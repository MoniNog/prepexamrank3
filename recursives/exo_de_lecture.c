int fun1(int x, int y)
{
    if (x == 0)
        return y;
    else
        return fun1(x - 1, x + y);
}

4 9 
3 13
2 19
1 21
0 22
22

// minimum index finder
    int minIndex(int arr[], int s, int e)
    {
        int sml = INT32_MAX;
        int mindex;
        for (int i = s; i < e; i++) {
            if (sml > arr[i]) {
                sml = arr[i];
                mindex = i;
            }
        }
        return mindex;
    }

    void fun2(int arr[], int start_index, int end_index)
    {
        if (start_index >= end_index)
            return;
        int min_index;
        int temp;

        // minIndex() returns index of minimum value in
        // array arr[start_index...end_index] 
        min_index = minIndex(arr, start_index, end_index);

        temp = arr[start_index];
        arr[start_index] = arr[min_index];
        arr[min_index] = temp;

        fun2(arr, start_index + 1, end_index);
    }

/* Assume that n is greater than or equal to 0 */
void fun2(int n)        4           2           1  
{
  if(n == 0)
    return;

  fun2(n/2);            4/2 = 2     2/2 = 1     1/2 = 0
  printf("%d", n%2);    2%2 = 0     1%2 = 1      
}

