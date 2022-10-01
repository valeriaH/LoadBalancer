#include <string>

#include "server.h"
#include "request.h"
#include "request_queue.h"
#include "load_balancer.h"

using namespace std;

//Request Constructor
request::request()
{
    generate_request(&IP_in, &IP_out, &request_time);
}

void request::generate_request(string &IP_in, string &IP_out, int &request_time)
{
    //generate request with random IPs and time
    IP_in = generate_IP();
    IP_out = generate_IP();

    
}

std::string generate_IP()
{
    //generate random IP address
    return ""
}