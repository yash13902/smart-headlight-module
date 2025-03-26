# Smart Headlight Module

## Summary - 
With the rise in night-time driving, driver safety is a growing concern. This project examines the impact of intense low-beam headlights, which, despite their brightness, remain legal and may pose risks to other drivers. It explores adaptive beam headlights, which use cameras to adjust brightness and beam shape in real-time, preventing glare while maintaining visibility. By reducing temporary blinding, these advanced systems aim to enhance road safety and reduce accidents.

## Objective - 
In this project, the study explores on how can smart headlights be developed in an economical way and how we can use technology to improve visibility for cars on roads at night. With the help of microcontrollers and sensors a device can be created which can provide a solution to the above problem and can give suggestions to help if not solve the larger problem at hand.
- **Using sensors to find whether the lighting conditions in the surroundings require the use of headlights** – if it is day time then the headlights are not required, but it is required in the night time.
- **Detect fast moving vehicles and find their position** – with the help of a camera for input and using machine learning models and fine-tuned models we can create a system that is able to detect the position of the vehicles on the road.
- **Control LED matrix according to the position of the fast moving vehicles** – once we have the location of these cars, we can control the intensity and whether we need to turn the light off in that direction to prevent glare.

## Tech Stack Used - 

### 1. ML Model and Object Detection - 

- Python
- OpenCV
- Ml Model - YOLOv8

### 2. Hardware Used -

- Microcontroller Board – Arduino Uno R3
- LED matrix – Max7219 matrix (4 components of 8x8 LED dot matrix)
- Light dependent Resistor – LM393 Photosensitive Light-Dependent Control Sensor LDR Module
- Breadboard
- Jumper wires

## Architecture of the Proposed Headlight System - 

<img width="732" alt="Screenshot 2025-03-25 at 11 19 20 PM" src="https://github.com/user-attachments/assets/d8b119a1-ba3e-4186-9c5f-221ff13dea1e" /><br>

This figure explains the architecture of the proposed headlight system. There are 2 parts to the proposed system. The vehicle detection with the help of a camera and the surrounding lighting condition detection with the help of an Light Dependent Resistor.
1) The flow of the vehicle detection and controlling of the LED Matrix –

<img width="748" alt="Screenshot 2025-03-25 at 11 20 06 PM" src="https://github.com/user-attachments/assets/cc4b5f30-e044-4c84-97cb-1f5c69b1618e" />  <br>


- With the help of a camera which will be attached on the car will take the real time input of the road and the vehicles that are on the road.
- Once the input is taken then with the help of Machine Learning algorithms we can detect the oncoming vehicles on the road on the opposite side.
- After that is detected and the position of these cars are located. We can get the coordinates of these cars.
- With the help of the coordinates of the oncoming cars and vehicles we can configure the LED matrix to control where the headlight shines and where it does not.
- This will help in reducing the glare that the drivers have to experience.

2) The flow of the Light Dependent Resistor and how it will control the headlights –

<img width="701" alt="Screenshot 2025-03-25 at 11 22 43 PM" src="https://github.com/user-attachments/assets/47a5ec13-0908-403e-afe9-ce5dc22ec5b5" />  <br>

- The Light Dependent Resistor can help us detect illumination.
- With the help of LDR we can gauge the lighting conditions of the surroundings and make a decision whether the headlights are required or not.
- If the lighting conditions are of a certain state, like if it is daytime and there is enough light in the surroundings then there is no need to the headlights and hence we can turn them off.
- If the lighting conditions are not enough and it is dark, then the headlights can be turned on and then we can make the use of the smart headlight system.

## Methodology 

### Software Functionality - 

- We utilize machine learning algorithms, particularly the model developed by Ultralytics - YOLOv8.
- The process involves training the model with labelled data, indicating the presence of vehicles, and testing it with various datasets to ensure accuracy.
- Once trained, the model can be invoked to detect vehicles in images or videos in real-time.
- Upon detecting vehicles, the model outputs their positions, which are then sent to an Arduino board.
- The Arduino board controls an LED matrix, visually indicating the positions of detected vehicles by illuminating corresponding LEDs.
- This setup enables us to visually perceive where the headlights of vehicles on the opposite side are providing light, aiding in decision-making and safety measures.

### Hardware Functionality - 

- The Arduino Uno receives input from the machine learning model regarding the position of detected vehicles.
- Based on the input, the Arduino Uno controls the LED matrix to create different shapes of beams, directing light away from the eyes of oncoming drivers.
- The LDR detects ambient light conditions and adjusts the headlights accordingly. If the light falls below a certain threshold, the headlights are automatically turned on; otherwise, they remain off.
- This setup ensures that headlights are utilized appropriately based on surrounding lighting conditions, enhancing safety for both the driver and other road users.

## Design of the Module - 

<img width="465" alt="Screenshot 2025-03-26 at 9 05 04 AM" src="https://github.com/user-attachments/assets/a6ff8ca1-be08-4b66-bc3d-cd9a60b4708a" /> <br> <br>

<img width="464" alt="Screenshot 2025-03-26 at 9 05 33 AM" src="https://github.com/user-attachments/assets/89b916fd-ae2a-4a35-b1fc-32963995ad96" />

## Real Life Working - 

<img width="420" alt="Screenshot 2025-03-26 at 9 07 20 AM" src="https://github.com/user-attachments/assets/f7b70491-1826-4ca0-acbc-b549c7eb771a" />

## Performance of the ML Model - 

The machine learning model used is YOLOv8. It is an object detection model and it is known for speed and accuracy.
- The precision for the trained model is – 76.4%
- The recall for the trained model is – 86.6%

<img width="466" alt="Screenshot 2025-03-26 at 9 09 13 AM" src="https://github.com/user-attachments/assets/207c9bc3-2e9c-4f7f-b613-5cbf71654eb8" /> <br>

<img width="310" height="210" alt="Screenshot 2025-03-26 at 9 09 34 AM" src="https://github.com/user-attachments/assets/ef18f4a3-05ef-4360-8e51-74365b12a064" />
<img width="310" height="210" alt="Screenshot 2025-03-26 at 9 09 49 AM" src="https://github.com/user-attachments/assets/473aa968-7315-43d8-9e38-3add44bd98db" />

# How to Run - 

### Software - 
- Python Environment is given
- Run the requirements.txt file to import all the required packages.
- Connect with the hardware Module and a Camera Module, you can use your laptop camera also.
- Run the videotrial.py file. You can use this to run the headlight module in live video form or even a pre-recorded video.
- Run the trial.py file. This can be used to run the headlight module for images.

### Hardware - 

Components –
1. Arduino Uno R3
2. LED Matrix Max7219
3. Light Dependent Resistor
4. Breadboard

Light Dependent Resistor –
- The VCC pin is connected to the breadboard where 5V of power is being supplied from
the Arduino.
- The ground pin is connected to the ground pin of the Arduino.
- The A0 pin which is the output of the LDR is connected to the A0 pin of the Arduino. The output of the LDR is given from the A0 pin of the LDR and it is given as input to the A0 pin of the Arduino.

LED Matrix –
- The VCC pin is connected to the breadboard where 5V of power is being supplied from the Arduino.
- The ground pin is connected to the ground pin of the Arduino.
- The Chip Select pin is connected to pin 10 of the Arduino.
- The Clock pin is connected to pin 11 of the Arduino.
- The Data In pin is connected to pin 12 of the Arduino.

PS. - Don't forget to connect the Arduino to your laptop before running the program.


