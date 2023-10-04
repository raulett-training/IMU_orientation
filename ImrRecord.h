#ifndef IMU_ORIENTATION_IMRRECORD_H
#define IMU_ORIENTATION_IMRRECORD_H

#include <cstdint>


struct ImrRecord{
    double time;
    int32_t gx;
    int32_t gy;
    int32_t gz;
    int32_t ax;
    int32_t ay;
    int32_t az;
};


#endif //IMU_ORIENTATION_IMRRECORD_H
