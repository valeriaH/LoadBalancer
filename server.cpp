#include<string>

#include "server.h"
#include "request.h"
#include "load_balancer.h"
#include "request_queue.h"
using namespace std;

server::server(std::string name)
{
    server_ID = name;
}

std::string server::handle_request(request r) 
{
    return "";
}
