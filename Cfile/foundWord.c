#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define TRUE 1
#define FALSE 0
int main(int argc,char * args[]){

	if(argc != 4){
    printf("Lutfen Belirtilen Parametreleri Verin");
		return -1;
	}
	int fp,i,countLetter=0;
	char *search = args[1];
	char *change = args[2];
	char *file = args[3];
	int chanLength = strlen(change);
	int searLength=strlen(search);
	char tmp[searLength];
	int fd = open(file,O_RDWR);
	int totalSize = lseek(fd,0,SEEK_END);
	printf("Search length: %d\nTotal size: %d\nFile description : %d\n",searLength,totalSize,fd);
	lseek(fd,0,SEEK_SET);
	if(fd > 0){
        while(TRUE){
            int size = read(fd, tmp, searLength);
            if (size == 0)
                break;
            if(strcmp(tmp,search)==0){
                    lseek(fd,-searLength,SEEK_CUR);
                    for(i=0;i<searLength;i++)
                        write(fd," ",1);
                    lseek(fd,-searLength,SEEK_CUR);
                    write(fd,change,chanLength);
                    countLetter++;
            }
            int map = lseek(fd,-searLength+1,SEEK_CUR);
            if(map+searLength >= totalSize)
                break;
        }
        if(countLetter!=0){
            printf("{ %d } Kadar bulundu ve degistirildi",countLetter);
        }
	}
	else{
        printf("file description cikartilamadi");
	}
}
