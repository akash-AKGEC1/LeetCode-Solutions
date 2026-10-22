

    /* isme dikat ye hai ki ye permutation nahi check kr raha */




//     int n = numsSize;
// // if alraedy sorted 
//     if (checker(nums, n)) {
//         return 0;
//     }

//     int *arr = (int*)malloc(n * sizeof(int));
//     if (arr == NULL) return -1;
// // pura new array me copy kr lete hnai pahle 
//     for (int i = 0; i < n; i++) {
//         arr[i] = nums[i];
//     }
// // reverse ko bs ekk bar hi karna hai isliye <@ use karenge 
//     for (int rev = 0; rev < 2; rev++) {
//         for (int rot = 0; rot < n; rot++) {
//             if (checker(arr, n)) {
//                 free(arr);
//                 return rev + rot;
//             }

//             int first = arr[0];
//             for (int i = 0; i < n - 1; i++) {
//                 arr[i] = arr[i + 1];
//             }
//             arr[n - 1] = first;
//         }

//         for (int i = 0; i < n; i++) {
//             arr[i] = nums[i];
//         }

//         if (rev == 0) {
//             for (int i = 0, j = n - 1; i < j; i++, j--) {
//                 int temp = arr[i];
//                 arr[i] = arr[j];
//                 arr[j] = temp;
//             }
//         }
//     }

//     free(arr);
//     return -1;
int minOperations(int* nums, int numsSize) {
    int n = numsSize;
// agar  ekk hi number ho to kya hi sort karenge usko
    if (n <= 1) return 0;

    int zeroIndex = -1;

    for (int i = 0; i < n; i++) {
        if (nums[i] == 0) {
            zeroIndex = i;
            break;
        }
    }

    int increasing = 1;
    int decreasing = 1;

    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;

        if (nums[next] != (nums[i] + 1) % n)
            increasing = 0;

        if (nums[next] != (nums[i] - 1 + n) % n)
            decreasing = 0;
    }

    int ans = n + 2;

    if (increasing) {
        int rotations = zeroIndex;
        int reverseWay = n - zeroIndex + 2;

        ans = rotations < reverseWay ? rotations : reverseWay;
    }

    if (decreasing) {
        int k = n - 1 - zeroIndex;
        int reverseWay = 1 + (k < n - k ? k : n - k);

        if (reverseWay < ans)
            ans = reverseWay;
    }

    return (increasing || decreasing) ? ans : -1;
}