#ifndef MYGYRO_H
#define MYGYRO_H

typedef struct imudata_packet_t {
    float eul[3];
    float quat[4];
}imudata_packet_t;

int gyro_init(const char gyro_addr[16]);
imudata_packet_t *get_gyro_data(int fd, bool printMode);

extern imudata_packet_t imusol;

#endif
