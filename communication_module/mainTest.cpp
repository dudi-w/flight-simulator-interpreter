#include "includes/simulatorServer.hpp"
#include "includes/netClient.hpp"
#include "gtest/gtest.h"

class ServerClientTest : public ::testing::Test {
protected:
    virtual void SetUp(){port = 1234;
                        server.initialize(port);}
    fp::env::SimulatorServer server;
    net::TelnetetClient client;
    uint16_t port;
};

TEST_F(ServerClientTest, Initialization) {
    net::TelnetetClient client;
    client.initialize("127.0.0.1",port);
    std::string message = "1234";
    client.send(message);
    ASSERT_EQ(message+"\r\n", server.receive());
    server.send(message);
    ASSERT_EQ(message, client.receive());
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
