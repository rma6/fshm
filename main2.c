# include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	FILE* filein = NULL;
	FILE* fileout = fopen("/mnt/ramdisk/21", "w");
	char* buf = (char*)malloc(sizeof(char)*10);
	while(1)
	{
		filein = fopen("/mnt/ramdisk/12", "r+");
		fgets(buf, 10, filein);
		if(buf[0]=='$')
		{
			buf++;
			filein = fopen("/mnt/ramdisk/12", "w");
			fclose(filein);

			char* req = (char*)malloc(sizeof(char)*10);
			sscanf(buf ,"%s", req);
			if(!strcmp(req, "add"))
			{
				buf+=3;
				int a,b;
				sscanf(buf ,"%i %i", &a, &b);
				fprintf(fileout ,"$%i\n", a+b);
				fclose(fileout);
			}
			break;
		}
		fclose(filein);
	}
}
