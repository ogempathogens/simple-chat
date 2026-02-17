# simple-chat

Basic chat server/client that I wrote in ~10 mins while learning sockets.

## Example
<img width="1920" height="1048" alt="2026-02-17_23-28" src="https://github.com/user-attachments/assets/bb902748-1dc1-4818-85b3-1cfdac6a41da" />

## Features
- (pretty) clean code
- commands support (`/time`, `/server`, `/help`, `/exit`)
- (possible) future updates

## Compiling (on Linux)

### Using g++
```bash
g++ -std=c++17 -o server server.cpp
g++ -std=c++17 -o client client.cpp
```

### Using make
```bash
make
```

