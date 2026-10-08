char* removeOuterParentheses(char* s) {
    int n = strlen(s);
    int depth =0 ;
    char *result =(char*)malloc(n*sizeof(char));
    int j=0;


    for(int i =0;i<n ;i++){
        if(s[i]=='('){
            depth++;
            if(depth >1){
                result[j]=s[i];
                j++;
            }
            
                }
                if(s[i]==')'){
                depth-- ;
                if(depth>0 ){
                    result[j]=s[i];
                    j++;
            }
        }
    }
    result [j]='\0';
    return result;
    
}