#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>

struct ChatMessage {
    char role[16], content[256]; 
};

int main(){
    struct ChatMessage conversation[] = {{"user","olá"}, {"system","olá"}}; 

    cJSON *data = cJSON_CreateObject();

    cJSON *model = cJSON_CreateString("gpt-3.5-turbo");
    cJSON_AddItemToObject(data, "model", model);

    cJSON *messages = cJSON_CreateArray();
    cJSON_AddItemToObject(data, "messages", messages);

    for(int i = 0; i < sizeof(conversation)/sizeof(struct ChatMessage); i++){
	cJSON *message = cJSON_CreateObject();
	cJSON_AddItemToArray(messages, message);
	cJSON *role = cJSON_CreateString(conversation[i].role);
	cJSON_AddItemToObject(message, "role",  role);
	cJSON *content = cJSON_CreateString(conversation[i].content);
	cJSON_AddItemToObject(message, "content",  content);
    }
    
    printf("%s\n", cJSON_Print(data));
}
