#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int n;
extern double ave_online(double val,double ave)
{   ave=((n-1)*ave)/n + val /n ;
       
    return ave;
}
extern double var_online(double val,double ave,double _2ave)
{   double var;
    var=((n-1)*_2ave)/n + pow(val,2) - pow(((n-1)*ave)/n + val/n,2);
    return var;
}

int main(void)
{
    double val,ave;
    char fname[FILENAME_MAX];
    char buf[300];
    FILE* fp;

    printf("input the filename of sample:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%lf",&val);
         ave=ave_online(val,ave);
         n=n+1;


    



    }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("Average: %f\n",ave);

    return 0;


}

   