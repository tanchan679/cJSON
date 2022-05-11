#include <cJson.h>
#include <cJson.c>
#include <stdio.h>
#include <assert.h>

int main()
{
	char * json = "{\"name\": \"dungnt98\", \"age\": 24, \"test_array\":[0, 1, 1998, 2000,1545,1548,4545]}";
	
	/* parse */
	cJSON *json_obj = cJSON_Parse(json);
	if (json_obj == NULL) {
		printf("parse json error\n");
		return -1;
	}
	
	/* get data */
	const cJSON *json_age = cJSON_GetObjectItem(json_obj, "age");
	unsigned int age = json_age->valueint;
	printf("%d\n", age);
	
	const cJSON *json_name = cJSON_GetObjectItem(json_obj, "name");
	char *name = json_name->valuestring;
	printf("%s\n", name);
	
	
	const cJSON *json_test_array = cJSON_GetObjectItem(json_obj, "test_array");
	const cJSON *resolution = NULL;
    cJSON_ArrayForEach(resolution ,json_test_array)
    {
        unsigned int array_item = resolution->valueint;
        printf("%d\n", array_item);
    }
	
	
	/* free */
  	cJSON_Delete(json_obj);
}
