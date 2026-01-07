#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

int main(int argc, char* argv[]) {
    int PID = getpid();
    FILE* raportFile = fopen("./raport.txt", "w");

    time_t rawtime;
    struct tm *timeinfo;
    time(&rawtime);
    timeinfo = localtime(&rawtime);
    printf("Current date is: %02d/%02d/%04d\n", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    fprintf(raportFile,"%02d/%02d/%04d\t\t", timeinfo->tm_mday, timeinfo->tm_mon + 1, timeinfo->tm_year + 1900);
    printf("Current time is: %02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);
    fprintf(raportFile, "%02d:%02d:%02d\n", timeinfo->tm_hour, timeinfo->tm_min, timeinfo->tm_sec);

    char path[40];
    snprintf(path, 40, "/proc/%d/status", PID);
    FILE* statusFile = fopen(path, "r");
    if (!statusFile) {
        printf("Error opening file\n");
        return 1;
    }
    char line[1024];
    printf("Process Status: \n");
    fprintf(raportFile, "%s", "Process Status: \n");
    while (fgets(line, 1024, statusFile)) {
        printf("%s", line);
        fprintf(raportFile, "%s", line);
    }
    fclose(statusFile);

    printf("\nCPU: \n");
    fprintf(raportFile, "%s", "\nCPU: \n");
    snprintf(path, 40, "/proc/cpuinfo");
    statusFile = fopen(path, "r");
    if (!statusFile) {
        printf("Error opening file\n");
        return 1;
    }
    int lineCount = 0;
    while (fgets(line, 1024, statusFile)) {
        if (lineCount == 0) {
            lineCount ++;
            continue;
        }
        if (strcmp(line,"\n") == 0)
            break;
        printf("%s", line);
        fprintf(raportFile, "%s", line);
    }
    fclose(statusFile);
fclose(raportFile);

}