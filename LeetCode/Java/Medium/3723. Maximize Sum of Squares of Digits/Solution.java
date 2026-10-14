class Solution {
    public String maxSumOfSquares(int num, int sum) {
                  if (sum > 9 * num) {
            return "";
        }

        StringBuilder required = new StringBuilder();

        for (int i = 0; i < num; i++) {
            if (sum > 9) {
                required.append(9);
                sum =sum- 9;
            } else {
                required.append(sum);
                sum = 0;
            }
        }

        return required.toString();

        
    }
}