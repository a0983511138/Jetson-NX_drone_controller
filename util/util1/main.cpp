#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "PCA9685.h"
#include "mygyro.h"
#include "packet.h"
#include "imu_data_decode.h"

#define bus 1
#define address 0x40
#define frequency 400
#define min_pulse 1900
#define max_pulse 2700
#define motor_acc 3
#define motor_num 4

using namespace std;

void motor_set_val(int motor_no, int motor_val);
void motor_stop();

PCA9685 motor = PCA9685(bus, address);   //PCA9685 create

int main(){
    int i, motor_no, pulse, fd;
    char gyro_address[16] = "ttyUSB0";
    struct receive_imusol_packet_t *data;

    motor.setPWMFreq(frequency);        //set frequency

    fd = gyro_init(gyro_address);
    sleep(1);
    for(i = 0; i < 50; i++){
        data = get_gyro_data(fd, false);
        printf("    eul(R P Y): %8.2f %8.2f %8.2f\r\n", data->eul[0], data->eul[1], data->eul[2]);
    }

    while(pulse >= 0 && motor_no >= 0){
        cout << "==================================================" << endl;
        cout << "input the motor and its value "<< min_pulse << " ~ " << max_pulse << "('-1' to stop)" << endl;
        cout << "type '5' to set all motor: ";
        cin >> motor_no >> pulse;

        motor_set_val(motor_no, pulse);
    }

    cout << "======================while out===================" << endl;

    motor_stop();

    cout << "========================stop======================" << endl;

    return 0;
}

void motor_set_val(int motor_no, int motor_val){
    if(motor_val >= min_pulse && motor_val <= max_pulse){   //check value range
        if(motor_no == 5){                                  //set all motor
            for(int i = 1; i <= motor_num; i++)
                motor.setPWM(i, motor_val);
        }
        else if(motor_no >= 1 && motor_no <= motor_num)     //check motor numbers
            motor.setPWM(motor_no, motor_val);
    }
}

void motor_stop(){
    for(int i = 1; i <= motor_num; i++)
        motor_set_val(i, min_pulse);
}
