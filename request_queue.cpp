#include "server.h"
#include "request.h"
#include "request_queue.h"
#include "load_balancer.h"
using namespace std;

request_queue::request_queue()
{

}

void request_queue::insert_request(request r)
{

}

request request_queue::pop_request() 
{
    request r;

    return r;
}

bool request_queue::is_empty()
{
    return false;
}
