#include <string>

#include "server.h"
#include "request.h"
#include "request_queue.h"
#include "load_balancer.h"

using namespace std;

//Request Constructor
request::request()
{
    IP_in = generate_IP();
    IP_out = generate_IP();

    request_time = generate_time();
}

std::string request::generate_IP()
{
    //generate random IP address
    return "";
}

int request::generate_time() 
{
    //generate random time
    return 0;
}