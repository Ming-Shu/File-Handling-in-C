#include<stdio.h>
#include<stdlib.h>
#include <stdint.h>

#define TRACK_NUM 10000

#pragma pack(push) 
#pragma pack(1)  
struct collect{
	uint32_t count;
	uint64_t time;
};
#pragma pack(pop)

int main (void)
{
	struct collect field[TRACK_NUM]={0};
	int num,n,m=0;
	FILE *r_fp,*w_fp;
	char name[50];
	
	printf("Please input the filename:");
	scanf("%s",name);
	
	if((r_fp = fopen(name,"rb"))==NULL)
		exit(1);
	if((w_fp = fopen("read_binary.txt","w"))==NULL)
		exit(1);				

			
	for (n=0;n<TRACK_NUM;n++){
		fseek(r_fp,n*sizeof(struct collect),SEEK_SET);
		fread(&field[n],sizeof(struct collect),1,r_fp);
		if(field[n].count!=0){
			printf("NO.%d\n%x (%d)\n%I64x (%d)\n\n",n,field[n].count,field[n].count,field[n].time,field[n].time);
			fprintf(w_fp,"NO.%d\n%x (%d)\n%I64x (%d)\n\n",n,field[n].count,field[n].count,field[n].time,field[n].time);
		}	

    }


	fclose(r_fp);
	fclose(w_fp);
	system("pause");	
	return 0; 
}
