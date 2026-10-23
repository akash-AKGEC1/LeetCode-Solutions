int sortPermutation(int* nums, int numsSize) {
    int n =numsSize;
    int k = -1;



    for(int i = 0 ; i<n;i++){
        if(nums[i]!=i){
            if(k==-1){
                k=nums[i];
            }
            else{
                k=k&nums[i];
            }
        }
    }
    if(k==-1) return 0;
    return k ; 
}