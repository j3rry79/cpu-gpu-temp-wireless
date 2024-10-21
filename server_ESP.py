import wmi
import socket
import time

print("==== Server Started ====")

# Get hardware data
def get_temperatures():
    hw_info = wmi.WMI(namespace="root\\OpenHardwareMonitor")
    temperature_info = hw_info.Sensor()
    
    cpu_temp = None
    gpu_temp = None
    
    # Look for CPU and GPU temperature sensors
    for sensor in temperature_info:
        if sensor.SensorType == "Temperature":
            if "CPU" in sensor.Name:  # Sensor.Name contains CPU
                cpu_temp = sensor.Value
            if "GPU" in sensor.Name:  # Sensor.Name contains GPU
                gpu_temp = sensor.Value

    return cpu_temp, gpu_temp

# Function to send data to ESP32
def send_data_to_esp(cpu_temp, gpu_temp):
    host = "192.168.0.115"  # Replace with your ESP's IP address
    port = 80  # Same port used in the ESP code

    # Formatting the message correctly
    message = f"{cpu_temp:.2f},{gpu_temp:.2f}$$"  # Ensuring two decimal places

    try:
        client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        client_socket.connect((host, port))
        client_socket.sendall(message.encode())
        print(f"Data sent to ESP: {message}")
        client_socket.close()
    except Exception as e:
        print(f"Failed to send data: {e}")

# Main loop
while True:
    cpu_temp, gpu_temp = get_temperatures()
    if cpu_temp is not None and gpu_temp is not None:
        send_data_to_esp(cpu_temp, gpu_temp)
        print(f"Sent CPU Temp: {cpu_temp:.2f}, GPU Temp: {gpu_temp:.2f}")
    time.sleep(2)  # Send data every 3 seconds
