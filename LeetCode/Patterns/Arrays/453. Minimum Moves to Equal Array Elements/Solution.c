int minMoves(int* nums, int numsSize) {
    int n = numsSize;
    int sum =0;
    int  min = nums[0];

    for(int i=1;i<n;i++){
        if(nums[i]<min){
            min=nums[i];
        }
    } 
     for(int i = 0; i <n; i++) {
        sum =sum+ nums[i] - min;

    }

    return sum;
}