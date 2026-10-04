bool checkValidString(char* s) {
    
    int n = strlen(s);
    int min = 0;
    int max = 0;

    for (int i = 0; i<n; i++) {
        if (s[i] == '(') {
            min++;
            max++;
        }
        else if (s[i] == ')') {
            min--;
            max--;
        }
        else if (s[i] == '*') {
            min=min-1;
            max=max+1;
        }

        if (max < 0) {
            return false;
        }

        if (min < 0) {
            min = 0;
        }
    }

    return min==0;
}
