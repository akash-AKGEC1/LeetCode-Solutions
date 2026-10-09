int minInsertions(char* s) {
    int n = strlen(s);
    int required =0;
    int open =0;
     

     for(int i = 0; i<n;i++){
        if(s[i]=='('){
            open++;
        }
        else{
            if(i+1<n && s[i+1]==')'){
            i++;
        }
        else{
            required++;
        }
        if(open>0){
            open--;
        }
        else{
            required++;
        }

        }
        

     }    
             required=required+open*2;
     return required;
}