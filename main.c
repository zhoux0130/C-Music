#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_LEN(array) sizeof(array) / sizeof(array[0])
struct LYRIC {
    int time;
    char *text;
};

struct SONG {
    int id;
    char *name;
    char *singer;
    char *url;
    int duration;
    struct LYRIC lyric[200];
};

struct SONG songList[5] = {
        {1, "盗将行",  "花粥",    "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/盗将行.mp3", 198},
        {2, "光年之外", "邓紫棋",   "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/光年之外.mp3", 235},
        {3, "年少有为", "李荣浩",   "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/年少有为.mp3", 279},
        {4, "水星记",  "郭顶",    "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/水星记.mp3",  325},
        {5, "沙漠骆驼", "展展与罗罗", "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/沙漠骆驼.mp3", 338, {{0, "什么鬼魅传说"},{20, "什么魑魅魍魉妖魔"}}}
};

void play(){
    printf("请输入歌曲序号:");
    int id;
    scanf("%d", &id);
    struct SONG song = songList[id - 1];
    char command[100];
    strcpy(command, "open ");
    strcat(command, song.url);
    system(command);
    printf("播放音乐 %s\n", song.name);
}

void show(){
    for (int i = 0; i < ARRAY_LEN(songList); ++i) {
        struct SONG song = songList[i];
        printf("[%d, %s, %s, %s, %d] \n",
               song.id,
               song.name,
               song.singer,
               song.url,
               song.duration);

        for (int j = 0; j < ARRAY_LEN(song.lyric); ++j) {
            struct LYRIC lyric = song.lyric[j];
            if(lyric.text != NULL){
                printf("%d: %s\n", lyric.time, lyric.text);
            }
        }
    }
}

int main() {
    printf("欢迎来带命令行Music！\n"
           "请输入你的操作(show|play|end)：");
    char opt[10];
    scanf("%s", opt);
    while(strcmp(opt, "end") != 0) {
        if (strcmp(opt, "show") == 0) {
            show();
        } else if (strcmp(opt, "play") == 0) {
            play();
        }
        printf("\n\n请输入你的操作(show|play|end)：");
        scanf("%s", opt);
    }
    printf("操作结束");
}