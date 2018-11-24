#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct SONG {
    int id;
    char name[20];
    char singer[20];
    char url[200];
    int duration;
};

struct SONG songList[5] = {
        {1, "盗将行",  "花粥",    "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/盗将行.mp3",  198},
        {2, "光年之外", "邓紫棋",   "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/光年之外.mp3", 235},
        {3, "年少有为", "李荣浩",   "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/年少有为.mp3", 279},
        {4, "水星记",  "郭顶",    "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/水星记.mp3",  325},
        {5, "沙漠骆驼", "展展与罗罗", "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/沙漠骆驼.mp3", 338}
};

int main() {
    printf("id---------: %p\n", &songList[0].id);
    printf("name-------: %p\n", &songList[0].name);
    printf("singer-----: %p\n", &songList[0].singer);
    printf("url--------: %p\n", &songList[0].url);
    printf("duration---: %p\n", &songList[0].duration);
    printf("songList[0]: %p\n", &songList[0]);
}