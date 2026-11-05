class Solution {
    public int findTheDistanceValue(int[] arr1, int[] arr2, int d) {
         int n=arr1.length;
    int m=arr2.length;
    int count=0;
     
    // int L;
    // if(n<m){
    //     L=n;
    // }
    // else{
    //     L=m;
    // }
    for(int i =0;i<n;i++){
        boolean check=true;
        for(int j = 0;j<m;j++){
            int k =Math.abs(arr1[i]-arr2[j]);
            if(k<=d){
                check=false;
            }
        }
        if(check==true){
             count++;
        }
       
    }
    return count;
    
    }
}