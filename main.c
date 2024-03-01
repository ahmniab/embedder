#include <stdio.h>
#include "bundle.h"

int main(int argc , char* argv[])
{
    if (argc != 3)
    {
        fprintf(stderr ,"%s <input's name> <output's name>\n",argv[0]);
        return 0;
    }
    
    if(bundle (argv[1] , argv[2]) == -1){
        return 1 ;
    }

}


