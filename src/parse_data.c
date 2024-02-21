#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>

int main(){
    char buffer[1024];
    FILE* file = fopen("./response.txt", "r"); 
    fread(buffer, 1, 1024, file);
    cJSON *response = cJSON_Parse(buffer);
    if(response != NULL){
	cJSON *choices = cJSON_GetObjectItem(response, "choices");
	if(choices != NULL){
	    cJSON *item = cJSON_GetArrayItem(choices, 0);
	    if(item != NULL){
		cJSON* message = cJSON_GetObjectItem(item, "message");
		if(message != NULL){
		    cJSON *role = cJSON_GetObjectItem(message, "role");
		    cJSON *content = cJSON_GetObjectItem(message, "content");
		    if(role != NULL && content != NULL){
			printf("%s\n%s\n", role->valuestring, content->valuestring);
		    }
		}
	    }
	}
    } else {
	const char *error_ptr = cJSON_GetErrorPtr();
	if(error_ptr != NULL){
	    fprintf(stderr, "Error before of: %s\n", error_ptr);
	}
    }
    fclose(file);
    return 0;
}
