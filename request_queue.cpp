#include <queue>

#include "server.h"
#include "request.h"
#include "request_queue.h"
#include "load_balancer.h"
using namespace std;

request_queue::request_queue()
{}

void request_queue::insert_request(request r)
{
    requests.push(r);
}

request request_queue::pop_request() 
{
    request r = requests.front();
    requests.pop();
    
    return r;
}

bool request_queue::is_empty()
{
    bool empty = requests.empty();
    return empty;
}
