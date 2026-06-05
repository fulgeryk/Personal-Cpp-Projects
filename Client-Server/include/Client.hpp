#include "ClientIf.hpp"
#include "Socket.hpp"

class Client : public ClientIf{
public:
    Client();
    void start() override;
    void stop() override;
    ~Client() override;
private:
    Socket clientSocket_;
    const char* ip_{"192.168.1.134"};
    uint16_t port_{5050};
    bool running_{false};
    std::thread receiveThread_;
    void connectToServer();
    void receiveMessages();
    void sendMessages();
};