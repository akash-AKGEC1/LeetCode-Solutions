long long minSumSquareDiff(int* nums1, int nums1Size, int* nums2, int nums2Size, int k1, int k2) {
int n = nums1Size;
long long k = (long long)k1 + k2;
int diff[100001] = {0};
int maxDiff = 0;

for (int i = 0; i < n; i++) {
    int d = abs(nums1[i] - nums2[i]);
    diff[d]++;

    if (d > maxDiff) {
        maxDiff = d;
    }
}

if (k >= n * 100000LL) {
    return 0;
}

for (int d = maxDiff; d > 0 && k > 0; d--) {
    if (diff[d] == 0) {
        continue;
    }

    int take = diff[d];
    if ((long long)take > k) {
        take = (int)k;
    }

    diff[d] -= take;
    diff[d - 1] += take;
    k -= take;
}

long long ans = 0;

for (int d = 0; d <= maxDiff; d++) {
    ans += (long long)d * d * diff[d];
}

return ans;

}