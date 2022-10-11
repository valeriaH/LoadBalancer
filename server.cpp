#include<string>
#include <chrono>
#include "server.h"
#include "request.h"
#include "load_balancer.h"
#include "request_queue.h"
using namespace std;

server::server(std::string name) :
    server_ID(name)
{}

void server::handle_request(request r,  int timestamp) 
{
    current_request = r;
    current_wait = timestamp;
}
