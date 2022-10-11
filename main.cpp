#include<iostream>
#include <string>

#include "server.h"
#include "request_queue.h"
#include "request.h"
#include "load_balancer.h"

using namespace std;


int main() 
{
    string user_input;
    int num_servers;
    int runtime;
    int initial_requests = 3;

    cout << "Please enter the number of servers: ";
    getline(cin, user_input);
    num_servers = stoi(user_input);

    cout << "Please enter the amount of time you would like to run the load balancer: ";
    getline(cin, user_input);
    runtime = stoi(user_input);

    //start the load balancer
    cout << "Starting load balancer..." << endl;
    load_balancer loadbalancer(runtime, num_servers, initial_requests);
    loadbalancer.initialize();
    loadbalancer.run();

    //Once the load balancer stops running, it means that time is up or queue is empty
    cout << "Done" << endl;
    for(int i = 0; i < loadbalancer.handled_requests.size(); i++)
    {
        cout << "At " << loadbalancer.handled_times[i] << " " 
            << loadbalancer.handled_servers[i].server_ID << " processed request from " 
            << loadbalancer.handled_requests[i].IP_in << " to " << 
            loadbalancer.handled_requests[i].IP_out << endl;
    }

    return 0;
}
