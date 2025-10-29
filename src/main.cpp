#include <mbed.h>

CAN can1(PA_11,PA_12,(1e6));
BufferedSerial serial(USBTX, USBRX, 115200);

int main(){
        int16_t enc[4] = {0,0,0,0};
        CANMessage enc_msg;
        float k = 360.0 / (256.0 * 4.0);
    while(1){
            can1.read(enc_msg);
        if(enc_msg.id == 10){
            for(int i = 0; i < 4; i++){
                enc[i] = enc_msg.data[i*2 + 1] << 8 | enc_msg.data[i*2];
                float k = 360.0 / (256.0 * 4.0);
            }
            printf("enc: %d, %d, %d, %d\n", (int)(enc[0]), (int)(enc[1]), (int)(enc[2]), (int)(enc[3]));
        }
    }
}