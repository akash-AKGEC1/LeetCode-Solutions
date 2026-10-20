int sortableIntegers(int* nums, int numsSize) {
     int n = numsSize;
    int ans = 0;
// 
    for (int k = 1; k <= n; k++) {
        if (n % k != 0)
            continue;

        int ok = 1;

        for (int i = 0; i < n; i += k) {
            int count = 0;

            for (int j = 0; j < k; j++) {
                int next = (j + 1) % k;

                if (nums[i + j] > nums[i + next])
                    count++;
            }

            if (count > 1) {
                ok = 0;
                break;
            }
        }

        if (!ok)
            continue;

        int prevMax = nums[0];

        for (int i = 0; i < n; i += k) {
            int mn = nums[i];
            int mx = nums[i];

            for (int j = 1; j < k; j++) {
                if (nums[i + j] < mn)
                    mn = nums[i + j];

                if (nums[i + j] > mx)
                    mx = nums[i + j];
            }

            if (i > 0 && prevMax > mn) {
                ok = 0;
                break;
            }

            prevMax = mx;
        }

        if (ok)
            ans += k;
    }

    return ans;
}