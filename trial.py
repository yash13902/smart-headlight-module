from ultralytics import YOLO
import serial

ser = serial.Serial('/dev/cu.usbmodem1101', 9600, timeout=0)

def singleCar(x, w, ser):
    car = x+w
    posCar = ""
    if(x <= 0.25 and car <= 0.25):
        posCar = "a" #module 4 is turned off
    elif(x > 0.25 and x <= 0.50 and car > 0.25 and car <= 0.50):
        posCar = "e" #modules 3 and 4 are turned off
    elif(x > 0.50 and x <= 0.75 and car > 0.50 and car <= 0.75):
        posCar = "f" #moduels 1 and 2 are turned off
    elif(x > 0.75 and car > 0.75):
        posCar = "d" #module 1 is turned off
    elif(x <= 0.25 and car <= 0.50):
        posCar = "e" #modules 3 and 4 are turned off
    elif(x > 0.50 and car >= 0.75):
        posCar = "f" #moduels 1 and 2 are turned off
    elif(x < 0.50 and car <= 1):
        posCar = "g" #modules 1, 2 and 3 are turned off
    elif(car >= 0.75 and x > 0):
        posCar = "h" #modules 2, 3 and 4 are turned off
    else: 
        posCar = "0" # all modules except last row is turned off
    
    print(posCar)
    # posCar = "x"+"y"+posX
    ser.write(posCar.encode())

def doubleCar(x1, w1, x2, w2, ser):
    if(x1 > x2):
        doubleCar(x2,w2,x1,w1,ser)

    car1 = x1+w1
    car2 = x2+w2
    posCar = ""
    if(x1 < 0.25 and car1 <= 0.25 and x2 >= 0.75 and car2 > 0.75):
        posCar = "a" # module 4 is turned off
    elif((x1<0.25 and car1<=0.25 and x2>=0.25 and x2<0.5 and car2>0.25 and car2<=0.5) or (x1<0.25 and car1<=0.25 and x2<0.25 and car2<=0.5) or (x1>=0.25 and x1<0.5 and car1>0.25 and car1<=0.5 and x2>=0.25 and x2<0.5 and car2>0.25 and car2<=0.5) or (x1<0.25 and car1<=0.50 and x2>=0.25 and x2<0.5 and car2>0.25 and car2<=0.5)):
        posCar = "e" #module 3 and 4 turned off
    elif((x1>=0.5 and car1<=0.75 and x2>=0.5 and car2<=0.75) or (x1>=0.5 and x1<0.75 and car1>0.5 and car1<=0.75 and x2>=0.5 and x2<0.75 and car2<0.5 and car2<=0.75) or (x1>=0.5 and x1<0.75 and car1>0.5 and car1<=0.75 and x2>=0.5 and car2>=0.75) or (x1>=0.5 and car1>=0.75 and x2>=0.75 and x2<1 and car2>0.75 and car2<=1)):
        posCar = "f" # modules 1 and 2 turned off
    elif(x1>=0.75 and car1<=1 and x2>=0.75 and car2<=1):
        posCar = "d" # module 1 turned off
    elif((x1<0.25 and car1<=0.25 and x2>=0.25 and x2<0.5 and car2<0.75) or (x1<0.25 and car1<=0.5 and x2>=0.25 and x2<0.5 and car2<=0.75) or (x1>=0.25 and x1<0.5 and car1>0.25 and car1<0.5 and x2>=0.25 and x2<0.5 and car2<=0.75)):
        posCar = "h" # modules 2, 3 and 4 turned off
    elif(x1<0.25 and car1<=0.25 and x2>=0.5 and car2>=0.75):
        posCar = "b" # modules 1, 2 and 4 turned off
    elif(x1<0.25 and car1<=0.5 and x2>=0.75 and car2>=0.75):
        posCar = "c" # modules 1, 3 and 4 turned off
    elif((x1>=0.25 and x1<0.5 and car1>=0.5 and car1<0.75 and x2>=0.5 and x2<0.75 and car2>=0.5 and car2<0.75) or (x1>=0.25 and x1<0.5 and car1>=0.5 and car1<0.75 and x2>=0.5 and x2<0.75 and car2>=0.75) or (x1>=0.25 and x1<0.5 and car1>=0.5 and car1<0.75 and x2>=0.75 and x2<1 and car2>=0.75 and car2<1)):
        posCar = "g" # modules 1, 2 and 3 turned off
    else:
        posCar = "0" # all turned off except bottom 2 rows

    print(posCar)
    ser.write(posCar.encode())

def ledOnOff(state, ser):
    # If state is 1, switch all the LEDs ON
    # Since there is no cars detected
    posCar = ""
    if state == 1:
        posCar = "1"

    # If state is 0, switch all the LEDs OFF
    # Since there is more than 2 cars detected
    if state == 0:
        posCar = "0"

    # Write the final data to the serial port
    ser.write(posCar.encode())

model = YOLO("best.pt")

# infer on a local image
# print(model.predict('/Users/yashjasani/Desktop/car_pic_right_1.png', confidence=40, overlap=30).json())

# results = model.predict('/Users/yashjasani/Desktop/car_pic_1_left.png', conf=0.5, imgsz=640)  # results list

results = model.predict('/Users/yashjasani/Desktop/test/2_car_right.png', conf=0.30, imgsz=640)

# # # Visualize the results
for r in results:
    ser.write("99".encode())
    x_size = r.orig_shape[0]
    y_size = r.orig_shape[1]
    print(x_size, y_size)
    # Plot results image
    im_bgr = r.plot()  # BGR-order numpy array
    print(r.boxes.xywhn.shape)
    if(r.boxes.shape[0] == 1): 
        for cor in r.boxes.xywhn:
            x = cor[0].item()
            y = cor[1].item()
            w = cor[2].item()
            h = cor[3].item()
            print('x: ', x) 
            print('y: ', y)
            print('w: ', w)
            print('h: ', h)
            if(y<0.65):
                singleCar(x,w,ser)
                singleCar(x,w,ser)
            print("1 car")
    elif r.boxes.shape[0] == 2: 
        print(r.boxes.xywhn)
        for cor in r.boxes.xywhn:
            print('x: ', cor[0].item()) 
            print('y: ', cor[1].item())
            print('w: ', cor[2].item())
            print('h: ', cor[3].item())
        numbers_list = r.boxes.xywhn.tolist()
        x1 = numbers_list[0][0]
        y1 = numbers_list[0][1]
        w1 = numbers_list[0][2]
        h1 = numbers_list[0][3]
        x2 = numbers_list[1][0]
        y2 = numbers_list[1][1]
        w2 = numbers_list[1][2]
        h2 = numbers_list[1][3]
        if(y1<0.65 and y2<0.65):
            doubleCar(x1,w1,x2,w2,ser)
            doubleCar(x1,w1,x2,w2,ser)
        print("2 cars")
    elif r.boxes.shape[0] > 2:
        ledOnOff(0, ser)
        ledOnOff(0, ser)
        print("more than 2 cars")
    elif r.boxes.shape[0] == 0:
        ledOnOff(1, ser)
        ledOnOff(1, ser)
        print("no cars")
    
    msg = ser.readline()
    msg1 = ser.readline()
    print("Arduino received: ", msg)
    r.show()


