#undef DEFAULT

#include "VideoStream.h"
#include "QRCodeScanner.h"

#define CHANNEL 0

// Default preset configurations for each video channel:
// Channel 0 : 1920 x 1080 30FPS H264
// Channel 1 : 1280 x 720  30FPS H264

VideoSetting config(CHANNEL);
QRCodeScanner Scanner;

void setup()
{
    // Initialize serial communication
    Serial.begin(115200);
    // Configure camera video channel with video format information
    Camera.configVideoChannel(CHANNEL, config);
    Camera.videoInit();

    Serial.println("Starting QR Code Scanning...");  // 확인뇽
    Scanner.StartScanning();
}

void loop()
{
    delay(1000);
    Scanner.GetResultString();
    Scanner.GetResultLength();
    if (Scanner.ResultString != nullptr) {
        Serial.print("Result String is:");
        Serial.println(Scanner.ResultString);
    }
    if (Scanner.ResultLength != 0) {
        Serial.print("Result Length is:");
        Serial.println(Scanner.ResultLength);
    }
}
