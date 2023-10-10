//Miram Khalil Halimeh
//202201330
//Computer Architecture Lab
//Homework #2
//Just learn to use serial communication in any another language to interface it with Arduino. 
//suggested languages: Java,C#, C, C++, Dart, Go, Rust.
//Change this code from python to C :
//Python code:
//import serial 
//import time 
//ser = serial.Serial('COM7', 9600) 
//time.sleep(2) 
//while True:
//        ser.write(b'x') 
//         time.sleep(1)
// ser.close()
//C code:
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h> // For sleep on Windows, consider using Sleep()

int main() {
    HANDLE hSerial;
    char portName[] = "\\\\.\\COM7"; // Use the appropriate COM port name
    char data[] = "x";
    hSerial = CreateFile(portName, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
    if (hSerial == INVALID_HANDLE_VALUE){
         fprintf(stdrr,”Error opening serial serial port\n”);
         return 1;
}
      Sleep(2000); // Sleep for 2 seconds
      while (1) {
               DWORD bytesWritten;
               if (!WriteFile(hSerial, data, strlen(data), &bytesWritten, NULL)) {
                           fprintf(stderr, "Error writing to serial port\n");
                           CloseHandle(hSerial);
                           return 1;
}
         Sleep(1000); // Sleep for 1 second
}
       CloseHandle(hSerial);
        return 0;
}
    
