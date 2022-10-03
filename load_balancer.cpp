#include <ostream>
#include <iostream>
#include "server.h"
#include "request.h"
#include "load_balancer.h"
#include "request_queue.h"

using namespace std;

load_balancer::load_balancer(int run_time, int num_servers) : 
    runtime(run_time), 
    num_servers(num_servers)
{
    //Now, the load balancer needs to first start up the new webservers
    webservers = start_webservers();
}

std::vector<server> load_balancer::start_webservers()
{
    std::vector<server> webserver_list;

    cout << "New webservers created: ";
    for(int i = 0; i < num_servers; i++) 
    {
        server new_server("S" + to_string(i));
        cout << "S" << to_string(i) << ", ";
        webserver_list.push_back(new_server);
    }
    cout << endl;
    return webserver_list;
}
