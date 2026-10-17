
int minSwaps(int* nums, int numsSize) {
    int n = numsSize;
    int sum[n], idx[n], visited[n];
   //sum nikalte hnai 
    for (int i = 0; i < n; i++) {
        int sumN = 0, curr = nums[i];

        while (curr != 0) {
            sumN += curr % 10;
            curr /= 10;
        }

        sum[i] = sumN;
        idx[i] = i;
        visited[i] = 0;
    }

    // Sort 
    for (int i = 1; i < n; i++) {
        int curr = idx[i];
        int j = i - 1;

        while (j >= 0 &&
              (sum[idx[j]] > sum[curr] ||
              (sum[idx[j]] == sum[curr] &&
               nums[idx[j]] > nums[curr]))) {
            idx[j + 1] = idx[j];
            j--;
        }

        idx[j + 1] = curr;
    }

    // Count
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (visited[i] || idx[i] == i)
            continue;

        int cycleSize = 0;
        int j = i;

        while (!visited[j]) {
            visited[j] = 1;
            j = idx[j];
            cycleSize++;
        }

        count += cycleSize - 1;
    }

    return count;
}
