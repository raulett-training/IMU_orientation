#include <filesystem>
#include <iostream>
#include <fstream>
#include "parse_header.h"
#include "ImrRecord.h"

int main(int argc, char *argv[]){
    if (argc < 2) {
        std::cerr << "Enter input *.imr file as a first comandline parameter." << std::endl;
        return 1;
    }

    std::filesystem::path input_path = argv[1];
    std::ifstream imr_file(std::filesystem::absolute(input_path), std::ios::binary);

    if (!imr_file) {
        std::cout << "unable to open input file.\n";
        return 1;
    }
    ImrHeader header = parse_header(&imr_file);
    std::filesystem::path output_filename{input_path.stem().string() + ".txt"};
    std::filesystem::path output_filepath = input_path.parent_path() / output_filename;
    std::ofstream result_file(std::filesystem::absolute(output_filepath));

    if (!result_file) {
        std::cout << "unable to open result file.\n";
        return 1;
    }

    result_file << "Header: " << header.szHeader << std::endl;
    result_file << "Intel or Motorola: " << header.bIsIntelOrMotorola << std::endl;
    result_file << "Inertial explorer version: " << header.dVersionNumber << std::endl;
    result_file << "DeltaTheta: " << header.bDeltaTheta << std::endl;
    result_file << "DeltaVelocity: " << header.bDeltaVelocity << std::endl;
    result_file << "DataRate, Hz: " << header.dDataRateHz << std::endl;
    result_file << "GyroScaleFactor, deg/s: " << header.dGyroScaleFactor << std::endl;
    result_file << "AccelScaleFactor, m/s^2: " << header.dAccelScaleFactor << std::endl;
    result_file << "0=Unknown will default to GPS, 1=UTC seconds of week, 2=GPS seconds of week, iUtcOrGpsTime.: " << header.iUtcOrGpsTime << std::endl;
    result_file << "0=Unknown will default to corrected time, 1=Time tags are top of the second, 2=Time tags are corrected for reciver clock bias, iRcvTimeOrCorrTime: " << header.iRcvTimeOrCorrTime << std::endl;
    result_file << "If you have a known bias your GPS and IMU time tags, TimeTagBias: " << header.dTimeTagBias << std::endl;
    result_file << "Name of IMU used, ImuName: " << header.szImuName << std::endl;
    result_file << "Name of calling program used, szProgramName: " << header.szProgramName << std::endl;
    result_file << "Name of IMU used, ImuName: " << header.bLeverArmValid << std::endl;
    result_file << "True if lever arms from IMU to prim GNSS antenna stored in this header: " << header.bLeverArmValid << std::endl;
    result_file << "lever arm x offset in mm: " << header.lXoffset << std::endl;
    result_file << "lever arm y offset in mm: " << header.lYoffset << std::endl;
    result_file << "lever arm z offset in mm: " << header.lZoffset << std::endl;
    result_file << "\nTIME\tGX\tGY\tGZ\tAX\tAY\tAZ" << std::endl;
    ImrRecord record{};
    while (imr_file.read(reinterpret_cast<char*>(&record), sizeof(record))){
        result_file << std::fixed << std::setprecision(6) << record.time << "\t";
        result_file << record.gx*header.dGyroScaleFactor*header.dDataRateHz << "\t";
        result_file << record.gy*header.dGyroScaleFactor*header.dDataRateHz << "\t";
        result_file << record.gz*header.dGyroScaleFactor*header.dDataRateHz << "\t";
        result_file << record.ax*header.dAccelScaleFactor*header.dDataRateHz << "\t";
        result_file << record.ay*header.dAccelScaleFactor*header.dDataRateHz << "\t";
        result_file << record.az*header.dAccelScaleFactor*header.dDataRateHz << std::endl;
    }
    result_file.close();
    imr_file.close();
}