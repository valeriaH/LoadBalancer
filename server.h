#ifndef SERVER_H
#define SERVER_H

/**
 * @brief Server object:
 *      Takes requests from load balancer
 *      Process the requests
 *      Asks for another     
 */

#include<string>
#include <chrono>
#include "request.h"

class server
{

public:
    server(std::string name);

    std::string server_ID;
    request current_request;
    int current_wait;


    void handle_request(request r, int timestamp);

};

#endif // SERVER_H