
int minSwaps(int* nums, int numsSize) {
    int n = numsSize;

    int sum[n], idx[n], visited[n];
// sum 
    for (int i = 0; i < n; i++) {
        int x = nums[i], s = 0;

        while (x > 0) {
            s += x % 10;
            x /= 10;
        }

        sum[i] = s;
        idx[i] = i;
        visited[i] = 0;
    }

    // Sort 
    int temp[n];

    for (int width = 1; width < n; width *= 2) {
        for (int left = 0; left < n; left += 2 * width) {
            int mid = left + width;
            int right = left + 2 * width;

            if (mid > n) mid = n;
            if (right > n) right = n;

            int i = left, j = mid, k = left;

            while (i < mid && j < right) {
                int a = idx[i], b = idx[j];

                if (sum[a] < sum[b] ||
                    (sum[a] == sum[b] && nums[a] < nums[b])) {
                    temp[k++] = idx[i++];
                } else {
                    temp[k++] = idx[j++];
                }
            }

            while (i < mid) temp[k++] = idx[i++];
            while (j < right) temp[k++] = idx[j++];
        }

        for (int i = 0; i < n; i++)
            idx[i] = temp[i];
    }

    // Count 
    int swaps = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || idx[i] == i)
            continue;

        int j = i, cycleSize = 0;

        while (!visited[j]) {
            visited[j] = 1;
            j = idx[j];
            cycleSize++;
        }

        swaps += cycleSize - 1;
    }

    return swaps;
}
