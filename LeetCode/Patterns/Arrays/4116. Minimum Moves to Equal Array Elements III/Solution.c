int minMoves(int* nums, int numsSize) {
    int n = numsSize ;
    int max = nums[0];
    int NO=0;
    //NO-- NUmber of oprations ;

    // max 
    for(int i = 1; i<n ;i++){
        if(max<nums[i]){
            max=nums[i];
        }
    }

    // formula ----> NO+Mxa-num[i];
    for(int j = 0 ; j<n;j++){
        NO=NO+max-nums[j];
    }
    return NO;
}