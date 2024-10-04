#include <iostream>

class ClientDevice{
    protected:
        static bool connectionStatus;
    public:
        void onConnect(){
            connectionStatus = true;
        }
        void onDisconnect(){
            connectionStatus = false;
        }
        bool getConnectionStatus(){
            return connectionStatus;
        }
};    

class TemperatureSensor:public ClientDevice{
    protected:
        static double temperature;
    public:
        void onChangeTemperature(double temp){
            TemperatureSensor::temperature = temp;
        }
        double getTemperatureSensorStatus(){
            return TemperatureSensor::temperature;
        }
};   
class MotionSensor : public ClientDevice{
    protected:
        static bool motionDetected;
    public:
        void onMotionDetected(){
            MotionSensor::motionDetected=true;
        }
        void onMotionComplete(){
            MotionSensor::motionDetected=false;
        }
        bool getMotionSensorStatus(){
            return MotionSensor::motionDetected;
        }
};      
class WaterLevelSensor : public ClientDevice{
    protected:
        static int waterLevel;
    public:
        void onChangeWaterLevel(int level){
            WaterLevelSensor::waterLevel = level;
        }
        int getWaterSensorStatus(){
            return WaterLevelSensor::waterLevel;
        }
        
};
class GasDetectionSensor : public ClientDevice{
    protected:
        static bool gasLeaked;
    public:
        void onGasLeak(){
            GasDetectionSensor::gasLeaked = true;
        }
        void onGasleakSolved(){
            GasDetectionSensor::gasLeaked = false;
        }
        bool getGasSensorStatus(){
            return GasDetectionSensor::gasLeaked;
        }
};
class Fan :public ClientDevice{
    protected:
        static bool status;
    public:
        void turnOn(){
            Fan::status = true;
        }
        void turnOff(){
            Fan::status = false;
        }
        bool getFanStatus(){
            return Fan::status;
        }
    
};        
class Light :public ClientDevice{
    protected:
        static bool status;
    public:
        void turnOn(){
            Light::status = true;
        }
        void turnOff(){
            Light::status = false;
        }
        bool getLightStatus(){
            return Light::status;
        }
};      
class Door :public ClientDevice{
    protected:
        static bool status ;
    public:
        void openDoor(){
            Door::status = true;
        }
        void closeDoor(){
            Door::status = false;
        }
        bool getDoorStatus(){
            return Door::status;
        }
    
};      


class ClientApplication{ //onConnect()->true onDisconnect()->false  Automate tasks
        std::vector<std::function<void()>> automationRules;
        public:
            ClientDevice cd;
            TemperatureSensor ts;
            MotionSensor ms;
            WaterLevelSensor wls;
            GasDetectionSensor gds;
            Fan fan;
            Light light;
            Door door;

            void simulateInput(){
                int opt;
                std::cout<<"1. Input for senor \n2. Input for device"<<std::endl;
                 std::cin>>opt;
                 if (opt == 1) {
                    // Simulate sensor input
                    int sensorOption, value;
                    std::cout << "Select sensor to simulate: \n1. Temperature\n2. Motion\n3. Water Level\n4. Gas Detection\n";
                    std::cin >> sensorOption;

                    if (sensorOption == 1) {
                        std::cout << "Enter new temperature value: ";
                        std::cin >> value;
                        ts.onChangeTemperature(value);
                    
                    } else if (sensorOption == 2) {
                        std::cout << "1. Motion Detected\n2. Motion Cleared\n";
                        std::cin >> value;
                        if (value == 1) ms.onMotionDetected();
                        else ms.onMotionComplete();
                    } else if (sensorOption == 3) {
                        std::cout << "Enter new water level: ";
                        std::cin >> value;
                        wls.onChangeWaterLevel(value);
                    } else if (sensorOption == 4) {
                        std::cout << "1. Gas Leak Detected\n2. Gas Leak Cleared\n";
                        std::cin >> value;
                        if (value == 1) gds.onGasLeak();
                        else gds.onGasleakSolved();
                }       
                } else if (opt == 2) {
                    // Simulate device input
                    int deviceOption;
                    std::cout << "Select device to control: \n1. Fan\n2. Light\n3. Door\n";
                    std::cin >> deviceOption;

                    if (deviceOption == 1) {
                        int fanOption;
                        std::cout << "1. Turn Fan ON\n2. Turn Fan OFF\n";
                        std::cin >> fanOption;
                        if (fanOption == 1) fan.turnOn();
                        else fan.turnOff();
                    } else if (deviceOption == 2) {
                        int lightOption;
                        std::cout << "1. Turn Light ON\n2. Turn Light OFF\n";
                        std::cin >> lightOption;
                        if (lightOption == 1) light.turnOn();
                        else light.turnOff();
                    } else if (deviceOption == 3) {
                        int doorOption;
                        std::cout << "1. Open Door\n2. Close Door\n";
                        std::cin >> doorOption;
                        if (doorOption == 1) door.openDoor();
                        else door.closeDoor();
                    }
                }
            }

            void printDevicesStatus(){
                std::cout <<"Sensor                  Status"<<std::endl;
                std::cout <<"------                  ------"<<std::endl;
                std::cout<<"Temperature Sensor      "<<ts.getTemperatureSensorStatus()<<std::endl;
                std::cout<<"Motion Sensor           "<<ms.getMotionSensorStatus()<<std::endl;
                std::cout<<"Water Level Sensor      "<<wls.getWaterSensorStatus()<<std::endl;
                std::cout<<"Gas Detection Sensor    "<<gds.getGasSensorStatus()<<std::endl;
                std::cout << "Fan                     " << (fan.getFanStatus() ? "ON" : "OFF") << std::endl;
                std::cout << "Light                   " << (light.getLightStatus() ? "ON" : "OFF") << std::endl;
                std::cout << "Door                    " << (door.getDoorStatus() ? "OPEN" : "CLOSED") << std::endl;
                
            }
            
            void addAutomationRule() {
                std::string sensorName, comparison;
                double value;
                std::string deviceAction, function;

                std::cout << "Enter automation rule (e.g., If: Temperature > 22.0 Then: Fan turnOn): "<<"\n"
                <<"Sensors[Temperature,Motion,WaterLevel,Gas] Comparision[<,>,=] Values[1(true)/0(false)] Device[Fan,Light,Door] Function[turnOn,turnOff,open,close]"
                <<std::endl;
                std::cout << "If: ";
                std::cin >> sensorName >> comparison >> value;
                std::cout << "Then: ";
                std::cin >> deviceAction >> function;

                // Temperature Sensor Rules
                if (sensorName == "Temperature") {
                    if (comparison == ">") {
                        automationRules.push_back([this, value, deviceAction, function]() {
                            if (ts.getTemperatureSensorStatus() > value) {
                                if (deviceAction == "Fan" && function == "turnOn") {
                                    return fan.turnOn();
                                } else if (deviceAction == "Fan" && function == "turnOff") {
                                    return fan.turnOff();
                                }
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Door" && function == "turnOff") {
                                    return light.turnOff();
                                }
                            }
                        });
                    }else if (comparison == "<") {
                        automationRules.push_back([this, value, deviceAction, function]() {
                            if (ts.getTemperatureSensorStatus() < value) {
                               if (deviceAction == "Fan" && function == "turnOn") {
                                    return fan.turnOn();
                                }else if (deviceAction == "Fan" && function == "turnOff") {
                                    return fan.turnOff();
                                }
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Door" && function == "turnOff") {
                                    return light.turnOff();
                                }
                            }
                        });
                    }else if (comparison == "=") {
                        automationRules.push_back([this, value, deviceAction, function]() {
                            if (ts.getTemperatureSensorStatus() == value) {
                                if (deviceAction == "Fan" && function == "turnOn") {
                                    return fan.turnOn();
                                }else if (deviceAction == "Fan" && function == "turnOff") {
                                    return fan.turnOff();
                                }
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Door" && function == "turnOff") {
                                    return light.turnOff();
                                }
                            }   
                        });
                    }
                }

                 // Motion Sensor Rules
                else if (sensorName == "Motion") {
                    if (comparison == "=") { 
                        automationRules.push_back([this, value, deviceAction, function]() {
                            bool detected = static_cast<bool>(value); 
                            if (ms.getMotionSensorStatus() == detected) {
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Light" && function == "turnOff") {
                                    return light.turnOff();
                                }
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Door" && function == "turnOff") {
                                    return light.turnOff();
                                }
                            }
                        });
                    }
                }

                // Water Level Sensor Rules
                else if (sensorName == "WaterLevel") {
                    if (comparison == ">") {
                        automationRules.push_back([this, value, deviceAction, function]() {
                            if (wls.getWaterSensorStatus() > value) {
                                if (deviceAction == "Fan" && function == "turnOn") {
                                    return fan.turnOn();
                                } else if (deviceAction == "Fan" && function == "turnOff") {
                                    return fan.turnOff();
                                }
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Door" && function == "turnOff") {
                                    return light.turnOff();
                                }
                            }
                        });
                    } else if (comparison == "<") {
                        automationRules.push_back([this, value, deviceAction, function]() {
                            if (wls.getWaterSensorStatus() < value) {
                                if (deviceAction == "Fan" && function == "turnOn") {
                                    return fan.turnOn();
                                } else if (deviceAction == "Fan" && function == "turnOff") {
                                    return fan.turnOff();
                                }
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Door" && function == "turnOff") {
                                    return light.turnOff();
                                }
                            }
                        });
                    }
                }

                // Gas Detection Sensor Rules
                else if (sensorName == "Gas") {
                    if (comparison == "=") { 
                        automationRules.push_back([this, value, deviceAction, function]() {
                            bool gasLeaked = static_cast<bool>(value); 
                            if (gds.getGasSensorStatus() == gasLeaked) {
                                if (deviceAction == "Fan" && function == "turnOn") {
                                    return fan.turnOn();
                                } else if (deviceAction == "Fan" && function == "turnOff") {
                                    return fan.turnOff();
                                }
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Door" && function == "turnOff") {
                                    return light.turnOff();
                                }
                            }
                        });
                    }
                }

                // Door Control
                else if (sensorName == "Door") {
                    if (comparison == "=") { 
                        automationRules.push_back([this, value, deviceAction, function]() {
                            bool doorOpen = static_cast<bool>(value); 
                            if (door.getDoorStatus() == doorOpen) {
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Door" && function == "open") {
                                    return door.openDoor();
                                } else if (deviceAction == "Door" && function == "close") {
                                    return door.closeDoor();
                                }
                                if (deviceAction == "Light" && function == "turnOn") {
                                    return light.turnOn();
                                } else if (deviceAction == "Door" && function == "turnOff") {
                                    return light.turnOff();
                                }
                            }
                        });
                    }
                }
            }

            void triggerAutomation() {
                for (auto& rule : automationRules) {
                    rule();
                }
            }

}; 

bool ClientDevice::connectionStatus = false; 
double TemperatureSensor::temperature = 20.4; 
bool MotionSensor::motionDetected = false; 
int WaterLevelSensor::waterLevel = 0; 
bool GasDetectionSensor::gasLeaked = false; 
bool Fan::status = false; 
bool Light::status = false;
bool Door::status = false; 


int main(){
    int option;
    do{
        //Output options
        ClientApplication obj;

        std::cout<<"1.Print Device Status\n2. Simulate Input\n3. Device Automation\n4.Exit"<<std::endl;

        std::cout<<"Enter an option : ";
        std::cin>>option;

        switch(option){
            case 1:
                obj.printDevicesStatus();
                break;
            case 2:
                obj.simulateInput();
                obj.triggerAutomation();
                break;
            case 3:
                obj.addAutomationRule();
                obj.triggerAutomation();
                break;
        }
    }while(option!=4);
    return 0;
}

