class Solution {
    public int minMoves2(int[] nums) {
           int n = nums.length;
    int NO=0;
    int  min = nums[0]; 
    int max=nums[0];
// sort
Arrays.sort(nums);
//middle nikhalenge 
int idxMidle=n/2;
//MV-midle vallue
int MV=nums[idxMidle];
//formula NO-(number of oprations )=ABS(NO+nums[i]-Middle)
  for(int i=0;i<n;i++){
    NO += Math.abs(nums[i] - MV);
  }

    return NO ;
        
    }
}