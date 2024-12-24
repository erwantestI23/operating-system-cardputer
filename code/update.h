#include <HTTPClient.h>
void updatemsg(int x, int y, int width, int height, const uint16_t *image) {
  int index = 0;
  for (int py = 0; py < height; py++) {
    for (int px = 0; px < width; px++) {
      uint16_t color = pgm_read_word(&image[index++]);
      if (color != 0x0000 && color != 0x2104 && color != 0x4A49 && color != 0x632C && color != 0x6B6D && color != 0x5ACB && color != 0x4208 && color != 0x18E3) { // 0x4208, 0x18e3
        M5.Lcd.drawPixel(x + px, y + py, color);
      }
    }
  }
}
int x = 240;
float a = -10.0;
const char* url = "https://raw.githubusercontent.com/erwantestI23/operating-system-cardputer/refs/heads/main/cardputer-src/version";
String currentVersion = "0.9.8"; // Version actuelle
void checkVersion() {
  int x = 240;
float a = -10.0;
  if (WiFi.status() == WL_CONNECTED) {
    HTTPClient http;
    http.begin(url);
    
    int httpCode = http.GET(); // Effectuer la requête GET
    
    if (httpCode > 0) {
      String payload = http.getString(); // Récupérer le contenu de la réponse
      payload.trim(); // Supprimer les espaces blancs autour
      
      Serial.println("Version du serveur : " + payload);
      
      if (payload != currentVersion) {
       // Serial.println("Nouvelle version détectée. Mise à jour en cours...");
        // Code pour effectuer l'action de mise à jour
        // Par exemple, télécharger un nouveau fichier, redémarrer le système, etc.
       // currentVersion = payload; // Mttre à jour la version actuelle
       for (int b = 0; b < 20; b++) {
   // M5.Lcd.fillScreen(0xCCCF); // Effacer l'écran à chaque étape
    a -= -0.5;
    x += a;
    updatemsg(x, 90, 100, 45, epd_bitmap_imgupdate); // Afficher l'image avec transparence
  vTaskDelay(15 / portTICK_PERIOD_MS);
  }
      } else {
        Serial.println("La version est à jour.");
      }
    } else {
      Serial.println("Erreur lors de la requête HTTP");
    }
    
    http.end();
  }
}
void updateTask(void *pvParameters) {
    while (true) {
  checkVersion();

  vTaskDelay(5000 / portTICK_PERIOD_MS);
  
  esp_task_wdt_reset(); // Réinitialiser le watchdog

    }
}
