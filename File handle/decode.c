#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

#define FILE_NUM 32
#define TRACK_NUM 1000

#pragma pack(push) 
#pragma pack(1)  
struct collect{
	uint32_t count;
	uint64_t time;
};
#pragma pack(pop)

int main (void)
{
	struct collect field[FILE_NUM][TRACK_NUM]={0};
	struct collect sum[TRACK_NUM]={0};
	int n=0,m=0;
	FILE *r_fp,*w_fp;
	char name[100];
	char dat[100];
	printf("Please input the filename of folder of path:");
	scanf("%s",name);	
	if((w_fp = fopen("decode_test.txt","w"))==NULL)
		exit(1);

	for (n=0;n<FILE_NUM;n++)
	{
		sprintf(dat,"%s\\%02d.dat",name,n);					
		if((r_fp = fopen(dat,"rb"))==NULL){
			continue;
		}else{
			printf("The file :%s\n",dat);
			fprintf(w_fp,"The file :%s\n",dat);					
			for (m=0;m<TRACK_NUM;m++){
				fseek(r_fp,m*sizeof(struct collect),SEEK_SET);
				fread(&field[n][m],sizeof(struct collect),1,r_fp);
				if(field[n][m].count!=0){
					printf("NO.%d\n%x (%d)\n%I64x (%d)\n\n",m,field[n][m].count,field[n][m].count,field[n][m].time,field[n][m].time);
					fprintf(w_fp,"NO.%d\n%x (%d)\n%I64x (%d)\n\n",m,field[n][m].count,field[n][m].count,field[n][m].time,field[n][m].time);
				}//if	
				sum[m].count=sum[m].count+field[n][m].count;
				sum[m].time=sum[m].time+field[n][m].time;		
    		}//for
		}//else
		
		fclose(r_fp);
	}//for
		
		printf("------------------------------------------------\n");		
		for (m=0;m<TRACK_NUM;m++){
			if(sum[m].count){
				printf("The total value:NO.%d\n%x (%d)\n%I64x (%d)\n\n",m,sum[m].count,sum[m].count,sum[m].time,sum[m].time);
				fprintf(w_fp,"The total value:NO.%d\n%x (%d)\n%I64x (%d)\n\n",m,sum[m].count,sum[m].count,sum[m].time,sum[m].time);
			}//if
		}//if
		fclose(w_fp);
	system("pause");	
	return 0; 
}
