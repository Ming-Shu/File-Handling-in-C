#include<stdio.h>
#include<stdlib.h>

int main (void)
{
	int c,ret,fake_size=0;

	char fake_name[256],data_name[256],new_name[256],*fake_readP,*data_readP;
	FILE *readFake_fp,*readData_fp,*write_fp;
	printf("Please loading fake of file name:");
	gets(fake_name);
	printf("Please loading packed data of file name:");
	gets(data_name);
	printf("Please input new file name:");
	gets(new_name);
	
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
	
	while((c=fgetc(readFake_fp))!=EOF){/*Write fake file*/
		fputc(c,write_fp);
		fake_size++;
	}

	fseek(write_fp,fake_size,SEEK_SET);
	fwrite(data_readP,1,3,write_fp);/*save filename extension*/		
	fseek(write_fp,fake_size+3,SEEK_SET);
	
	while((c=fgetc(readData_fp))!=EOF)/*Write data file*/
			fputc(c,write_fp);

	fseek(write_fp,0,SEEK_END);
	fwrite(&fake_size,1,sizeof(fake_size),write_fp);
	fclose(readFake_fp);
	fclose(readData_fp);
	fclose(write_fp);
			
	printf("\n---Pack compete--%d-\n",fake_size);
	system("pause");
	return 0;		
}
