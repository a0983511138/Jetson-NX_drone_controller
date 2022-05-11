#include <iostream>
#include <string>
#include <pthread.h>
#include "PCA9685.h"
#include <unistd.h>
#include <stdlib.h>

#define bus 1
#define address 0x40
#define frequency 400
#define min_pulse 1700
#define max_pulse 3800
#define motor_acc 3
#define motor_num 4

using namespace std;

int findMax(int* buf, int size);
void stop();
void* keyPress(void* arg);
void* moving(void* arg);

PCA9685 motor = PCA9685(bus, address);   //PCA9685 create
int ptr = min_pulse;

int main(){
    int motor_no, pulse;
    motor.setPWMFreq(frequency);        //set frequency
    sleep(1);

    pthread_t t1, t2;  //create pthread
    sleep(1);
/*    
    pthread_create(&t1, NULL, keyPress, NULL);
    //pthread_detach(t1);

    while(ptr != -1){
        pthread_create(&t2, NULL, moving, NULL);

        if(ptr == -1){
            cout << "---------------stop------------------" << endl;
            ptr = min_pulse;
            break;
        }
    }
*/
    while(pulse >= 0 && motor_no >= 0){
        cout << "======================================================" << endl;
        cout << "input the motor and its value "<< min_pulse << " ~ " << max_pulse << "('-1' to stop): ";
        cin >> motor_no >> pulse;
        motor.setPWM(motor_no, pulse);
        if(pulse < 0 || motor_no < 0)
            break;
    
    }

    cout << "======================while out===================" << endl;
    motor.setPWM(1, min_pulse);
    motor.setPWM(2, min_pulse);
    //motor.setPWM(3, 1700);
    //motor.setPWM(4, 1700);

    //stop();

    return 0;
}

int findMax(int* buf, int size){
    int i, max = buf[0];

    for(i = 0; i < size; i++){
        max = max > buf[i] ? buf[i] : max;
    }
    cout << "max : " << max << endl;

    return max;
}

void* keyPress(void* arg){

    while(ptr >= 0){
        cout << "======================================================" << endl;
        cout << "input the motor value "<< min_pulse << " ~ " << max_pulse << "('-1' to stop): ";
        cin >> ptr;
        cout << "t1: " << ptr << endl;
        if(ptr == -1)
            break;
    }
    return NULL;
}

void* moving(void* arg){

    motor.setPWM(1, ptr);
    cout << "\nptr= " << ptr << ", pwm= " << motor.getPWM(1) << endl;;
    sleep(1);
    //motor.setPWM(2, pwm);
    //motor.setPWM(3, pwm);
    //motor.setPWM(4, pwm);
    return NULL;
}

void stop(){
    int pwm[motor_num], i;

    for(i = 0; i < motor_num; i++){
        pwm[i] = motor.getPWM(i+1);
    }

    while(findMax(pwm, motor_num) > min_pulse){
        for(i = 0; i < motor_num; i++){
            if(pwm[i] > min_pulse){
                pwm[i] -= motor_acc;
                if((pwm[i]) < min_pulse)
                    pwm[i] = min_pulse;
                motor.setPWM(i+1, pwm[i]);
            }
            else
                pwm[i] = 1;
            cout << "motor" << i+1 << " : " << pwm[i] << "  ";
            sleep(0.3);
        }
    }
}
