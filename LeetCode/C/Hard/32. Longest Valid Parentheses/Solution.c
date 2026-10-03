int longestValidParentheses(char* s) {
    int close =0;
    int open=0;
    int Max_lenght =0;
    int n = strlen(s);



    for(int i = 0 ; i<n;i++){
        if(s[i]=='('){
            open=open+1;

        }
        else{
            close=close+1;
        }
        if(open==close){
            if(Max_lenght<2*close){
                Max_lenght=2*close;
            }
        }
        else if(close>open){
            open =0;
            close=0;
        }
    }
    open = 0;
    close=0;




    for(int i = n - 1; i >= 0; i--) {
    if(s[i] == '(') {
        open++;
    } else {
        close++;
    }
        if(open==close){
            if(Max_lenght<2*open){
                Max_lenght=2*open ;
            }
        }
        else if (open > close) {
            open = 0;
            close = 0;
        }
    }
return Max_lenght;
    
}