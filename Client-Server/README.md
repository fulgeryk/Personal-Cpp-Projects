# TCP Chat Server (RAII + OOP)

A multi-client TCP chat application written in modern C++.

---

## Features

- TCP client-server communication
- Multi-client support
- Thread-per-client architecture
- Message broadcasting
- Client disconnect command (`/exit`)
- RAII socket management
- Move semantics support
- Smart pointers (`std::unique_ptr`)
- Exception handling
- Thread synchronization using `std::mutex`

---

## Architecture

### Socket Layer

`SocketIf` defines the socket interface.

`Socket` implements:

- Socket creation
- Send
- Receive
- Close
- RAII resource management

### Server Layer

`ServerIf` defines the server interface.

`Server` implements:

- Bind
- Listen
- Accept
- Client management
- Message broadcasting

Connected clients are stored using:

```cpp
std::vector<std::unique_ptr<Socket>>
```

### Client Layer

`ClientIf` defines the client interface.

`Client` implements:

- Connect to server
- Send messages
- Receive messages
- Graceful disconnect

---

## Commands

### Disconnect

```
/exit
```

Disconnects the client and notifies the server.

---

## Concepts Practiced

- Object Oriented Programming (OOP)
- Interfaces and Inheritance
- RAII (Resource Acquisition Is Initialization)
- Rule of Five
- Move Constructor
- Move Assignment Operator
- Smart Pointers (`std::unique_ptr`)
- Threads (`std::thread`)
- Mutexes (`std::mutex`)
- Exception Handling
- TCP Networking

---

## Project Structure

```
src/
├── SocketIf.hpp
├── Socket.hpp
├── Socket.cpp
│
├── ServerIf.hpp
├── Server.hpp
├── Server.cpp
│
├── ClientIf.hpp
├── Client.hpp
├── Client.cpp
│
├── server_main.cpp
└── client_main.cpp
```

---

## Build

```bash
cmake -B build
cmake --build build
```

---

## Run

**Server:**

```bash
./build/server
```

**Client:**

```bash
./build/client
```

---

## Example

**Client 1 sends:**

```
Message: Salutare
```

**Client 2 receives:**

```
Message from Server: Salutare
```

**Client 2 sends:**

```
Message: Respect
```

**Client 1 receives:**

```
Message from Server: Respect
```

**Disconnect:**

```
Message: /exit
```

**Server log:**

```
[INFO-Server] Client disconnected. Socket: 4
```

---

## Future Improvements

- Decorator Pattern (`LoggingSocket`, `EncryptedSocket`)
- Private messaging
- User nicknames
- Chat rooms
- Message history
- TLS/SSL encryption
- Unit testing