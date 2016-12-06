#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	int c,ret,count=0;

	char fake_name[256],data_name[256],new_name[256],tail_file[3],*fake_readP,*data_readP;
	FILE *readFake_fp,*readData_fp,*write_fp;
	printf("Please loading fake of file name:");
	scanf("%s",fake_name);
	printf("Please loading packed data of file name:");
	scanf("%s",data_name);
	printf("Please input new file name:");
	scanf("%s",new_name);
	
	fake_readP = fake_name;
	data_readP = data_name;
	while(*fake_readP++ != '.' );
	while(*data_readP++ != '.' );
	sprintf(new_name,"%s.%s",new_name,fake_readP);
	
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
	if((write_fp = fopen(new_name,"wb"))==NULL)
	{
		printf("Cannot open write file\n");
		exit(1);
	}
	
	while((c=fgetc(readFake_fp))!=EOF){
			fputc(c,write_fp);
			count++;
	}
	
	fseek(write_fp,count,SEEK_SET);
	fwrite(data_readP,1,3,write_fp);/*save filename extension*/		
	fseek(write_fp,count+3,SEEK_SET);
	
	while((c=fgetc(readData_fp))!=EOF){
			fputc(c,write_fp);
	}
	
	fclose(readFake_fp);
	fclose(readData_fp);
	fclose(write_fp);
			
	printf("\n---Pack compete--%d-\n",count);
	system("pause");
	return 0;		
}
