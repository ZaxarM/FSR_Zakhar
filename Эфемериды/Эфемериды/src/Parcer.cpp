#include "Parcer.h"
static const int DATA_COLUNNS = 6;
extern int DATA_SIZE;
Parcer::Parcer(const std::string& s) : filename(s) {
    f_in.open(filename);
    if (!f_in.is_open()) {
        throw Except(FILE_NOT_OPEN, "Unable to open file");
    }
}

Parcer::~Parcer() {
    if (f_in.is_open()) {
        f_in.close();
    }
}

bool Parcer::parse(std::string info[], double date[][DATE_COLUMNS], double positionX[], double positionY[], double positionZ[], double velocityX[], double velocityY[], double velocityZ[]) {
    std::string line;
    int q = 0;
    while(getline(f_in, line)&&(q<11)){
        std::istringstream iss(line);
        std::string words[10];
        int count = 0;
        while (iss >> words[count] && count < 10) {
            ++count;
        }
        if (q == 5){
            info[q] = words[count-2] +" " + words[count-1];
        }
        else{
            if (q == 3){
                info[q] = words[count-2];
            }
            else{
                if(q<9){
                    info[q] = words[count-1];
                }
            }
        }
        q++;
    }
    for (int q = 0; q < DATA_SIZE; ++q) {
        if (!(f_in >> date[q][0] >> date[q][1] >> date[q][2] >> date[q][3] >> date[q][4] >> date[q][5] >> positionX[q] >> positionY[q] >> positionZ[q] >> velocityX[q] >> velocityY[q] >> velocityZ[q])) {
            return false;
        }
    }
    return true;
}
