#ifndef SERVER_H
#define SERVER_H

/**
 * @brief Server object:
 *      Takes requests from load balancer
 *      Process the requests
 *      Asks for another     
 */

#include<string>
#include "request.h"
class server
{

public:
    server();

    std::string server_ID;

    std::string handle_request(request r);


};

#endif // SERVER_H