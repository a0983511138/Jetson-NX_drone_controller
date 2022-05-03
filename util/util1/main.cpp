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
int ptr;

int main(){
    //char *state = (char*)"1700";
    //char *ptr = (char*)malloc(sizeof(char) * 5);

    motor.setPWMFreq(frequency);        //set frequency
    sleep(1);

    pthread_t t1, t2;  //create pthread
    sleep(1);
    
    pthread_create(&t1, NULL, keyPress, NULL);
    pthread_detach(t1);

    while(1){
        pthread_create(&t2, NULL, moving, NULL);

        if(ptr == -1){
            cout << "---------------stop------------------" << endl;
            ptr = min_pulse;
            break;
        }
    }
    
    //pthread_cancel(t2);

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

void* keyPress(void* arg){

    while(ptr >= 0){
        cout << "======================================================" << endl;
        cout << "input the motor value "<< min_pulse << " ~ " << max_pulse << "('-1' to stop): ";
        cin >> ptr;
        cout << "t1: " << ptr << endl;
    }
}

void* moving(void* arg){
    int pwm = motor.getPWM(1);

    if(abs(pwm - ptr) < motor_acc)
        pwm = ptr;
    if(pwm > ptr)
        pwm -= motor_acc;
    else if(pwm < ptr){
        pwm += motor_acc;
    }
    motor.setPWM(1, pwm);
    motor.setPWM(2, pwm);
    motor.setPWM(3, pwm);
    motor.setPWM(4, pwm);
}

/*void* moving(void* arg){         //set motor PWM smoothly
    int pwm, i;
    int target = atoi((char*)arg);

    pwm = motor.getPWM(1);
    //cout << "t2: pwm:" << pwm << "\ttarget:" << target << endl;

    while(pwm != target){
        if(abs(pwm - target) < motor_acc)
            pwm = target;
        if(pwm > target){
            pwm -= motor_acc;
        }
        else if(pwm < target){
            pwm += motor_acc;
        }
        motor.setPWM(1, pwm);
        motor.setPWM(2, pwm);
        motor.setPWM(3, pwm);
        motor.setPWM(4, pwm);
        //cout << "t2_in: pwm:" << pwm << "\ttarget:" << target << endl;
        sleep(0.8);
    }
}
*/
