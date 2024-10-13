#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *folder;
    struct dirent * entry;
    struct stat file_stat;
    char filepath[1000];

    int ll = 0;
    
    char *path = ".\\";
    if(argc>1){
      for(int i=1; i<=argc-1; i++){
       if(strcmp(argv[i], "-l")==0){
       ll = 1; 
       }
       else{
          path = argv[i];
        }
      }
      if(path[-2]!='\\'){
        strcat(path,"\\"); 
      }
    }
    
    folder = opendir(path);
    if(folder == NULL){
        printf("%s is not a valid path.\n", path);
        return(1);
    }
    else{
        while ((entry = readdir(folder))){
          sprintf(filepath, "%s\%s", path, entry->d_name);
          if(ll ==1 && stat(filepath,&file_stat) == 0){
            printf("%d\t%s\n", file_stat.st_size,entry->d_name);
          }
          else{
              printf("%s\t", entry->d_name);
          }
        }
    }
    closedir(folder);

    return(0);
}
