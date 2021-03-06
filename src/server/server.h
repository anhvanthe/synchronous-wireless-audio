
#ifndef SERVER_H
#define SERVER_H

#include "../common/common.h"
#include "list.h"

#define MUS_PATH "../../sound_files/goat.wav"
#define IP_ADDRESS_BUFFER_SIZE 20

typedef enum server_status_code{
    SUCCESS = 0,
    LOAD_SONG_ERROR = 1,
    SERVER_START_ERROR = 2,
    OPEN_SOCKET_ERROR = 3,
    CANNOT_FIND_RPI_ERROR = 4,
    CONNECTION_ERROR = 5,
    TIMEOUT_ERROR = 6,
    DEVICE_ALREADY_CONNECTED = 7,
    DEVICE_NOT_CONNECTED = 8,
    NO_CONNECTED_DEVICES = 9,
    NO_PACKETS = 10,
}server_status_code_t;

typedef struct device{
    char ip_address[IP_ADDRESS_BUFFER_SIZE];
    int sockfd;
    sockaddr_in serv_addr;
} device_t;

// this initializes the server c code.
// this will start a thread in an infinate while loop and check for status changes and play songs.
server_status_code_t start();

// this will set change the song to be played.
server_status_code_t set_song(char* filepath);

// TODO: change this to add device.
server_status_code_t set_device(char* ip_address, uint32_t num);
server_status_code_t kill_device(char* ip_address, uint32_t num);

// TODO: change name of play to play_audio, or think of better names for these that dont conflict
server_status_code_t play();
server_status_code_t pause_audio();
// TODO: change name of stop to stop_audio
server_status_code_t stop();


#endif
