#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct data
{   int ID;
    int gender;
    double heights;
};

int num=15;
int main(void)
{
    char fname[FILENAME_MAX];
    char buf[256];
    FILE* fp;
    
    int i=0;
    struct data sample[num];
    int g,id;
    double h;
    int w_id;

    printf("input the filename of sample heights ?:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample heights: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }
    
    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d , %lf",&g,&h);
        
        
        sample[i-1].gender = g;
        sample[i-1].heights = h;
        i=i+1;

    }


    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }


   printf("input the filename of sample ID ?:");
    fgets(fname,sizeof(fname),stdin);
    fname[strlen(fname)-1] = '\0';
    printf("the filename of sample ID: %s\n",fname);

    fp = fopen(fname,"r");
    if(fp==NULL){
        fputs("File open error\n",stderr);
        exit(EXIT_FAILURE);
    }

    i=0;

    while(fgets(buf,sizeof(buf),fp) != NULL){
        sscanf(buf,"%d",&id);

        sample[i].ID = id;
        i=i+1;

    }


    if(fclose(fp) == EOF){
        fputs("file close error\n",stderr);
        exit(EXIT_FAILURE);
    }

printf("Which ID's data do you want? : ");
scanf("%d",&w_id);

int j=0;
int n=0;

while(j <= num)
{
if(sample[j].ID == w_id)
{
    if(sample[j].gender==1){
    printf("---\nID : %d\ngender : Male\nheights : %.2lf\n",sample[j].ID,sample[j].heights);
    }
    else{printf("---\nID : %d\ngender : Female\nheights : %.2lf\n",sample[j].ID,sample[j].heights);}
}
else{n=n+1;}
j=j+1;
}

if(n==j)
{ printf("---\nNo data");}

return 0;
}

