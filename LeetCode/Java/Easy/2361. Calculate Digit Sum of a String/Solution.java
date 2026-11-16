class Solution {
    public String digitSum(String s, int k) {
        while (s.length() > k){
         StringBuilder sn = new StringBuilder();
         

         for(int i = 0 ; i<s.length();i+=k){
            String str = s.substring(i, Math.min(i + k, s.length()));
            int sum =0;
            for(int j= 0 ;j<str.length();j++){
                sum=sum+str.charAt(j)-'0';
            }
            sn.append(sum);
         }
          s = sn.toString();
        }
        return s;
    }
}