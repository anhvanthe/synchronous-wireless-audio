
#include "../common/common.h"
#include "list.h"

#define MUS_PATH "../../sound_files/goat.wav"

typedef enum server_status_code{
    SUCCESS = 0,
    LOAD_SONG_ERROR,
    SERVER_START_ERROR,
    OPEN_SOCKET_ERROR,
    CANNOT_FIND_RPI_ERROR,
    CONNECTION_ERROR,
    TIMEOUT_ERROR,
}server_status_code_t;

typedef struct device{
    int sockfd;
    sockaddr_in serv_addr;
} device_t;

// this initializes the server c code.
// this will start a thread in an infinate while loop and check for status changes and play songs.
server_status_code_t start();

// this will set change the song to be played.
server_status_code_t set_song(char* filepath);

server_status_code_t set_device(char* ip_addresses);

server_status_code_t play();
server_status_code_t stop();

