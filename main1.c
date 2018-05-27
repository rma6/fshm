# include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* file = fopen("/mnt/ramdisk/12", "w");

	char* inst = (char*)malloc(sizeof(char)*10);
	char* buf = (char*)malloc(sizeof(char)*10);
	int result;

	fgets(inst, 10, stdin);
	fputs(inst, file);
	fclose(file);
	while(1)
	{
		file = fopen("/mnt/ramdisk/21", "r+");
		fgets(buf, 10, file);
		if(buf[0]=='$')
		{
			buf++;
			file = fopen("/mnt/ramdisk/21", "w");
			fclose(file);

			sscanf(buf, "%i", &result);
			printf("%i", result);
			break;
		}
		fclose(file);
	}
}
