#include <iostream>
#include <cstring>


int main(){
    char timeC[12];
    printf("Enter your time (Exampe 50m): "); scanf("%s",&timeC[0]);

    uint32_t timestamp = time(0);
    std::string timeStr;
    uint32_t time32;
    for(int i = 0; i < 12; i++){
        timeStr += timeC[i];
        if(timeC[i] == 'm'){
            time32 = std::stoi(timeStr);
            break;
        }
    }

    time32 = 60*time32;
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