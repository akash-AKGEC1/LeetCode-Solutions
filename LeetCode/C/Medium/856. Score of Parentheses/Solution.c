int scoreOfParentheses(char* s) {
    int n = strlen(s);
    int score = 0;
    int depth = 0;

    for (int i = 0; i < n; i++) {

        if (s[i] == '(') {
            depth++;
        }

        else {
            if (s[i - 1] == '(') {

                int value = 1;

                for (int j = 1; j < depth; j++) {
                    value = value * 2;
                }

                score = score + value;
            }

            depth--;
        }
    }

    return score;
}