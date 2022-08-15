#include <iostream>
#include <string>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

#include "PCA9685.h"
#include "BMP180.h"
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
//BMP180  myBMP = BMP180(1, 0x77, BMP180_ULTRAHIGHRES);

int main(int argc, const char *argv[]){
    int i, motor_no, pulse, fd;
    struct receive_imusol_packet_t *data;

    motor.setPWMFreq(frequency);        //set frequency
    
    if(argc > 1){
        fd = gyro_init(argv[1]);
    }
    else{
        puts("Please enter USB port append to the execution commend!!");
        exit(0);
    }
    sleep(1);
/*    while(1) {
        printf("Temperature.......: %f\n",myBMP.getTemperature());
        printf("Pressure..........: %d\n",myBMP.getPressure());
        //myBMP.getTemperature();
        //myBMP.getPressure();
    }
*/

    for(i = 0; i < 5000; i++){
        data = get_gyro_data(fd, true);
    }
/*
    while(pulse >= 0 && motor_no >= 0) {
        cout << "==================================================" << endl;
        cout << "input the motor and its value "<< min_pulse << " ~ " << max_pulse << "('-1' to stop)" << endl;
        cout << "type '5' to set all motor: ";
        cin >> motor_no >> pulse;

        motor_set_val(motor_no, pulse);
    }

    cout << "======================while out===================" << endl;

    motor_stop();

    cout << "========================stop======================" << endl;
*/
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
