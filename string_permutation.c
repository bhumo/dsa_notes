#include<stdio.h>
#include<string.h>

void _print_permutation(char *str,int start_point, int end_point){
        if(start_point == end_point) {
            for(int i=0;i<=end_point;i++) printf("%c",str[i]);
            printf("\n");
        return;
    }

    for(int i=start_point;i<=end_point;i++){
        char a = str[i];
        str[i]= str[start_point];
        str[start_point] = a;
        _print_permutation(str,start_point+1,end_point);
         a = str[i];
        str[i]= str[start_point];
        str[start_point] = a;
    }
    return;
}
void print_permutation(char *str, int start_point,int end_point){

    return _print_permutation(str,start_point,end_point-1);
}


int main(){
    char a[11];
    printf("Enter a string:");
    scanf("%s",a);
    int start_point = 0;
    int end_point = strlen(a);
    print_permutation(a,start_point,end_point);
    return 0;
}