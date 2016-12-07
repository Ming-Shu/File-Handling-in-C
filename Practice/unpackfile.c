#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	int c,ret,fake_size=0;
	int data_endadd,data_size,count=0;
	char fake_name[256],data_name[256],new_name[256],new_file[100],tail_file[3];
	FILE *readData_fp,*write_fp;

	printf("Please loading upack data of file name:");
	gets(data_name);
	printf("Please input new file name:");
	gets(new_name);

	if((readData_fp = fopen(data_name,"rb"))==NULL)
	{
		printf("Cannot open read data file\n");
		exit(1);
	}

	fseek(readData_fp,-sizeof(fake_size),SEEK_END);
	data_endadd = (int)ftell(readData_fp);
	fread(&fake_size,1,sizeof(fake_size),readData_fp);
	fseek(readData_fp,fake_size,SEEK_SET);
	fread(&tail_file,1,3,readData_fp);
	sprintf(new_file,"%s.%c%c%c",new_name,tail_file[0],tail_file[1],tail_file[2]);
	
	printf("%s\n",new_file);	
	
	if((write_fp = fopen(new_file,"wb"))==NULL)
	{
		printf("Cannot open write file\n");
		exit(1);
	}
		
	fseek(readData_fp,fake_size+3,SEEK_SET);/*skipping filename extension*/	
	data_size = data_endadd - (int)ftell(readData_fp);
	while(count++!=data_size){
			c=fgetc(readData_fp);
			fputc(c,write_fp);
	}
	
	fclose(readData_fp);
	fclose(write_fp);
			
	printf("\n---Copy compete---\n");
	system("pause");
	return 0;		
}
