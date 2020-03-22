// quick sort
void QuickSort(int* a, int s, int t){
    int i = s, j = t-1;
    int tmp;
    if(s < t-1){
        tmp = a[s];
        while(i != j){
            while(j>i && a[j] >= tmp) j--;
            a[i] = a[j];
            while(i<j && a[i] <= tmp) i++;
            a[j] = a[i];
        }
        a[i] = tmp;
        QuickSort(a, s, i);
        QuickSort(a, i+1, t);
    }
}