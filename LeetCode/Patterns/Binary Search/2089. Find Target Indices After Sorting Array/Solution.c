/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* targetIndices(int* nums, int numsSize, int target, int* returnSize) {
    for(int i =1; i<numsSize;i++){
        int curr =nums[i];
        int prev =i-1;
        while( prev>=0 && nums[prev]>curr){
            nums[prev+1]=nums[prev];
            prev--;
        }
        nums[prev+1]=curr;

    }
    int* result = (int*)malloc(numsSize * sizeof(int));
    int j =0 ;
    for(int k =0;k<numsSize;k++){
        if(nums[k]==target ){
            result[j]=k;
            j++;
        }
    }
    *returnSize = j;
    return result;
    
}