#include <Bridge.h>
#include <YunServer.h>
#include <YunClient.h>

#define PORT 6666
YunServer server(PORT); 
//need to know the internal ip of Yun
int button=13;
int val=-1;
String push_flag="0";
void setup(){
  Serial.begin(9600);
  Bridge.begin();
  server.noListenOnLocalhost();
  server.begin();
  Serial.println("Setup end");
  pinMode(button,INPUT);
}

void loop(){
  //If the button is pressed, val will be set to 1
  YunClient client = server.accept();
  if(client){  //When a client request to Yun, send the val to the client and set val to 0
    Serial.println("connected");
    String response="{\"push\":"+push_flag+"}";
    push_flag="0";
    client.print(response);
    client.stop();
  }
  val=digitalRead(button);  //push->1   no push->0
  while(val){     //button was pushing in
    val=digitalRead(button);val=digitalRead(button);
    if(val==0){
      push_flag="1";
      break;
    }
  }
}

