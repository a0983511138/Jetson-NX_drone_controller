int gyro_init(char gyro_addr[16]);
struct receive_imusol_packet_t *get_gyro_data(int fd, bool printMode);
