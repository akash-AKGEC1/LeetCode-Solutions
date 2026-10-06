int minAddToMakeValid(char* s) {
    int n = strlen(s);
    int required =0;
    int open =0;



    for(int i = 0 ;i<n ;i++){
        if(s[i]=='('){
            open ++;
            
        }
        if(s[i]==')'){
            // open --;
            if(open > 0)
              {
                open--;
              }
            else
            {
                required++;
            }
        }
    }
    required =required+open;
    
    return required;
    
}
