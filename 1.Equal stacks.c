
int equalStacks(int h1_count, int* h1, int h2_count, int* h2, int h3_count, int* h3) {
    int sum1 =0, sum2 =0, sum3 =0;
    
    for(int i=0; i <h1_count; i++) 
        sum1 += h1[i];
    for(int i=0; i <h2_count; i++) 
        sum2 += h2[i];
    for(int i=0; i <h3_count; i++) 
        sum3 += h3[i];
    
    int i = 0, j = 0, k = 0;
    
    while (i < h1_count && j < h2_count && k < h3_count) {
        if (sum1 == sum2 && sum2 == sum3) 
            return sum1;
        
        if (sum1 >= sum2 && sum1 >= sum3) 
            sum1 -= h1[i++];
        else if (sum2 >= sum1 && sum2 >= sum3) 
            sum2 -= h2[j++];
        else if (sum3 >= sum1 && sum3 >= sum2) 
            sum3 -= h3[k++];
    }
    
    return 0;
}