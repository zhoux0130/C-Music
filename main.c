#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ARRAY_LEN(array) (sizeof(array)/sizeof(array[0]))

// 歌曲
struct SONG {
    int id;
    char *name;
    char *singer;
    char *url;
    int duration;
};

struct SONG songList[5] = {
        {1, "盗将行", "花粥", "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/盗将行.mp3", 198},
        {2, "光年之外", "邓紫棋", "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/光年之外.mp3", 235},
        {3, "年少有为", "李荣浩", "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/年少有为.mp3", 279},
        {4, "水星记", "郭顶", "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/水星记.mp3", 325},
        {5, "沙漠骆驼", "展展与罗罗", "/Users/zhoufan/CLionProjects/memoryAndStruct/mp3/沙漠骆驼.mp3", 338}
};

void show(){
    for (int i = 0; i < ARRAY_LEN(songList); ++i) {
        struct SONG song = songList[i];
        printf("[%d, %s, %s, %s, %d]\n", song.id, song.name, song.singer, song.url, song.duration);
    }
}

void play(){
    int index;
    printf("请输入歌曲序号：");
    scanf("%d", &index);
    if(index < 0 || index > ARRAY_LEN(songList)){
        printf("无效的序号");
        return;
    }
    char command[110];
    strcpy(command, "open ");
    strcat(command, songList[index - 1].url);
    system(command);
    printf("开始播放：%s", songList[index - 1].name);
}

int main() {
    char opt[10];
    printf("请输入你的操作(show|play|end)：");
    scanf("%s", opt);
    while(strcmp(opt, "end") != 0)
    {
        if(strcmp(opt, "show") == 0) {
            show();
        }else if(strcmp(opt, "play") == 0){
            play();
        }
        printf("\n\n请输入你的操作(show|play|end)：");
        scanf("%s", opt);
    }
    printf("操作结束");
    return 0;
}