#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	int c,ret,count=0;
	char fake_name[256],data_name[256],new_name[256],new_file[100],tail_file[3];
	FILE *readFake_fp,*readData_fp,*write_fp;
	printf("Please loading key fake of file name:");
	scanf("%s",fake_name);
	printf("Please loading upack data of file name:");
	scanf("%s",data_name);
	printf("Please input new file name:");
	scanf("%s",new_name);
	
	if((readFake_fp = fopen(fake_name,"rb"))==NULL)
	{
		printf("Cannot open read fake file\n");
		exit(1);
	}
	if((readData_fp = fopen(data_name,"rb"))==NULL)
	{
		printf("Cannot open read data file\n");
		exit(1);
	}

	while((c=fgetc(readFake_fp))!=EOF)
			count++;
	
	fseek(readData_fp,count,SEEK_SET);
	fread(&tail_file,1,3,readData_fp);
	sprintf(new_file,"%s.%s",new_name,tail_file);	
	printf("%s\n",new_file);	
	
	if((write_fp = fopen(new_file,"wb"))==NULL)
	{
		printf("Cannot open write file\n");
		exit(1);
	}
		
	fseek(readData_fp,count+3,SEEK_SET);/*skipping filename extension*/	

	while((c=fgetc(readData_fp))!=EOF){
			fputc(c,write_fp);
	
	}
	
	
	fclose(readFake_fp);
	fclose(readData_fp);
	fclose(write_fp);
			
	printf("\n---Copy compete--%d-\n",count);
	system("pause");
	return 0;		
}
