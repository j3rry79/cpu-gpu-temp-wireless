
#include <WiFi.h>
#include <LiquidCrystal_I2C.h>

const char* ssid = "VIXI";              // Your Wi-Fi SSID
const char* password = "11111111";      // Your Wi-Fi Password

WiFiServer server(80);                   // Create a server that listens on port 80
LiquidCrystal_I2C lcd(0x27, 16, 2);      // Initialize the LCD (I2C address, columns, rows)

void setup() {
  Serial.begin(115200);                  // Start serial communication
  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.clear();                     
  lcd.backlight();                       

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  server.begin();                        // Start the server
  lcd.print("Server Started");
}

void loop() {
  WiFiClient client = server.available(); // Check if a client has connected
  if (client) {
    String data = "";
    while (client.connected() && !client.available()) {
      delay(1); // Wait for data
    }

    // Read the incoming data
    while (client.available()) {
      char c = client.read();
      data += c; // Append each character to the data string
    }

    // If data received, process it
    if (data.length() > 0) {
      Serial.println("Received: " + data);
      displayTemperatures(data);
    }

    client.stop(); // Close the connection
  }
}

void displayTemperatures(String data) {
  // Split the data to get CPU and GPU temps
  int commaIndex = data.indexOf(',');
  if (commaIndex > 0) {
    String cpuTemp = data.substring(0, commaIndex);
    String gpuTemp = data.substring(commaIndex + 1, data.length() - 2); // Remove '$$' at the end

    // Clear the LCD and display temperatures
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("CPU Temp: " + cpuTemp + "C");
    lcd.setCursor(0, 1);
    lcd.print("GPU Temp: " + gpuTemp + "C");
  }
}
