#include<stdio.h>
#include<string.h>
/*
To check for the distinct values there are two techniques:

Technique 1: 
    Store a Data structure and before printing the stirng check if it's already printed, 
        if not in ds -> print & add to ds
        if present in ds -> don't print !!!

Technique 2:
    When you are looping through start to end for finding the combinations:
    check if for any character before the start is it same as the character at start???
    if yes then it's a duplicate string else it's distinct.
     for(k=start_point;k<i;k++) if(str[i]==str[k]) break;
        if(k<i){
            continue;
            // here continue because the string is duplicate & move on to another copy
        }
*/
void _print_distinct_combinations(char *str, int start_point, int end_point){
        if(start_point == end_point) {
            for(int i=0;i<=end_point;i++) printf("%c",str[i]);
            printf("\n");
        return;
    }

    for(int i=start_point;i<=end_point;i++){
        int k = 0;
        for(k=start_point;k<i;k++) if(str[i]==str[k]) break;
        if(k<i){
            continue;
        }
        char a = str[i];
        str[i]= str[start_point];
        str[start_point] = a;
        _print_distinct_combinations(str,start_point+1,end_point);
         a = str[i];
        str[i]= str[start_point];
        str[start_point] = a;
    }
    return;

}

void print_distinct_combinations(char *str, int start_point, int end_point){
    return _print_distinct_combinations(str,start_point, end_point-1);
}

int main(){
    char str[11];
    printf("Enter a string:");
    scanf("%s",str);
    print_distinct_combinations(str,0,strlen(str));
    return 0;
}