int sumOfSquares(int* nums, int numsSize) {
    int n=numsSize;
    int sum =0 ;
    for(int i=0 ;i<n ; i++){
        int D =i+1;
        if(n%D==0){
            sum=sum+nums[i]*nums[i];
        }
    }
    return sum ;
    
}