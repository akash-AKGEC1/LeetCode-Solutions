int romanToInt(char* s) {
      int result=0;
    for(int i=0;s[i]!='\0';i++){
        int f,d;
        switch (s[i]){
            case 'I' : f=1;
            break;
            case 'V' : f=5;
            break ;
            case 'X' :f=10;
            break ;
            case 'L':f=50;
            break;
            case 'C': f=100;
            break;
            case 'D': f=500;
            break;
            case 'M': f=1000;
            break ;

              

        }//switch wala
        if (s[i + 1] != '\0'){
             switch (s[i+1]){
            
            case 'I' : d = 1;
            break;
            case 'V' : d=5;
            break ;
            case 'X' :d=10;
            break ;
            case 'L':d=50;
            break;
            case 'C': d=100;
            break;
            case 'D': d=500;
            break;
            case 'M': d=1000;
            break ;
        }//iff ke adr wale switch ka hai ye
        if (f<d)
            result=result-f;
            else 
            result=result+f;
        

        }//iff wala
        else {
            result=result  + f;
        }
        
       
        
      

    }//forr wala
    return result;
    
    
}