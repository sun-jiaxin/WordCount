#include<stdio.h>
#include<string.h>
int main (int args,char* argv[])
{
	char path[100]="test.txt";
	FILE*fp;
	errno_t err;
	int i=0;
	char tmp;
	int len=strlen(argv[2]);
	strcpy_s(path,len+1,argv[2]);
	if(!(err=fopen_s(&fp,path,"r")))
	{
		if(strcmp(argv[1],"-c")==0)
		{
			while(1)
			{
				tmp=fgetc(fp);
				if(tmp!=EOF)
				{
					i++;
				}
				else
				{
					printf("\n�ַ�����%d\n",i);
					break;
				}
			}
		}
		else if(strcmp(argv[1],"-w")==0)
		{
			while(1)
			{
				tmp=fgetc(fp);
				if(tmp!=EOF)
				{
					if(tmp==','||tmp=='\n'||tmp==' ')
					{
						i++;
					}
				}
				else
				{
					i++;
					printf("\n��������%d\n",i);
					break;
				}
			}
		}
		else
		{
			printf("���Ʋ�������������");
		}
	}
	else
	{
		printf("�ļ���ʧ��\n");
		return 0;
	}
	return 0;
}