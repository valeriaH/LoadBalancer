#include <ostream>
#include <iostream>
#include <vector> 

#include "server.h"
#include "request.h"
#include "load_balancer.h"
#include "request_queue.h"

using namespace std;

load_balancer::load_balancer(int run_time, int num_servers, int initial_requests) : 
    runtime(run_time), 
    num_servers(num_servers),
    initial_requests(initial_requests)
{}

void load_balancer::initialize()
{
    //First, start up the webservers
    webservers = start_webservers();

    //Now, we can fill up the request queue
    requests = populate_requests();
}

std::vector<server> load_balancer::start_webservers()
{
    std::vector<server> webserver_list;

    cout << "New webservers created: ";
    for(int i = 0; i < num_servers; i++) 
    {
        server new_server("S" + to_string(i));
        cout << "S" << to_string(i);

        if(i != num_servers-1) 
            cout << ",";
        webserver_list.push_back(new_server);
    }
    cout << endl;
    return webserver_list;
}

request_queue load_balancer::populate_requests()
{
    request_queue r;

    for(int i = 0; i < initial_requests; i++) 
    {
        request new_request;
        cout << "New Request from " << new_request.IP_in << " to " << new_request.IP_out << endl;
        r.insert_request(new_request);
    }

    cout << "Request queue has been populated with " << to_string(initial_requests) << " requests." << endl;
    return r;
}
