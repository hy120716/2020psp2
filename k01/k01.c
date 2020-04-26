#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
double n;
extern double ave_online(double val,double ave);
extern double var_online(double val,double ave,double _2ave);

int main(void)
{
    double val,ave=0,var=0,_2ave=0,s_var;
    char fname[FILENAME_MAX];
    char buf[256];
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
         
        n=n+1;

         var=var_online(val,ave,_2ave);
         ave=ave_online(val,ave);
         _2ave=ave_online(pow(val,2),_2ave);
        
        
        }

    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

    printf("%f\n",n);
    s_var=(n/(n-1))*var;
    
    printf("Average: %f\n",ave);
    printf("Var: %f\n",var);

    printf("suitei_Average: %f\n",ave);
    printf("suitei_Var: %f\n",s_var);
    

    return 0;


}

double ave_online(double val,double ave)
{   double average;
    average=((n-1)*ave)/n + val /n ;
       
    return average;
}
double var_online(double val,double ave,double _2ave)
{   double var;
    var=((n-1)*_2ave)/n + pow(val,2)/n - pow(((n-1)*ave)/n + val/n,2);
    return var;
}
