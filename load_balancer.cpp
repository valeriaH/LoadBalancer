#include "server.h"
#include "request.h"
#include "load_balancer.h"
#include "request_queue.h"

using namespace std;

load_balancer::load_balancer(int run_time, int num_servers) 
{
    runtime = run_time;
    num_servers = num_servers;
}

