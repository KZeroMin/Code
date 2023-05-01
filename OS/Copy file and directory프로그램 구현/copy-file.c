#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>  //open()
#include <unistd.h> //lseek(), read(), write(), close()
#include <string.h>
#include <sys/types.h>  //stat()
#include <sys/stat.h>   //stat()
#include <dirent.h> //mkdir(), opendir(), readdir()

#define FILELEN 256
#define BUFSIZE 2048
char buf[BUFSIZ];
char option[10];
char route[FILELEN] = "./";
char SourceFile[FILELEN], TargetFile[FILELEN], SourceDirectory[FILELEN], TargetDirectory[FILELEN];
int fd, f_target, read_bytes;


//function: Check whether the copy object is a directory
int Check_Dir(char *path)
{
    struct stat buf;
    lstat(path,&buf);

    return S_ISDIR(buf.st_mode);
}

//command: -f option
// function: copying source files
void Copy_file(char *Source, char *Target){

    struct stat buffer; //buffer for obtaining permissions for source file

    strcpy(SourceFile, Source);    //Source file name
    strcpy(TargetFile, Target);    //Target file name

    stat(SourceFile, &buffer);

    fd = open(SourceFile, O_RDWR);  //open source file
    if(fd == -1){
        perror(SourceFile); //failure to open source file causes error
        exit(1);
    }
    f_target = open(TargetFile, O_RDWR | O_CREAT, buffer.st_mode);  //open target file
    lseek(fd, 0, SEEK_SET);

    while((read_bytes = read(fd, buf, BUFSIZE)) > 0){   //copy the contents of the source file to the target file
        write(f_target, buf, read_bytes);
    }
    chmod(TargetFile, buffer.st_mode);  //configure with the same permissions as the source file

    close(fd);
    close(f_target);
}

//command: -fv option
// function: copying source files + print out what is being done
void V_Copy_file(char *Source, char *Target){

    struct stat buffer; //buffer for obtaining permissions for source file

    strcpy(SourceFile, Source);    //Source file name
    strcpy(TargetFile, Target);    //Target file name
    fd = open(SourceFile, O_RDWR);  //open source file
    if(fd == -1){
        perror(SourceFile); //failure to open source file causes error
        exit(1);
    }
    stat(SourceFile, &buffer);
    f_target = open(TargetFile, O_RDWR | O_CREAT | O_EXCL, buffer.st_mode); //open target file
    lseek(fd, 0, SEEK_SET);

    while((read_bytes = read(fd, buf, BUFSIZE)) > 0){   //copy the contents of the source file to the target file
        write(f_target, buf, read_bytes);
    }
    chmod(TargetFile, buffer.st_mode);  //configure with the same permissions as the source file
    printf("Copy File: %s -> %s\n", SourceFile, TargetFile);

    close(fd);
    close(f_target);
}

//command: -m option
//function: copy several files to the target directory
void Copy_to_Dir(char *TargetDirectory, char *SourceFile){
    strcpy(route, "./");
    strcpy(TargetFile, SourceFile); //set the target file to the same name as the source fiel
    strcat(route, TargetDirectory);
    strcat(route, "/");
    strcat(route, TargetFile);   //make target directory route
    Copy_file(SourceFile, route);
}

//command: -mv option
//function: copy several files to the target directory + print out what is being done
void V_Copy_to_Dir(char *TargetDirectory, char *SourceFile){
    strcpy(route, "./");
    strcpy(TargetFile, SourceFile); //set the target file to the same name as the source fiel
    strcat(route, TargetDirectory);
    strcat(route, "/");    //make target directory route
    strcat(route, TargetFile);
    V_Copy_file(SourceFile, route);
}

//command: -d option
//copy all files belonging to the directory are in the source directory
void Copy_Dir(char *SourceDirectory, char *TargetDirectory){
    struct stat buffer;
    struct stat path_buf;
    stat(SourceDirectory, &buffer);

    DIR *dir_info = NULL;
    struct dirent *dir_entry = NULL;
    char path[1000]; //variable to store source directory path
    char newpath[1000]; //variable to store target directory path

    dir_info = opendir(SourceDirectory);

    if(dir_info != NULL){
        while((dir_entry = readdir(dir_info)) != NULL){ //read source directory
            mkdir(TargetDirectory, buffer.st_mode);   //make target directory
            chmod(TargetDirectory, buffer.st_mode); //configure with the same permissions as the source directory
            if((strcmp(dir_entry->d_name, ".") != 0) && (strcmp(dir_entry->d_name, "..") != 0) && (strcmp(dir_entry->d_name, ".DS_Store") != 0)){
                sprintf(path, "%s/%s", SourceDirectory, dir_entry->d_name); //make path (Source Dir route)
                sprintf(newpath, "%s/%s", TargetDirectory, dir_entry->d_name);  //make newpath (Target Dir route)

                if(Check_Dir(path)){
                    mkdir(newpath, 0777);
                    stat(path, &path_buf);
                    chmod(newpath, path_buf.st_mode); //configure with the same permissions as the source directory
                    Copy_Dir(path, newpath);
                }
                else{
                    Copy_file(path, newpath);
                }
            }

        }
    }

}

//command: -d option
//copy all files belonging to the directory are in the source directory + print out what is being done
void V_Copy_Dir(char *SourceDirectory, char *TargetDirectory){
    struct stat buffer;
    struct stat path_buf;
    stat(SourceDirectory, &buffer);

    DIR *dir_info = NULL;
    struct dirent *dir_entry = NULL;
    char path[1000]; //variable to store source directory path
    char newpath[1000]; //variable to store target directory path

    dir_info = opendir(SourceDirectory);

    if(dir_info != NULL){
        while((dir_entry = readdir(dir_info)) != NULL){ //read source directory
            mkdir(TargetDirectory, buffer.st_mode);   //make target directory
            chmod(TargetDirectory, buffer.st_mode); //configure with the same permissions as the source directory
            if((strcmp(dir_entry->d_name, ".") != 0) && (strcmp(dir_entry->d_name, "..") != 0) && (strcmp(dir_entry->d_name, ".DS_Store") != 0)){
                sprintf(path, "%s/%s", SourceDirectory, dir_entry->d_name); //make path (Source Dir route)
                sprintf(newpath, "%s/%s", TargetDirectory, dir_entry->d_name);  //make newpath (Target Dir route)

                if(Check_Dir(path)){
                    mkdir(newpath, 0755);
                    stat(path, &path_buf);
                    chmod(newpath, path_buf.st_mode); //configure with the same permissions as the source directory
                    V_Copy_Dir(path, newpath);
                }
                else{
                    V_Copy_file(path, newpath);
                }
            }

        }
    }

}

int main(int argc, char *argv[]) {

    int opt;
    int flag_f = 0, flag_m = 0, flag_d = 0, flag_v = 0;

    while((opt = getopt(argc, argv, "fmdv")) != -1) {
        switch (opt) {
            case 'f': flag_f = 1; break;
            case 'm': flag_m = 1; break;
            case 'd': flag_d = 1; break;
            case 'v': flag_v = 1; break;
            case '?': printf("Unknown flag : %c \n", optopt);
        }
    }
    
    //call a function that matches the options entered by the user
    //using getopt
    if (flag_f == 1 && flag_v == 0){
        Copy_file(argv[2], argv[3]);
    }
    else if(flag_f == 1 && flag_v == 1){
        V_Copy_file(argv[2], argv[3]);
    }
    if (flag_m == 1 && flag_v == 0){
        strcpy(TargetDirectory, argv[argc-1]);  //target directory
        mkdir(TargetDirectory, 0777);   //make target directory
        for(int i=2; i<argc-1; i++){
            Copy_to_Dir(TargetDirectory, argv[i]);
        }
    }
    else if (flag_m == 1 && flag_v == 1){
        strcpy(TargetDirectory, argv[argc-1]);  //target directory
        mkdir(TargetDirectory, 0777);   //make target directory
        for(int i=2; i<argc-1; i++){
            V_Copy_to_Dir(TargetDirectory, argv[i]);
        }
    }
    if (flag_d == 1 && flag_v == 0){
        strcpy(SourceDirectory, argv[2]);   //copy destination directory
        strcpy(TargetDirectory, argv[3]);  //target directory
        Copy_Dir(SourceDirectory, TargetDirectory);
    }
    else if (flag_d == 1 && flag_v == 1){
        strcpy(SourceDirectory, argv[2]);   //copy destination directory
        strcpy(TargetDirectory, argv[3]);  //target directory
        V_Copy_Dir(SourceDirectory, TargetDirectory);
    }
    
    return 0;
}