#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <sys/shm.h>
#include <dirent.h>
#include <pwd.h>
#include <grp.h>

struct dirent * p ;
DIR *dir ;
struct stat x ;
int sum = 0;
char file[1000];

int check_obj(char *s)
{
	for(int i=0;i<strlen(s);i++)
		if(s[i] == '.')
			return 1;
	return 0;
}

void type_file(char *s)
{
	stat(s,&x);
	if(x.st_mode & S_IXOTH && (s[0] != '.'))
		sprintf(file,"%s%s%s%s%s\t","\033[1m","\033[032m",s,"\033[0m","\033[0m");
	else{
	if (S_ISREG(x.st_mode))               	// Regular file
	{
        	printf("-");
		sprintf(file,"%s",s);
	}
    	
       	else if (S_ISDIR(x.st_mode)) 		// Directory file
	{
		printf("d");
		sprintf(file,"%s%s%s","\033[34m",s,"\033[0m");
        }

      
       	else if (S_ISCHR(x.st_mode)) 		// Character device file
	{
		printf("c");
                sprintf(file,"%s",s);
        }

     
	else if (S_ISBLK(x.st_mode)) 		// Block file
	{
		printf("b");
                sprintf(file,"%s",s);
        }

       
	else if (S_ISFIFO(x.st_mode)) 		// Named pipe
	{
		printf("p");
                sprintf(file,"%s%s%s","\033[33m",s,"\033[0m");
        }

     	
	else if (S_ISLNK(x.st_mode)) 		// Symbolic/Soft link or hard link
	{
        	printf("l");
                sprintf(file,"%s%s%s","\033[36m",s,"\033[0m");
        }

     	
	else if (S_ISSOCK(x.st_mode)) 		// Socket file
	{
        	printf("s");
                sprintf(file,"%s",s);
        }
	else
		printf("Linux can't recognize the file\n");
	}
}

void permissions (char *s)
{
	stat(s,&x);

	(x.st_mode & S_IRUSR) ? printf("r") : printf("-");           	// owner permissions
	
	(x.st_mode & S_IWUSR) ? printf("w") : printf("-");		
	
	(x.st_mode & S_IXUSR) ? printf("x") : printf("-");		

	(x.st_mode & S_IRGRP) ? printf("r") : printf("-");		// group permissions
        
        (x.st_mode & S_IWGRP) ? printf("w") : printf("-");
        
        (x.st_mode & S_IXGRP) ? printf("x") : printf("-");
        
	(x.st_mode & S_IROTH) ? printf("r") : printf("-");		// other permission
        
        (x.st_mode & S_IWOTH) ? printf("w") : printf("-");
        
      	(x.st_mode & S_IXOTH) ? printf("x") : printf("-");
                
	
}

void print_month(char *s)         // prints day , month , date , hrs:min:sec , year                             
{ 
	for(int i=0;i<strlen(s);i++)
		if(s[i] != '\n')
			printf("%c",s[i]);
}

void lss_al(char *s)
{
	if(strlen(s) <= 3)
	{
		while((p = readdir(dir)) != NULL)
        	{
			if((strlen(s) == 2) && (p->d_name[0] == '.'))  // if \"./lss -l\" skip directories
				continue;
			type_file(p->d_name);                     // type of file
			permissions(p->d_name);                   // file permissions
			printf("\t");

			stat(p->d_name,&x);
			printf("%ld\t",x.st_nlink);                // no. of hard links

			struct passwd *pw = getpwuid(x.st_uid);   
			struct group *gr = getgrgid(x.st_gid);
			printf("%s\t", pw->pw_name);               // file's owner
    			printf("%s\t", gr->gr_name);               // file's group

			printf("%ld\t ",x.st_size);               // size of the file

			print_month(ctime(&x.st_mtime));          // print time
			printf("\t");
			
			sum = sum + x.st_blocks;		  // counting blocks allocated for the directory.
		                 
                        printf("%s\n",file);                      // name of the file
		}
		printf("total %d",sum/2);
	}
	else
	{
		perror("invalid operator......\n");
		exit(0);
	}
}

void lss()
{
	while((p = readdir(dir)) != NULL)
        {
		if(p->d_name[0] == '.')
			continue;
		if(check_obj(p->d_name))		
                	printf("%s\t",p->d_name);
		else
			printf("%s%s%s\t","\033[0;32m",p->d_name,"\033[0m");
        }

}

int main(int argc,char *argv[])
{
	dir = opendir(".");
	if(argc == 1)
	{
		lss();
		printf("\n");
	}
	else
	{
		lss_al(argv[1]);
		printf("\n");
	}

}
