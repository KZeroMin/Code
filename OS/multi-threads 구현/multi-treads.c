#define _GNU_SOURCE
#include <stdio.h> 
#include <stdlib.h>
#include <fcntl.h>  
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>

#define FILELEN 256
#define BUFSIZE 1024

pthread_mutex_t mutex_lock;
sem_t empty;
sem_t full;

char SourceDirectory[FILELEN];
char Source_path[10] = ".";
char arr[1000][BUFSIZE];    // Array to store the path list
//char func_path[BUFSIZE];    
char SearchWord[BUFSIZ];    //  Save the word to search
char buf[BUFSIZ];
int idx = 0;    // Variables that manage the index of the arr arrays
int indx = 0;   // Variables that manage loops where threads work
int in = 0; // tail or rear
int out = 0;    // head or front
int buffer_size = 0;
int thread_num = 0;
int wordCount = 0;
int fileCount = 0;

// Bounded buffer item structure
typedef struct{
    char path[BUFSIZE];
} Buffer;

// function: Check whether the copy object is a directory
int Check_Dir(char *path)
{
    struct stat buf;
    lstat(path,&buf);

    return S_ISDIR(buf.st_mode);
}


// function: Exploring Directory
void Dir_explore(char *SourceDirectory, char arr[][BUFSIZE]){
    DIR *dir_info = NULL;
    struct dirent *dir_entry = NULL;
    char path[BUFSIZE]; // variable to store source directory path
    dir_info = opendir(SourceDirectory);

    if(dir_info != NULL){
        while((dir_entry = readdir(dir_info)) != NULL){
            if((strcmp(dir_entry->d_name, ".") != 0) && (strcmp(dir_entry->d_name, "..") != 0) && (strcmp(dir_entry->d_name, ".DS_Store") != 0)){
                sprintf(path, "%s/%s", SourceDirectory, dir_entry->d_name); //make path (Source Dir route)

                if(Check_Dir(path)){
                    Dir_explore(path, arr);  // Navigating if a folder exists in that path
                }
                else{
                    for(int i = 0; i< BUFSIZE; i++){
                        arr[idx][i] = path[i];
                    }
                    idx++;
                }
            }
        }
    }
}

// function: Read a file, Counts the number of words, return
int readFile(char *PATH){
    int Count = 0; // word count

    FILE *fp = fopen(PATH, "r");

    while(feof(fp) == 0){
        fgets(buf, sizeof(buf), fp);

        char *pt = strcasestr(buf, SearchWord); // Search target word
        while(pt != NULL){
            Count += 1; // if a word exists, +1
            pt = strcasestr(pt+1, SearchWord);  // Go next one space and find word
        }
    }

    return Count;


}

void *test(void *data){
    Buffer *buffer = (Buffer *)data;
    Buffer item_produced;
    Buffer item_consumed;

    BACK:
    // Producer
    sem_wait(&empty);   // Acquire empty semaphore
    pthread_mutex_lock(&mutex_lock);    // Acquire mutex lock to protect bounded buffer
    strcpy(item_produced.path, arr[indx]);
    buffer[in] = item_produced; // Put the item in the buffer (ENQUEUE)
    in = (in + 1) % buffer_size;    // Adjust the 'in' value
    indx++;
    sleep(1);
    pthread_mutex_unlock(&mutex_lock);  // Release mutex lock
    sem_post(&full);    // Release full


    // Consumer
    sem_wait(&full);    // Acquire full semaphore
    pthread_mutex_lock(&mutex_lock);    // Acquire mutex lock to protect bounded buffer
    int word_Count = 0;
    strcpy(item_consumed.path, buffer[out].path);   // Remove item from buffer (DEQUEUE)
    word_Count = readFile(item_consumed.path);  // Running readFile()
    wordCount += word_Count;
    printf("[Thread %lu - %d]  %s : %d found\n", pthread_self(), fileCount, item_consumed.path, word_Count);
    out = (out + 1) % buffer_size;  // Adjust the 'out' value
    fileCount++;
    sleep(1);
    pthread_mutex_unlock(&mutex_lock);  // Release mutex lock
    sem_post(&empty);   // Release empty
    
    if(indx < idx-(thread_num-1)){  // If there are still have files to process, go back to top
        goto BACK;
    }
    else if(indx == idx){   // Shut down the threads when process done with all files
        pthread_exit(NULL);
    }
}

// function: Print total wordCount, file number
void *PrintCount(){
    printf("Total count: %d (Num files=%d)\n", wordCount, fileCount);
}


// function: Print the programe usage
void Usage(const char *param){
    printf("Usage: %s\n", param);
        printf("  -b : bounded buffer size\n");
        printf("  -t : number of threads searching word (except for main thread\n");
        printf("  -d : search directory\n");
        printf("  -w : search word\n");
}


int main(int argc, char *argv[]){

    int opt;
    int BUFFER_SIZE;    // Bounded buffer size
    int Thread_NUM; // Number of Threads
    int flag_error = 0;
    
    if(argc<8){
        Usage(argv[0]);
        return 0;
    }

    while((opt = getopt(argc, argv, "b:t:d:w")) != -1) {
        switch (opt) {
            case 'b': BUFFER_SIZE = atoi(argv[2]); buffer_size = BUFFER_SIZE; break;
            case 't': Thread_NUM = atoi(argv[4]); thread_num = Thread_NUM; break;
            case 'd': strcpy(SourceDirectory, argv[6]); strcat(Source_path, SourceDirectory); break;    // Source_path: 초기 주어진 경로
            case 'w': strcpy(SearchWord, argv[8]); break;
            default: Usage(argv[0]); printf("**Please restart!(Ctrl + C)\n\n"); break;
        }
    }

    printf("Buffer size = %d, Num threads = %d, Directory = %s, SearchWord = %s\n", BUFFER_SIZE, Thread_NUM, SourceDirectory, SearchWord);

    Dir_explore(Source_path, arr);  // Navigate to all files and folders in the path user entered, and ssave the path to the array, Stored in array first for ease of loading into bounded buffer

    // Bounded buffer setting
    Buffer buffer[BUFFER_SIZE];
    for(int i = 0; i<BUFFER_SIZE; i++){
        strcpy(buffer[i].path, "HELLO");
    }
    
    //Semaphore
    pthread_mutex_init(&mutex_lock, NULL);  // Initialize with mutex lock preferences
    sem_init(&empty, 0, BUFFER_SIZE);   // Initialize empty value
    sem_init(&full, 0, 0);  // Initialize full value

    pthread_t tid[Thread_NUM];
    long t;
    for(t=0; t<Thread_NUM; t++){    //  Create and use as many threads as receive
        pthread_create(&tid[t], NULL, test, buffer);
        printf("%lu started searching '%s'... \n", tid[t], argv[8]);
    }
    pthread_t final;    // Thread that were created separately to count the total number of words
    sleep(2*idx+1);
    pthread_create(&final, NULL, PrintCount, NULL);
    pthread_exit(NULL);

    return 0;
} 

