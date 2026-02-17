# simple-chat

Basic chat server/client that I wrote in ~10 mins while learning sockets.

## Features
- (pretty) clean code
- Commands support (`/time`, `/server`, `/help`, `/exit`)
- (possible) future updates

## Compiling (on Linux)

### Using g++
`g++ -std=c++17 -o server server.cpp <br>
g++ -std=c++17 -o client client.cpp`

### Using make
```bash
make
