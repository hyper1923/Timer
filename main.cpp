#include <iostream>
#include <cstring>


#define minute 0x1
#define seconds 0x2
#define hours 0x3
#define nothing 0x0

int main(){
    char timeC[12];
    short dataType = nothing;
    printf("Enter your time (Exampe 50m): "); scanf("%s",&timeC[0]);

    uint32_t timestamp = time(0);
    std::string timeStr;
    uint32_t time32;
    for(int i = 0; i < 12; i++){
        timeStr += timeC[i];
        if(timeC[i] == 'm'){
            time32 = std::stoi(timeStr) * 60;
            dataType = minute;
            break;
        }
        if(timeC[i] == 's'){
            time32 = std::stoi(timeStr);
            dataType = seconds;
            break;
        }
        if(timeC[i] == 'h'){
            time32 = std::stoi(timeStr)*60*60;
            dataType = hours;
            break;
        }
    }

    if(dataType == nothing){
        printf("You didn't add s,m or h to end of string.\n\r");
        exit(EXIT_FAILURE);
    }

    uint32_t totalStamp = timestamp + time32;

    bool finished = false;
    while(1){
        if(time(NULL) == totalStamp){
            finished = true;
            break;
        }
    }

    while(finished){
        system("echo -e '\a'");
        system("sleep 0.5");
        printf("You need to wake up!\n\r");
    }
}