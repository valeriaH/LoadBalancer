#include <string>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <thread>

#include "server.h"
#include "request.h"
#include "request_queue.h"
#include "load_balancer.h"

using namespace std;

//Request Constructor
request::request()
{
    IP_in = generate_IP();
    IP_out = generate_IP();

    request_time = generate_time();
}

std::string request::generate_IP()
{
    //generate random IP address
    std::string new_address = "";
    int address_octects [4]= {0,0,0,0};

    int random_seed = (rand() % 1000);
    srand(random_seed);
    //std::this_thread::sleep_for(std::chrono::milliseconds(500));

    int offset = 0;
    int range = 256;

    for(int i = 0; i < 4; i++) 
    {

        if(i == 0) 
        {
            //For the first octect, range is 1-126
            offset = 1;
            range = 127;
        } else if (i == 3) 
        {
            //For the last octect, range is 1 - 254
            offset = 1;
            range = 255;
        }

        address_octects[i] = offset + (rand() % range);
        new_address += to_string(address_octects[i]);

        if(i != 3) 
        {
            new_address += ".";
        }
    }

    return new_address;
}

int request::generate_time() 
{
    //generate random time
    int random_seed = (rand() % 1000);
    srand(random_seed);

    int time_limit = 3;
    int t = rand() % 3;

    return t;
}