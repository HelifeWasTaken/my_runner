#include <lodeus/stdlib.h>
#include <lodeus/stdio.h>
#include <lodeus/json_parser/json.h>

int main(void)
{
    json_t *config = jsonparser("bonus/config.json");

    lprintf("%s\n", SEEK_STR(config, "textures.test"));
    lprintf("%d\n", SEEK_INT(config, "sprites.1.position.x"));
    return (0);
}
