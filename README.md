# Gas Leakage Monitoring & Alerting System for Industries using IoT
 
*A safety system to detect gas leaks and alert workers via IoT.*

## 📌 Overview
An IoT-based solution to monitor gas leaks in industrial environments, send real-time alerts via SMS, and trigger safety protocols. Built with Arduino, IBM Watson IoT, and MIT App Inventor.

## 🛠️ Key Features
- **Real-time monitoring** using MQ-series gas sensors.
- **Cloud integration** (IBM Watson) for data logging.
- **SMS alerts** and evacuation triggers.
- **Dashboard** for live gas levels and location tracking.
- **Automatic exhaust fan control** to mitigate leaks.

## 📂 Repository Structure

https://github.com/user-attachments/assets/afb07538-3e4c-4211-97f8-e4374684524b


## 🔧 Hardware Components
- Arduino UNO
- MQ-2/MQ-5 Gas Sensor
- GSM Module (for SMS)
- Buzzer, LED, LCD Display
- DC Motor (exhaust fan)

## 💻 Software & Tools
- **Arduino IDE** (Firmware)
- **IBM Watson IoT** (Cloud)
- **Node-RED** (Data flow)
- **MIT App Inventor** (Mobile interface)

## 🚀 Setup Instructions
1. **Hardware Assembly**:  
   - Connect sensors to Arduino as per Circuit_Diagram.pdf
2. **Firmware**:  
   - Upload Firmware/Arduino/gas_leak_detector.ino to Arduino.
3. **Cloud Setup**:  
   - Configure IBM Watson IoT using Cloud_Integration/IBM_Cloud_Setup.md.
4. **Mobile App**:  
   - Import MIT App Inventor project from `MIT_App_Backend/`.

## 📊 Results
- Data sent to IBM Cloud Firmware/Arduino/ibm_cloud_integration.ino.  
- MIT App displays gas levels and GPS coordinates. App_Screenshots/alert_notification.png

## 📜 Project Documentation
- Proposed_Solution.pdf 
- GAS LEAKAGE MONITORING AND ALERTING SYSTEMS FOR INDUSTRIES USING IOT REPORT.pdf 
- Functional_Requirements.pdf

## 🔗 Links
- **TinkerCAD Simulation**: https://www.tinkercad.com/things/fGvVek7Ol3p-ibm-final-project/editel?sharecode=iGapHQfMmO_xV402duIgs56cyEezHI88xpORIGxviqc
- **Demo Video**: https://drive.google.com/file/d/1iQ351A_5vi5RaYbCFBmZhbWGPaFNdfRO/view 

## 🙏 Acknowledgments
Team: Gokul R, Gayathri R, Haritha R  
Project ID: PNT2022TMID53571
