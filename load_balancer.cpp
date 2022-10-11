#include <ostream>
#include <iostream>
#include <vector> 
#include <chrono>
#include <ctime>


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
        free_webservers.push(new_server);
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
        cout << "New Request from " << new_request.IP_in << " to " << new_request.IP_out << " in time " << new_request.request_time << endl;
        r.insert_request(new_request);
    }

    cout << "Request queue has been populated with " << to_string(initial_requests) << " requests." << endl;
    return r;
}

void load_balancer::assign_request()
{
        server current_server = free_webservers.front();
        free_webservers.pop();

        request current_request = requests.pop_request();

        int current_timestamp = clock;
        current_server.handle_request(current_request, current_timestamp);
}

void load_balancer::server_sweep()
{
    int request_time;
    int request_duration;

    for(int i = 0; i < num_servers; i++) 
    {
        //Check if the server is done with a request
        server current_server = webservers[i];

        request_time = current_server.current_request.request_time;
        request_duration = clock - current_server.current_wait;

        if(request_duration >= request_time)
        {
            //this means the server is done with the request
            handled_requests.push_back(current_server.current_request);

            std::string handled_time = to_string(request_duration);
            handled_times.push_back(handled_time);

            free_webservers.push(current_server);
        }
    }
}

void load_balancer::initialize()
{
    //First, start up the webservers
    webservers = start_webservers();

    //Now, we can fill up the request queue
    requests = populate_requests();
}

void load_balancer::run() 
{
    clock = 0;

    while(clock < runtime && !requests.is_empty()) {
        clock += 1;

        if(!requests.is_empty() && free_webservers.empty()) 
            server_sweep();

        while(!free_webservers.empty() && !requests.is_empty())
            assign_request();
    }
}