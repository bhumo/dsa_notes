#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int count = 0;
void _print_permutation_string(char *seed, char* charset, int set_size, int max_length){

    if(max_length== 0) {
        printf("%s\n",seed);
        count++;
        return;
    }
    int seed_length = strlen(seed);
    char* new_seed = (char *) malloc(sizeof(char)*seed_length+2);
    strcpy(new_seed,seed);
    new_seed[seed_length] = '\0';
    for(int i=0;i<set_size;i++){
        new_seed[seed_length] = charset[i];
        new_seed[seed_length+1] = '\0';
    
        _print_permutation_string(new_seed,charset,set_size,max_length-1);
    }
    free(new_seed);
    return;
}

void print_permutation_string(char* charset,int set_size,int max_length){
  _print_permutation_string("",charset,set_size,max_length);

    return ;
}


int main(){
  char charset[4] = {'0','1','2','3'};
  int size_of_charset = 4;
  int max_length = 3;
  print_permutation_string(charset,size_of_charset,max_length); // charset address, size of charset, max_length
  printf("Number of combinations: %d\n",count);  
    return 0;
}