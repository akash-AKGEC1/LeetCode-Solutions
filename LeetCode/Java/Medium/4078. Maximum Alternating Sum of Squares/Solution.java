class Solution {
    public long maxAlternatingSum(int[] nums) {

          int n = nums.length;

        int[] temp = new int[n];
        int k = 0;

        for (int i = 0; i < n; i++) {
            temp[k] = Math.abs(nums[i]);
            k++;
        }

        Arrays.sort(temp);

        int a = 0;
        int b = n - 1;

        long sqrP = 0;
        long sqrN = 0;

        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                sqrP += (long) temp[b] * temp[b];
                b--;
            } else {
                sqrN += (long) temp[a] * temp[a];
                a++;
            }
        }

        return sqrP - sqrN;
        
    }
}