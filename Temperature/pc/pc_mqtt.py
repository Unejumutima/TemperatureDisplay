import serial
import paho.mqtt.client as mqtt

# ---------------- SERIAL SETUP ----------------
# Change COM3 to your port
arduino = serial.Serial('COM4', 9600)

# ---------------- MQTT SETUP ----------------
broker = "broker.benax.rw"  
port = 1883
topic = "iot/temperature"

client = mqtt.Client()
client.connect(broker, port, 60)

print("System started... reading data")

# ---------------- MAIN LOOP ----------------
while True:
    try:
        # Read from Arduino
        line = arduino.readline().decode().strip()

        if "Temperature" in line:
            print("Received:", line)

            # Extract number (simple parsing)
            temp_value = ''.join(c for c in line if (c.isdigit() or c == '.' or c == '-'))

            # Publish to MQTT
            client.publish(topic, temp_value)

            print("Published to MQTT:", temp_value)

    except Exception as e:
        print("Error:", e)