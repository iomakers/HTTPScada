/**
 * Exemplo de GET ao Scada
 *
 *
 *
 * autor: João Campos
 * Referencias
 * http://forum.scadabr.com.br/t/arduino-e-esp8266-estacao-meteorologia-com-cliente-http/1028/10
 * https://techtutorialsx.com/2017/11/18/esp32-arduino-https-get-request/
 *
 */


 #include <WiFi.h>
 #include <HTTPClient.h>


const char* ssid = "ScadaBR";
const char* password = "ScadaBRunp";
//
// caminho do ScadaBR
String  ScadaBRpath = "http://192.168.0.13:8050/ScadaBR/httpds?__device=esp32";

void setup() {

  Serial.begin(115200);
  delay(1000);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Ligando à rede wifi");
  }

  Serial.println("Conectado à rede");
}

void loop(){

  if ((WiFi.status() == WL_CONNECTED)) { //Ver se Esp está conectado à rede

      HTTPClient http;
      // dado a ser transmitido
      float dado = 10;
      String dadoString = String(dado);
      String requisicao =  ScadaBRpath + "&dado=" + dadoString;
      Serial.println(requisicao);
      http.begin(requisicao);
      int httpCode = http.GET(); // realizar requisição

      if (httpCode > 0) {

          String payload = http.getString();
          Serial.println(httpCode); // Código tem de ser 200 para confirmar
          Serial.println(payload);
        }

      else {
        Serial.println("Erro na requisicao, verificar ScadaBR");
      }

      http.end(); //Free the resources
    }

    delay(2000);




}
