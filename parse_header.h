#ifndef IMU_ORIENTATION_PARSE_HEADER_H
#define IMU_ORIENTATION_PARSE_HEADER_H

#include <fstream>

struct ImrHeader{
    char szHeader[8];
    int8_t bIsIntelOrMotorola;
    double dVersionNumber;
    int32_t bDeltaTheta;
    int32_t bDeltaVelocity;
    double dDataRateHz;
    double dGyroScaleFactor;
    double dAccelScaleFactor;
    int32_t iUtcOrGpsTime;
    int32_t iRcvTimeOrCorrTime;
    double dTimeTagBias;
    char szImuName[32];
    char szProgramName[32];
    char tCreate[12];
    bool bLeverArmValid;
    int32_t lXoffset;
    int32_t lYoffset;
    int32_t lZoffset;
};

ImrHeader parse_header(std::ifstream* imr_file);


#endif //IMU_ORIENTATION_PARSE_HEADER_H
