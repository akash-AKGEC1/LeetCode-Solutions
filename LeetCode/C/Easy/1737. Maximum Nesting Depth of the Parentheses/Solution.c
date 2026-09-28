int maxDepth(char* s) {
     int count =0;
    int new_count =0;
    for(int i =0;i<strlen(s);i++){
        if(s[i]=='('){
            new_count =new_count +1;
        }
        if(s[i]==')'){
            new_count =new_count -1;
        }
        if(count<new_count){
            count= new_count ;

        }
    }

    return count ;
    
}