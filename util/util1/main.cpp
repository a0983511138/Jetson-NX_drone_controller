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
#define default_port "ttyUSB0"

using namespace std;

void motor_set_val(int motor_no, int motor_val);
void motor_stop();
//int balance(struct receive_imusol_packet_t *data);

int  motor_no[6] = {1, 2, 11, 12, 5, 6};
PCA9685 motor = PCA9685(bus, address);   //PCA9685 create

int main(int argc, const char *argv[]){
    int i, pulse, fd, number;
    imudata_packet_t *data;
    FILE *fp;
    char file_dir[50] = "/home/uav/code/controller/util/util1/simpletest";
    char bmp_data[10];

    motor.setPWMFreq(frequency);        //set frequency
    
    if(argc > 1){
        fd = gyro_init(argv[1]);
    }
    else{
        fd = gyro_init(default_port);
        printf("Using default port (%s)!\n", default_port);
    }
    sleep(1);

    while(1) {
        data = get_gyro_data(fd, false);
        //balance(data);
        printf("eul:\t%f\t%f\t%f\n", data->eul[0], data->eul[1], data->eul[2]);
        printf("quat:\t%f\t%f\t%f\t%f\n", data->quat[0], data->quat[1], data->quat[2], data->quat[3]);
        cout << "==================================================" << endl;
        sleep(10);
    }


/*
    i = 0;
    while(1) {
        fp = popen(file_dir, "r");
        if (fp == NULL) {
            printf("Failed to open py file!\n");
            exit(1);
        }

        while (fgets(bmp_data, sizeof(bmp_data), fp) != NULL)
            printf("%s", bmp_data);

        pclose(fp);
        i++;
    }
*/

    /**************************************************************************/
    /* Motor threshold :
     * motor1 : 1950
     * motor2 : 2400
     * motor3 : 1950
     * motor4 : 2000
     */
    /**************************************************************************/
/*
     do {
        cout << "==================================================" << endl;
        cout << "input the motor and its value "<< min_pulse << " ~ " << max_pulse << "('-1' to stop)" << endl;
        cout << "motor number: 1~4, '5' set all motors, '6' add same value: ";
        cin >> number >> pulse;

        motor_set_val(number, pulse);
    }while(number >= 0 && number <= 6);

    cout << "======================while out===================" << endl;

    motor_stop();

    cout << "========================stop======================" << endl;
*/
    return 0;
}

void motor_set_val(int number, int motor_val){
    int i;

    if (number == 6) {
        cout << "mode 6" << endl;
        int pwm[4];
        cout << "mode " << number << endl;
        for (i = 0; i < 4; i++) {
            pwm[i] = motor.getPWM(motor_no[i]);
            motor.setPWM(motor_no[i], pwm[i] + motor_val);
            cout << "set motor " << motor_no[i] << " as " << motor_val+pwm[i] << endl;
        }
    }
    else if(motor_val >= min_pulse && motor_val <= max_pulse){   //check value range
        if(number == 5){                                  //set all motor
            for(i = 0; i < 4; i++) {
                motor.setPWM(motor_no[i], motor_val);
                cout << "set motor " << motor_no[i] << " as " << motor_val << endl;
            }
        }
        else if(number >= 1 && number <= motor_num) {    //check motor numbers
            motor.setPWM(motor_no[number-1], motor_val);
            cout << "set motor " << motor_no[number-1] << " as " << motor_val << endl;
        }
    }
}

void motor_stop(){
    for(int i = 1; i <= motor_num; i++)
        motor_set_val(i, min_pulse);
}
/*
int balance(struct receive_imusol_packet_t *data) {
    puts("\033c");
    printf("eul(R P Y):  %8.2f %8.2f %8.2f\r\n",  data->eul[0],  data->eul[1],  data->eul[2]);
    printf("quat(W X Y Z):  %8.3f %8.3f %8.3f %8.3f\r\n",  data->quat[0],  data->quat[1],  data->quat[2],  data->quat[3]);

     
    
    return NULL;
}
*/
