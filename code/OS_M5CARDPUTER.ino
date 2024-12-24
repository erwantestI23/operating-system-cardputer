#include <Adafruit_NeoPixel.h>
#include "M5Cardputer.h"
#include <WiFi.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include "image.h"
#include "EEPROM.h"
#include "esp_task_wdt.h"
#include "update.h"
int lux = 255;
int logi = 0;
int timer = 0;
int selecting = 0;
int selecta = 0;
int wallpaperno = 0;
const int epd_bitmap_bsodallArray_LEN = 7;
const uint16_t* epd_bitmap_bsodallArray[7] = {
  epd_bitmap_bsodframe_0_delay_0,
  epd_bitmap_bsodframe_1_delay_0,
  epd_bitmap_bsodframe_2_delay_0,
  epd_bitmap_bsodframe_3_delay_0,
  epd_bitmap_bsodframe_4_delay_2,
  epd_bitmap_bsodframe_5_delay_2,
  epd_bitmap_bsodframe_6_delay_2
};

Adafruit_NeoPixel led(10, 21, NEO_GRB + NEO_KHZ800);
WiFiUDP ntpUDP;// NTP (Network Time Protocol)
NTPClient timeClient(ntpUDP, "pool.ntp.org", 3600); // UTC+1 (ajustez selon votre fuseau)
//task1
volatile int connectedtowifi = 0;
void WiFiTask(void *pvParameters) {
  while (true) {
    if (WiFi.status() != WL_CONNECTED) {
      connectedtowifi = 0;
      WiFi.begin();
      Serial.println("Connexion au Wi-Fi...");

      int retryCount = 0;
      while (WiFi.status() != WL_CONNECTED && retryCount < 20) {
        vTaskDelay(500 / portTICK_PERIOD_MS);
        retryCount++;
      }

      if (WiFi.status() == WL_CONNECTED) {
        connectedtowifi = 1;
        Serial.println("Wi-Fi connecté !");
      } else {
        Serial.println("Échec de la connexion Wi-Fi...");
      }
    }
    esp_task_wdt_reset(); // Réinitialiser le watchdog
    vTaskDelay(5000 / portTICK_PERIOD_MS);
  }
}


void setup() {
esp_task_wdt_init(30000, true); // Initialiser le watchdog avec un timeout de 10 secondes 
esp_task_wdt_add(NULL); // Ajouter la tâche principale au watchdog  setupaudio();
  auto cfg = M5.config();
  M5Cardputer.begin(cfg, true);
  led.begin();
  WiFi.begin();
  EEPROM.begin(64);
  Serial.begin(115200);
  xTaskCreatePinnedToCore(
    WiFiTask,          // Fonction de la tâche
    "WiFiTask",        // Nom de la tâche
    2048,              // Taille de la pile
    NULL,              // Paramètre passé à la tâche
    1,                 // Priorité de la tâche
    NULL,              // Handle de la tâche (non utilisé ici)
    1                  // Exécuter sur le Core 1
  );
xTaskCreatePinnedToCore(
    updateTask,          // Fonction de la tâche
    "updateTask",        // Nom de la tâche
    4096,              // Taille de la pile
    NULL,              // Paramètre passé à la tâche
    1,                 // Priorité de la tâche
    NULL,              // Handle de la tâche (non utilisé ici)
    1                  // Exécuter sur le Core 1
  );

#include "bootloader.h"

}
void code() {
  M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper1);
  #define imagetoshow epd_bitmap_wallpaperlogo1
  displayImageWithTransparency(40, 40);
  Serial.println("code");
  while(true) {//loopcode
    M5Cardputer.update();
    if (M5Cardputer.Keyboard.isChange()) {
      Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();
      if (status.enter) {
        if(selecta == 2) {
          /////////////////////////////////////////////////////////////////////virus/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
EEPROM.write(0, 240); // Écrit une valeur à l'adresse spécifiée
EEPROM.commit();
M5.Lcd.invertDisplay(true); // Active l'inversion des couleurs
    vTaskDelay(1500 / portTICK_PERIOD_MS);
M5.Lcd.invertDisplay(false); // Active l'inversion des couleurs
    vTaskDelay(1500 / portTICK_PERIOD_MS);
M5.Lcd.invertDisplay(true); // Active l'inversion des couleurs
    vTaskDelay(1500 / portTICK_PERIOD_MS);
M5.Lcd.invertDisplay(false); // Active l'inversion des couleurs
    vTaskDelay(1500 / portTICK_PERIOD_MS);
   for (int i = 0; i < 25; i++) {
    int yline = random(1, 240); // Position verticale aléatoire
    uint16_t color = M5.Lcd.color565(random(0, 256), random(0, 256), random(0, 256)); // Couleur aléatoire
    M5.Lcd.drawLine(0, yline, 240, yline, color); // Dessine une ligne horizontale
        vTaskDelay(random(1, 300) / portTICK_PERIOD_MS); // Délai aléatoire
  }
  M5.Lcd.invertDisplay(true); // Active l'inversion des couleurs
  for (int i = 0; i < 600; i++) {
    int yline = random(1, 240); // Position verticale aléatoire
    uint16_t color = M5.Lcd.color565(random(0, 256), random(0, 256), random(0, 256)); // Couleur aléatoire
    M5.Lcd.drawLine(0, yline, 240, yline, color); // Dessine une ligne horizontale
   vTaskDelay(random(1, 15) / portTICK_PERIOD_MS); // Délai aléatoire
  }
    M5.Lcd.invertDisplay(false); // Active l'inversion des couleurs
  for (int i = 0; i < 25; i++) {
    int yline = random(1, 240); // Position verticale aléatoire
    uint16_t color = M5.Lcd.color565(random(0, 256), random(0, 256), random(0, 256)); // Couleur aléatoire
    M5.Lcd.drawLine(0, yline, 240, yline, color); // Dessine une ligne horizontale
    vTaskDelay(random(1, 300) / portTICK_PERIOD_MS); // Délai aléatoire
    vTaskDelay(1000 / portTICK_PERIOD_MS);
M5.Lcd.fillScreen(0x1395);
      for (int frame = 0; frame < epd_bitmap_bsodallArray_LEN; frame++) {
         vTaskDelay(random(1000, 1400) / portTICK_PERIOD_MS); 
        M5.Lcd.drawBitmap(26, 0, 177, 135, epd_bitmap_bsodallArray[frame]);
    }
M5.Lcd.setBrightness(0);
ESP.restart();

  }
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        }
        if(selecta == 1) {
          if(wallpaperno == 1) {
          M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper2);
            wallpaperno = 0;
          }else{
           M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper1);
            wallpaperno++;
          }
         if (wallpaperno > 1) {
           wallpaperno == 0;
              M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper1);
         }else{
              M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper2);
         }
        }
          if(wallpaperno == 0) {
    M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper1);
  }
    if(wallpaperno == 1) {
    M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper2);
  }
  Serial.println(wallpaperno);
      }
        if (M5Cardputer.Keyboard.isKeyPressed('.')) {
          if(selecta > 2) {
          selecta = 0;
          }else{
          selecta++;

          }
    }
       if (M5Cardputer.Keyboard.isKeyPressed(';')) {
          if(selecta < 1) {
          selecta = 3;
          }else{
          selecta--;

          }
    }
          if (M5Cardputer.Keyboard.isKeyPressed('/')) {
          if(lux > 250) {
            lux = 255;
          }else{
           lux = lux + 5;
Serial.println(lux);
            M5.Lcd.setBrightness(lux);
          }
    }
              if (M5Cardputer.Keyboard.isKeyPressed(',')) {
          if(lux < 5) {
            lux = 0;
          }else{
          lux = lux - 5;
          Serial.println(lux);

            M5.Lcd.setBrightness(lux);
          }
    }
            if (M5Cardputer.Keyboard.isKeyPressed('w')) {
                      if(wallpaperno == 1) {
          M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper2);
            wallpaperno = 0;
          }else{
           M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper1);
            wallpaperno++;
          }
         if (wallpaperno > 1) {
           wallpaperno == 0;
              M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper1);
         }else{
              M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper2);
         }
            }
              Serial.println(selecta);
   if(selecta == 1) {
    selecting = 1;
      #define imagetoshow epd_bitmap_wallpaperlogo1
  displayImageWithTransparency(40, 40);
   }else{
        selecting = 0;
      #define imagetoshow epd_bitmap_wallpaperlogo1
  displayImageWithTransparency(40, 40);
   }
    if(selecta == 2) {//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////virus///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  int index = 0;
  selecting = 1;
  for (int y = 41; y < 81; y++) { 
    for (int x = 0; x < 40; x++) { 
      uint16_t color = epd_bitmap_virus[index++]; // Si le pixel est transparent (en utilisant un code spécial, ici 0xffff) 
      if (color == 0xffff) { // Ne rien faire ou ignorer ce pixel pour la transparence
        if(selecting == 1) {
       M5.Lcd.drawPixel(x, y, 0x8410);           
        }else{
        }
        } else { // Dessiner le pixel  // epd_bitmap_wallpaperlogo1
          M5.Lcd.drawPixel(x, y, color);           
      }
    }
  }

   }else{
  int index = 0;
  selecting = 0;
  for (int y = 41; y < 81; y++) { 
    for (int x = 0; x < 40; x++) { 
      uint16_t color = epd_bitmap_virus[index++]; // Si le pixel est transparent (en utilisant un code spécial, ici 0xffff) 
      if (color == 0xffff) { // Ne rien faire ou ignorer ce pixel pour la transparence
        if(selecting == 1) {
       M5.Lcd.drawPixel(x, y, 0x8410);           
        }else{
        }
        } else { // Dessiner le pixel  // epd_bitmap_wallpaperlogo1
          M5.Lcd.drawPixel(x, y, color);           
      }
    }
  }
   }
  }
  esp_task_wdt_reset(); // Réinitialiser le watchdog 
  vTaskDelay(1 / portTICK_PERIOD_MS);
}
}
void displayImageWithTransparency(int width,  int height) {
  if(wallpaperno == 0) {
    M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper1);
  }
    if(wallpaperno == 1) {
    M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wallpaper2);
  }
  int index = 0;
  for (int y = 0; y < height; y++) { 
    for (int x = 0; x < width; x++) { 
      uint16_t color = imagetoshow[index++]; // Si le pixel est transparent (en utilisant un code spécial, ici 0xffff) 
      if (color == 0x0000) { // Ne rien faire ou ignorer ce pixel pour la transparence
        if(selecting == 1) {
       M5.Lcd.drawPixel(x, y, 0x8410);           
        }else{
        }
        } else { // Dessiner le pixel  // epd_bitmap_wallpaperlogo1
          M5.Lcd.drawPixel(x, y, color);           
      }
    }
  }
}
void loop() {
  esp_task_wdt_reset(); // Réinitialiser le watchdog
//  vTaskDelay(1 / portTICK_PERIOD_MS);
  M5Cardputer.update();
  if (M5Cardputer.Keyboard.isChange()) {
    if (M5Cardputer.Keyboard.isPressed()) {
      Keyboard_Class::KeysState status = M5Cardputer.Keyboard.keysState();
      if (status.enter) {
        logi = 1;
      }
    }
  }
    vTaskDelay(1/ portTICK_PERIOD_MS);
  timer++;
  //Serial.println(timer);
  if (timer == 1000) {
    timer = 0;
  }
  if (logi == 0) {
    if (timer == 500) {
      if (connectedtowifi == 1) {
        M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_wifi);
      } else {
        M5.Lcd.drawBitmap(0, 0, 240, 135, epd_bitmap_nowifi);
      }
      if (connectedtowifi == 1) {
        timeClient.update();
        String formattedTime = timeClient.getFormattedTime();
        int textWidth = M5.Lcd.textWidth(formattedTime);
        int textX = (M5.Lcd.width() - textWidth) / 2;
        int textY = M5.Lcd.height() / 3.5;
        M5.Lcd.setTextSize(0.8);
        M5.Lcd.setTextColor(TFT_WHITE);
        M5.Lcd.setTextFont(&fonts::Orbitron_Light_32);
        M5.Lcd.setCursor(textX, textY);
        M5.Lcd.print(formattedTime);
      } else {
        //nowifi
      }
    }
  } else {
    code();
    //if key are pressed
  }
}
