#include <stdio.h>

#include <string.h>



void timeConversion(char* s) {
    int hour, minute , second;
    char period[3];
    sscanf(s, "%d:%d:%d%s",&hour,&minute,&second,period);
    if(strcmp(period, "AM")==0){
        if(hour ==12)hour =0;
    }else if (strcmp(period,"PM")==0){
        if(hour !=12)hour +=12;
    }
    printf("%02d:%02d:%02d\n",hour,minute,second);
    
}
int main(){
    char s[11];
    scanf("%s",s);
    timeConversion(s);
    return 0;
}
