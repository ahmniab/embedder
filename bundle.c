#include <stdio.h>

size_t len(const char *_str)
{
    size_t ln = 0;
    while (_str[ln]) ++ln ;
    ln--;
    return ln;
}

size_t find_name(const char *path){
    size_t start = 0 , end =  len(path);

    for (size_t i = end; i ; i--) 
    {
        if (path[i] == '/' || path[i] == '\\')
        {
            start = i + 1 ;
            break;
        }
        
    }
    
}


int bundle (char in_name[] , char out_name[])
{
    FILE *in = fopen(in_name,"rb");
            if (!in) {
                fprintf(stderr,"file not found !\n");
                return -1;
            }
            // size of the file
            fseek(in, 0L, SEEK_END); 
            size_t fsz = ftell(in) ; 
            fseek(in, 0L, SEEK_SET); 


            FILE *out = fopen(out_name,"w");
                fprintf(out,"#ifndef __BUNDLE \n");    
                fprintf(out,"#define __BUNDLE \n");    
                fprintf(out,"#define FILE_SIZE %zu \n",fsz);    
                fprintf(out,"#define FILE_NAME \"%s\" \n",in_name + find_name(in_name));
                fprintf(out,"unsigned char data[] = {\n");    
                
                while (!feof(in))
                {
                    fprintf(out,"\t");
                    for (size_t i = 0; i < 15 && !feof(in); i++)
                    {
                        fprintf(out,"0x%02x , ",(unsigned char) fgetc(in));
                    }
                    fprintf(out,"\n");
                        
                    
                }
                fprintf(out,"};\n");    
                
                fprintf(out,"#endif // __BUNDLE ");    
            fclose(out);


            
        fclose(in);
}