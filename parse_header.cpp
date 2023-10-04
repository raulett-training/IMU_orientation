#include <cstdint>
#include "parse_header.h"

ImrHeader parse_header(std::ifstream* imr_file){
    uint8_t reserved1[4];
    int8_t Reserved[354];

    ImrHeader header{};

    imr_file->read(reinterpret_cast<char*>(&header.szHeader), sizeof(header.szHeader));
    imr_file->read(reinterpret_cast<char*>(&header.bIsIntelOrMotorola), sizeof(header.bIsIntelOrMotorola));
    imr_file->read(reinterpret_cast<char*>(&header.dVersionNumber), sizeof(header.dVersionNumber));
    imr_file->read(reinterpret_cast<char*>(&header.bDeltaTheta), sizeof(header.bDeltaTheta));
    imr_file->read(reinterpret_cast<char*>(&header.bDeltaVelocity), sizeof(header.bDeltaVelocity));
    imr_file->read(reinterpret_cast<char*>(&header.dDataRateHz), sizeof(double));
    imr_file->read(reinterpret_cast<char*>(&header.dGyroScaleFactor), sizeof(double));
    imr_file->read(reinterpret_cast<char*>(&header.dAccelScaleFactor), sizeof(header.dAccelScaleFactor));
    imr_file->read(reinterpret_cast<char*>(&header.iUtcOrGpsTime), sizeof(header.iUtcOrGpsTime));
    imr_file->read(reinterpret_cast<char*>(&header.iRcvTimeOrCorrTime), sizeof(header.iRcvTimeOrCorrTime));
    imr_file->read(reinterpret_cast<char*>(&header.dTimeTagBias), sizeof(header.dTimeTagBias));
    imr_file->read(reinterpret_cast<char*>(&header.szImuName), sizeof(header.szImuName));
    imr_file->read(reinterpret_cast<char*>(&reserved1), sizeof(reserved1));
    imr_file->read(reinterpret_cast<char*>(&header.szProgramName), sizeof(header.szProgramName));
    imr_file->read(reinterpret_cast<char*>(&header.tCreate), sizeof(header.tCreate));
    imr_file->read(reinterpret_cast<char*>(&header.bLeverArmValid), sizeof(header.bLeverArmValid));
    imr_file->read(reinterpret_cast<char*>(&header.lXoffset), sizeof(header.lXoffset));
    imr_file->read(reinterpret_cast<char*>(&header.lYoffset), sizeof(header.lYoffset));
    imr_file->read(reinterpret_cast<char*>(&header.lZoffset), sizeof(header.lZoffset));
    imr_file->read(reinterpret_cast<char*>(&Reserved), sizeof(Reserved));


    return header;
}
